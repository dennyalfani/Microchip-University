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


typedef struct {
    uint8_t green;
    uint8_t red;
    uint8_t blue;
} WS2812;

void WS2812Reset(void) {
    __delay_us(65);

}

WS2812 LEDArray[NUM_LEDS];
WS2812 LEDColor;
volatile uint8_t led, temp;

void LEDSetColor(uint8_t red, uint8_t green, uint8_t blue) {
    LEDColor.red = red;
    LEDColor.green = green;
    LEDColor.blue = blue;
}

void LEDSetPixel(uint8_t pixel) {
    LEDArray[pixel].red = LEDColor.red;
    LEDArray[pixel].green = LEDColor.green;
    LEDArray[pixel].blue = LEDColor.blue;
}

void LEDClearPixel(uint8_t pixel) {
    LEDArray[pixel].red = 0;
    LEDArray[pixel].green = 0;
    LEDArray[pixel].blue = 0;
}

void LEDSetColorRandom(void) {
    LEDColor.red = rand() / (RAND_MAX / LEDMAXVALUE);
    LEDColor.green = rand() / (RAND_MAX / LEDMAXVALUE);
    LEDColor.blue = rand() / (RAND_MAX / LEDMAXVALUE);
}

void LEDClearAll(void) {
    uint8_t i;
    for (i = 0; i < NUM_LEDS; i++) {
        LEDArray[i].red = 0;
        LEDArray[i].green = 0;
        LEDArray[i].blue = 0;
    }
}

void LEDSetAll(void) {
    uint8_t i;
    for (i = 0; i < NUM_LEDS; i++) {
        LEDArray[i].red = LEDColor.red;
        LEDArray[i].green = LEDColor.green;
        LEDArray[i].blue = LEDColor.blue;
    }
}

void LEDMoveRightPixel(void) {
    uint8_t i;
    for (i = NUM_LEDS - 1; i > 0; i--) {
        LEDArray[i].red = LEDArray[i-1].red;
        LEDArray[i].green = LEDArray[i-1].green;
        LEDArray[i].blue = LEDArray[i-1].blue;
    }
    LEDArray[0].red = LEDColor.red;
    LEDArray[0].green = LEDColor.green;
    LEDArray[0].blue = LEDColor.blue;
}

void LEDMoveLeftPixel(void) {
    uint8_t i;
    for (i = 0; i < NUM_LEDS-1; i++) {
        LEDArray[i].red = LEDArray[i+1].red;
        LEDArray[i].green = LEDArray[i+1].green;
        LEDArray[i].blue = LEDArray[i+1].blue;
    }
    LEDArray[NUM_LEDS-1].red = LEDColor.red;
    LEDArray[NUM_LEDS-1].green = LEDColor.green;
    LEDArray[NUM_LEDS-1].blue = LEDColor.blue;
}

void WS2812Update(void) {
    uint8_t i;
    for (i = 0; i < NUM_LEDS * 3; i++) {
        led = *(&LEDArray[0].green + i);
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        asm("RLF _led,f");
        asm("RRF _temp,f");
        EUSART1_Write(temp);
    }
    WS2812Reset();
}

