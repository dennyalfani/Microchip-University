/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F47K42
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0xEC;
    TRISB = 0xFF;
    TRISC = 0xBF;
    TRISD = 0xF7;

    /**
    ANSELx registers
    */
    ANSELD = 0xFF;
    ANSELC = 0x0F;
    ANSELB = 0xEF;
    ANSELE = 0x07;
    ANSELA = 0xEC;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;





   
    
	
    U1CTSPPSbits.U1CTSPPS = 0x14;   //RC4->UART1:CTS1;    
    CLCIN0PPSbits.CLCIN0PPS = 0x15;   //RC5->CLC3:CLCIN0;    
    RD3PPS = 0x03;   //RD3->CLC3:CLC3;    
    U1RXPPSbits.U1RXPPS = 0x17;   //RC7->UART1:RX1;    
    RA1PPS = 0x28;   //RA1->DSM:DSM1;    
    RC6PPS = 0x13;   //RC6->UART1:TX1;    
    RA0PPS = 0x28;   //RA0->DSM:DSM1;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/