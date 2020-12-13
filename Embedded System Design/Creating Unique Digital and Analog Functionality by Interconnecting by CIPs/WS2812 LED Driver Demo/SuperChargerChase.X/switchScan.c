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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16F15325
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
#include "switchScan.h"

bool scanInput1(void) {
    return (TRIGGER_1_GetValue());
}

bool scanInput2(void) {
    return (TRIGGER_2_GetValue());
}


SWITCHS switchInput[NUM_SWITCHES] = {
    UP, 0, 0, scanInput1,
    UP, 0, 0, scanInput2
};

void switchScan(void) {
    uint8_t i;
    SWITCHS * ptr_switch;
    for (i = 0; i < NUM_SWITCHES; i++) {
        ptr_switch = &switchInput[i];
        switch (ptr_switch->state) {
            case UP:
            {
                if (ptr_switch->Position() == 0) {
                    ptr_switch->state = UP_DEBOUNCE;
                    ptr_switch->debounce = DEBOUNCECOUNT;
                }
                break;
            }
            case UP_DEBOUNCE:
            {
                if (ptr_switch->Position() == 1) {
                    ptr_switch->state = UP;
                } else if (--ptr_switch->debounce == 0) {
                    ptr_switch->state = DOWN;
                    ptr_switch->change = 1;
                }
                break;
            }
            case DOWN:
            {
                if (ptr_switch->Position() == 1) {
                    ptr_switch->state = DOWN_DEBOUNCE;
                    ptr_switch->debounce = DEBOUNCECOUNT;
                }
                break;
            }
            case DOWN_DEBOUNCE:
            {
                if (ptr_switch->Position() == 0) {
                    ptr_switch->state = DOWN;
                } else if (--ptr_switch->debounce == 0) {
                    ptr_switch->state = UP;
                }
                break;
            }
        }
    }

}


