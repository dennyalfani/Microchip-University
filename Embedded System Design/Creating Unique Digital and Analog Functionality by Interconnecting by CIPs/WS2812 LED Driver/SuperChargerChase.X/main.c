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
#include "WS2812.h"
#include "switchScan.h"


/*
                         Main application
 */





uint16_t mScounter, mSlimit;
uint8_t direction, pixel;

#define MSLIMITMAX 200
#define MSLIMITMIN 50
#define MSLIMITDEC 10

void updateLED(void) {
    WS2812Update();
    switchScan();
    if (mScounter > 0) {
        mScounter--;
    }
}

void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(updateLED);

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
    LEDSetColor(255, 0, 0);
    mSlimit = MSLIMITMAX;
    pixel = 0;
    direction = 1;
    while (1) {
        if (switchInput[0].change == 1) {
            switchInput[0].change = 0;
            if (mSlimit > MSLIMITMIN) {
                mSlimit -= MSLIMITDEC;
            } else {
                mSlimit = MSLIMITMAX;
            }
        }
        if (mScounter == 0) {
            mScounter = mSlimit;
            if (direction == 1) {
                if (++pixel > NUM_LEDS) {
                    direction = 0;
                    LEDSetColorRandom();
                    LEDClearAll();
                } else {
                    LEDMoveRightPixel();
                    LEDSetColor(0, 0, 0);
                }
            } else {
                if (--pixel == 0) {
                    direction = 1;
                    LEDSetColorRandom();
                    LEDClearAll();
                } else {
                    LEDMoveLeftPixel();
                    LEDSetColor(0, 0, 0);
                }
            }
        }
    }
}
/**
 End of File
 */