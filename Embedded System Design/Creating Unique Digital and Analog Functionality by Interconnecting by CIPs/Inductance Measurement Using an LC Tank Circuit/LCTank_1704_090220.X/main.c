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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F1704
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
#include "inductance.h"
/*
                         Main application
 */

extern LCFreqS LCMeas;

uint32_t freqMin, freqMax, freqDiff, freqPercent, peakMin, peakMax, peakDiff, peakPercent;

void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    ADC_SelectChannel(PEAK);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    freqMin = 0xFFFFFFFF;
    freqMax = 0;
    peakMin = 0xFFFFFFFF;
    peakMax = 0;

    printf("LC Meter Version 1.1 %s\r\n", __DATE__);

    uint8_t  i, dataVisualizer[] = {0x03, 0x00, 0x00, 0x00, 0x00, 0xFC};

    struct buttonS {
        unsigned state : 1;
        unsigned mode : 1;
    } button;

    button.mode = 0;
    button.state = 1;

    while (1) {
        if (LCMeas.sample == 1) {
            PROX_SetHigh();
            if (MCLR_TEST_GetValue() != button.state) {
                button.state ^= 1;
                if (button.state == 0) {
                    button.mode ^= 1;
                }
            }
            LCMeas.peakVoltage = ADC_GetConversionResult();
            if (freqMin > LCMeas.frequency) {
                freqMin = LCMeas.frequency;
            }
            if (freqMax < LCMeas.frequency) {
                freqMax = LCMeas.frequency;
            }
            if (peakMax < LCMeas.peakVoltage) {
                peakMax = LCMeas.peakVoltage;
            }
            if (peakMin > LCMeas.peakVoltage) {
                peakMin = LCMeas.peakVoltage;
            }
            if (MCLR_TEST_GetValue() == 0) {
                freqMin = 0xFFFFFFFF;
                freqMax = 0;
                peakMin = 0xFFFFFFFF;
                peakMax = 0;
            } else {
                freqDiff = freqMax - freqMin;
                freqPercent = ((100 * (freqMax - freqMin)) / freqMax);
                peakDiff = peakMax - peakMin;
                peakPercent = ((100 * (peakMax - peakMin)) / peakMax);
                if (button.mode == 0) {
                    printf("Peak = %u Diff = %lu %lu%%, LC = %u Freq = %lu Hz Diff = %lu %lu%%\r\n", LCMeas.peakVoltage, peakDiff, peakPercent, LCMeas.cycle, LCMeas.frequency, freqDiff, freqPercent);
                } else {
                    dataVisualizer[1] = LCMeas.peakVoltage;
                    dataVisualizer[2] = LCMeas.peakVoltage >> 8;
                    dataVisualizer[3] = LCMeas.cycle;
                    dataVisualizer[4] = LCMeas.cycle >> 8;
                    for (i = 0; i < sizeof (dataVisualizer); i++) {
                        EUSART_Write(dataVisualizer[i]);
                    }
                }
                LCMeas.sample = 0;
            }
            PROX_SetLow();
        }
    }
}

/**
 End of File
 */