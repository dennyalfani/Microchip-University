/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18855
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "prbs.h"
#include "signal.h"
#include "set_lights.h"
#include "interface.h"
#include "timeslots.h"
#include <stdio.h>
#include <stdlib.h>

//RA0-3 LEDs
//RA4 Analog input (Poti)
//RA5 Button
//RA6, RA7 Temp Alarm inputs
//RB0 mod data
//RB1 mod clock
//RB2 CS (input)
//RB3 SCK (input)
//RB4 MISO (slave out)
//RB5 MOSI (slave in)
//RB6, RB7 ICSP
//RC0, RC1 RX+TX to programmer
//RC2 unmod. carrier
//RC3 mod. signal
//RC4 load indicator main
//RC5 mux 0
//RC6 mux 1
//RC7 load indicator int

typedef enum {
    ST_FIRST_STATE = 0,
    ST_SET_CARRIER_FREQUENCY = ST_FIRST_STATE,
    ST_SET_MODULATION_FREQUENCY,
    ST_MUX_OUTPUTS_MODULATED,
    ST_MUX_OUTPUTS_UNMODULATED,
    ST_LAST_STATE = ST_MUX_OUTPUTS_UNMODULATED
} st_system_t;

uint32_t NCO_start_freq = 1800000ul;
uint32_t NCO_stop_freq = 2200000ul;
uint32_t MOD_start_freq = _XTAL_FREQ / 800;
uint32_t MOD_stop_freq = _XTAL_FREQ / 80;


st_system_t st_system;

// RC5: delayed, modulated signal MUX0
// RC6: delayed, modulated signal MUX1
// RC7: undelayed, modulated Signal DSM
// RB4: modulation signal DT

void main(void) {
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    st_system = ST_FIRST_STATE;
    set_signal_modulation_frequency(MOD_start_freq, MOD_stop_freq, 512);

    TMR0_SetInterruptHandler(interrupt_set_timeslots);
    EUSART_SetTxInterruptHandler(interrupt_modulate_carrier_signal);
    
    while (1) {

        if (timeslot.ms_1) {
            LOAD_MAIN_SetHigh();
            timeslot.ms_1 = 0;
            if (button_pressed() == true) {
                if (st_system == ST_LAST_STATE) {
                    st_system = ST_FIRST_STATE;
                } else {
                    st_system++;
                }
            }
            LOAD_MAIN_SetLow();
        }

        if (timeslot.ms_50) {
            LOAD_MAIN_SetHigh();
            timeslot.ms_50 = 0;

            uint16_t freq_select_poti = ADCC_GetSingleConversion(POT);

            switch (st_system) {
                case ST_SET_CARRIER_FREQUENCY:
                    LED_D2_SetLow();
                    LED_D5_SetLow();
                    if(set_signal_frequency(NCO_start_freq, NCO_stop_freq, freq_select_poti)) {
                        LED_D3_Toggle();
                        LED_D4_SetHigh();
                    } else {
                        LED_D3_SetHigh();
                        LED_D4_SetHigh();
                    }
                    mux_signal(false);
                    modulate_signal(false);
                    break;
                case ST_SET_MODULATION_FREQUENCY:
                    LED_D2_SetHigh();
                    LED_D3_SetLow();
                    LED_D4_SetLow();
                    LED_D5_SetHigh();
                    set_signal_modulation_frequency(MOD_start_freq, MOD_stop_freq, freq_select_poti);
                    mux_signal(false);
                    modulate_signal(true);
                    break;
                case ST_MUX_OUTPUTS_MODULATED:
                    LED_D2_Toggle();
                    LED_D3_Toggle();
                    LED_D4_Toggle();
                    LED_D5_Toggle();
                    mux_signal(true);
                    modulate_signal(true);
                    break;
                case ST_MUX_OUTPUTS_UNMODULATED:
                    LED_D2_SetLow();
                    LED_D3_Toggle();
                    LED_D4_Toggle();
                    LED_D5_SetLow();
                    mux_signal(true);
                    modulate_signal(false);
                    break;
                default:
                    break;
            }
        }
        LOAD_MAIN_SetLow();
    }
}


/**
 End of File
 */