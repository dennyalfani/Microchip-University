/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18855
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_D2 aliases
#define LED_D2_TRIS                 TRISAbits.TRISA0
#define LED_D2_LAT                  LATAbits.LATA0
#define LED_D2_PORT                 PORTAbits.RA0
#define LED_D2_WPU                  WPUAbits.WPUA0
#define LED_D2_OD                   ODCONAbits.ODCA0
#define LED_D2_ANS                  ANSELAbits.ANSA0
#define LED_D2_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_D2_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_D2_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_D2_GetValue()           PORTAbits.RA0
#define LED_D2_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_D2_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_D2_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LED_D2_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LED_D2_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LED_D2_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LED_D2_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_D2_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_D3 aliases
#define LED_D3_TRIS                 TRISAbits.TRISA1
#define LED_D3_LAT                  LATAbits.LATA1
#define LED_D3_PORT                 PORTAbits.RA1
#define LED_D3_WPU                  WPUAbits.WPUA1
#define LED_D3_OD                   ODCONAbits.ODCA1
#define LED_D3_ANS                  ANSELAbits.ANSA1
#define LED_D3_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_D3_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_D3_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_D3_GetValue()           PORTAbits.RA1
#define LED_D3_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_D3_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_D3_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_D3_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_D3_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_D3_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_D3_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_D3_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_D4 aliases
#define LED_D4_TRIS                 TRISAbits.TRISA2
#define LED_D4_LAT                  LATAbits.LATA2
#define LED_D4_PORT                 PORTAbits.RA2
#define LED_D4_WPU                  WPUAbits.WPUA2
#define LED_D4_OD                   ODCONAbits.ODCA2
#define LED_D4_ANS                  ANSELAbits.ANSA2
#define LED_D4_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_D4_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_D4_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_D4_GetValue()           PORTAbits.RA2
#define LED_D4_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_D4_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_D4_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_D4_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_D4_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_D4_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_D4_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_D4_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED_D5 aliases
#define LED_D5_TRIS                 TRISAbits.TRISA3
#define LED_D5_LAT                  LATAbits.LATA3
#define LED_D5_PORT                 PORTAbits.RA3
#define LED_D5_WPU                  WPUAbits.WPUA3
#define LED_D5_OD                   ODCONAbits.ODCA3
#define LED_D5_ANS                  ANSELAbits.ANSA3
#define LED_D5_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED_D5_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED_D5_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED_D5_GetValue()           PORTAbits.RA3
#define LED_D5_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED_D5_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED_D5_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LED_D5_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LED_D5_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LED_D5_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LED_D5_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED_D5_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA4
#define POT_LAT                  LATAbits.LATA4
#define POT_PORT                 PORTAbits.RA4
#define POT_WPU                  WPUAbits.WPUA4
#define POT_OD                   ODCONAbits.ODCA4
#define POT_ANS                  ANSELAbits.ANSA4
#define POT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POT_GetValue()           PORTAbits.RA4
#define POT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISAbits.TRISA5
#define BUTTON_LAT                  LATAbits.LATA5
#define BUTTON_PORT                 PORTAbits.RA5
#define BUTTON_WPU                  WPUAbits.WPUA5
#define BUTTON_OD                   ODCONAbits.ODCA5
#define BUTTON_ANS                  ANSELAbits.ANSA5
#define BUTTON_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA5
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set EMC_ALARM2 aliases
#define EMC_ALARM2_TRIS                 TRISAbits.TRISA6
#define EMC_ALARM2_LAT                  LATAbits.LATA6
#define EMC_ALARM2_PORT                 PORTAbits.RA6
#define EMC_ALARM2_WPU                  WPUAbits.WPUA6
#define EMC_ALARM2_OD                   ODCONAbits.ODCA6
#define EMC_ALARM2_ANS                  ANSELAbits.ANSA6
#define EMC_ALARM2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define EMC_ALARM2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define EMC_ALARM2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define EMC_ALARM2_GetValue()           PORTAbits.RA6
#define EMC_ALARM2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define EMC_ALARM2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define EMC_ALARM2_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define EMC_ALARM2_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define EMC_ALARM2_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define EMC_ALARM2_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define EMC_ALARM2_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define EMC_ALARM2_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set EMC_ALARM1 aliases
#define EMC_ALARM1_TRIS                 TRISAbits.TRISA7
#define EMC_ALARM1_LAT                  LATAbits.LATA7
#define EMC_ALARM1_PORT                 PORTAbits.RA7
#define EMC_ALARM1_WPU                  WPUAbits.WPUA7
#define EMC_ALARM1_OD                   ODCONAbits.ODCA7
#define EMC_ALARM1_ANS                  ANSELAbits.ANSA7
#define EMC_ALARM1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define EMC_ALARM1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define EMC_ALARM1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define EMC_ALARM1_GetValue()           PORTAbits.RA7
#define EMC_ALARM1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define EMC_ALARM1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define EMC_ALARM1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define EMC_ALARM1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define EMC_ALARM1_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define EMC_ALARM1_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define EMC_ALARM1_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define EMC_ALARM1_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()               do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()                do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()                do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()       do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()      do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set MB_RST aliases
#define MB_RST_TRIS                 TRISBbits.TRISB1
#define MB_RST_LAT                  LATBbits.LATB1
#define MB_RST_PORT                 PORTBbits.RB1
#define MB_RST_WPU                  WPUBbits.WPUB1
#define MB_RST_OD                   ODCONBbits.ODCB1
#define MB_RST_ANS                  ANSELBbits.ANSB1
#define MB_RST_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MB_RST_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MB_RST_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MB_RST_GetValue()           PORTBbits.RB1
#define MB_RST_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MB_RST_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MB_RST_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MB_RST_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MB_RST_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MB_RST_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MB_RST_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define MB_RST_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set MB_CS aliases
#define MB_CS_TRIS                 TRISBbits.TRISB2
#define MB_CS_LAT                  LATBbits.LATB2
#define MB_CS_PORT                 PORTBbits.RB2
#define MB_CS_WPU                  WPUBbits.WPUB2
#define MB_CS_OD                   ODCONBbits.ODCB2
#define MB_CS_ANS                  ANSELBbits.ANSB2
#define MB_CS_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define MB_CS_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define MB_CS_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define MB_CS_GetValue()           PORTBbits.RB2
#define MB_CS_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define MB_CS_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define MB_CS_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define MB_CS_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define MB_CS_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define MB_CS_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define MB_CS_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define MB_CS_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS                 TRISBbits.TRISB3
#define SCK2_LAT                  LATBbits.LATB3
#define SCK2_PORT                 PORTBbits.RB3
#define SCK2_WPU                  WPUBbits.WPUB3
#define SCK2_OD                   ODCONBbits.ODCB3
#define SCK2_ANS                  ANSELBbits.ANSB3
#define SCK2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SCK2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SCK2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SCK2_GetValue()           PORTBbits.RB3
#define SCK2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SCK2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SCK2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SCK2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SCK2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SCK2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SCK2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set MISO aliases
#define MISO_TRIS                 TRISBbits.TRISB4
#define MISO_LAT                  LATBbits.LATB4
#define MISO_PORT                 PORTBbits.RB4
#define MISO_WPU                  WPUBbits.WPUB4
#define MISO_OD                   ODCONBbits.ODCB4
#define MISO_ANS                  ANSELBbits.ANSB4
#define MISO_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define MISO_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define MISO_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define MISO_GetValue()           PORTBbits.RB4
#define MISO_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define MISO_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define MISO_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define MISO_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define MISO_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define MISO_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define MISO_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define MISO_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set MOSI aliases
#define MOSI_TRIS                 TRISBbits.TRISB5
#define MOSI_LAT                  LATBbits.LATB5
#define MOSI_PORT                 PORTBbits.RB5
#define MOSI_WPU                  WPUBbits.WPUB5
#define MOSI_OD                   ODCONBbits.ODCB5
#define MOSI_ANS                  ANSELBbits.ANSB5
#define MOSI_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define MOSI_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define MOSI_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define MOSI_GetValue()           PORTBbits.RB5
#define MOSI_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define MOSI_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define MOSI_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define MOSI_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define MOSI_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define MOSI_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define MOSI_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define MOSI_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set F188TXU aliases
#define F188TXU_TRIS                 TRISCbits.TRISC0
#define F188TXU_LAT                  LATCbits.LATC0
#define F188TXU_PORT                 PORTCbits.RC0
#define F188TXU_WPU                  WPUCbits.WPUC0
#define F188TXU_OD                   ODCONCbits.ODCC0
#define F188TXU_ANS                  ANSELCbits.ANSC0
#define F188TXU_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define F188TXU_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define F188TXU_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define F188TXU_GetValue()           PORTCbits.RC0
#define F188TXU_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define F188TXU_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define F188TXU_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define F188TXU_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define F188TXU_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define F188TXU_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define F188TXU_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define F188TXU_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set F188RXU aliases
#define F188RXU_TRIS                 TRISCbits.TRISC1
#define F188RXU_LAT                  LATCbits.LATC1
#define F188RXU_PORT                 PORTCbits.RC1
#define F188RXU_WPU                  WPUCbits.WPUC1
#define F188RXU_OD                   ODCONCbits.ODCC1
#define F188RXU_ANS                  ANSELCbits.ANSC1
#define F188RXU_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define F188RXU_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define F188RXU_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define F188RXU_GetValue()           PORTCbits.RC1
#define F188RXU_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define F188RXU_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define F188RXU_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define F188RXU_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define F188RXU_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define F188RXU_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define F188RXU_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define F188RXU_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set UNMOD aliases
#define UNMOD_TRIS                 TRISCbits.TRISC2
#define UNMOD_LAT                  LATCbits.LATC2
#define UNMOD_PORT                 PORTCbits.RC2
#define UNMOD_WPU                  WPUCbits.WPUC2
#define UNMOD_OD                   ODCONCbits.ODCC2
#define UNMOD_ANS                  ANSELCbits.ANSC2
#define UNMOD_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define UNMOD_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define UNMOD_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define UNMOD_GetValue()           PORTCbits.RC2
#define UNMOD_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define UNMOD_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define UNMOD_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define UNMOD_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define UNMOD_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define UNMOD_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define UNMOD_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define UNMOD_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()               do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()                do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()                do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()       do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()      do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LOAD_MAIN aliases
#define LOAD_MAIN_TRIS                 TRISCbits.TRISC4
#define LOAD_MAIN_LAT                  LATCbits.LATC4
#define LOAD_MAIN_PORT                 PORTCbits.RC4
#define LOAD_MAIN_WPU                  WPUCbits.WPUC4
#define LOAD_MAIN_OD                   ODCONCbits.ODCC4
#define LOAD_MAIN_ANS                  ANSELCbits.ANSC4
#define LOAD_MAIN_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LOAD_MAIN_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LOAD_MAIN_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LOAD_MAIN_GetValue()           PORTCbits.RC4
#define LOAD_MAIN_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LOAD_MAIN_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LOAD_MAIN_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LOAD_MAIN_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LOAD_MAIN_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LOAD_MAIN_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LOAD_MAIN_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define LOAD_MAIN_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set MUX_0 aliases
#define MUX_0_TRIS                 TRISCbits.TRISC5
#define MUX_0_LAT                  LATCbits.LATC5
#define MUX_0_PORT                 PORTCbits.RC5
#define MUX_0_WPU                  WPUCbits.WPUC5
#define MUX_0_OD                   ODCONCbits.ODCC5
#define MUX_0_ANS                  ANSELCbits.ANSC5
#define MUX_0_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define MUX_0_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define MUX_0_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define MUX_0_GetValue()           PORTCbits.RC5
#define MUX_0_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define MUX_0_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define MUX_0_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define MUX_0_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define MUX_0_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define MUX_0_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define MUX_0_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define MUX_0_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set MUX_1 aliases
#define MUX_1_TRIS                 TRISCbits.TRISC6
#define MUX_1_LAT                  LATCbits.LATC6
#define MUX_1_PORT                 PORTCbits.RC6
#define MUX_1_WPU                  WPUCbits.WPUC6
#define MUX_1_OD                   ODCONCbits.ODCC6
#define MUX_1_ANS                  ANSELCbits.ANSC6
#define MUX_1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define MUX_1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define MUX_1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define MUX_1_GetValue()           PORTCbits.RC6
#define MUX_1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define MUX_1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define MUX_1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define MUX_1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define MUX_1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define MUX_1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define MUX_1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define MUX_1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LOAD_INT aliases
#define LOAD_INT_TRIS                 TRISCbits.TRISC7
#define LOAD_INT_LAT                  LATCbits.LATC7
#define LOAD_INT_PORT                 PORTCbits.RC7
#define LOAD_INT_WPU                  WPUCbits.WPUC7
#define LOAD_INT_OD                   ODCONCbits.ODCC7
#define LOAD_INT_ANS                  ANSELCbits.ANSC7
#define LOAD_INT_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LOAD_INT_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LOAD_INT_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LOAD_INT_GetValue()           PORTCbits.RC7
#define LOAD_INT_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LOAD_INT_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LOAD_INT_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LOAD_INT_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LOAD_INT_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LOAD_INT_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LOAD_INT_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LOAD_INT_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/