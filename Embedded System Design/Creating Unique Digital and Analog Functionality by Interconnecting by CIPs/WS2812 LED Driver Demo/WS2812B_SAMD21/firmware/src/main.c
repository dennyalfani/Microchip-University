/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "ws2812b.h"

extern DMA_Descriptor_TypeLocal DMA_Descriptor_WB;
extern DMA_Descriptor_TypeLocal DMA_Descriptor;
extern WS2812_TYPE ws2812;

struct timermSS {
    uint8_t interval : 1;
    uint32_t count;
    uint32_t timeOut;
} timermS;

struct LEDPaternS {
    uint8_t index;
    uint8_t color;
} LEDPattern;

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

uint32_t TC3period, TC3Counter, TC3Status;

void Interval1mS(TC_TIMER_STATUS status, uintptr_t context) {
    GPIO_STATUS_Set();
    if (++timermS.count >= timermS.timeOut) {
        timermS.interval = 1;
        timermS.count = 0;
    }
    GPIO_STATUS_Clear();
}

int main(void) {
    uint8_t i;
    /* Initialize all modules */
    SYS_Initialize(NULL);
    GPIO_STATUS_OutputEnable();
    TC4_TimerStart();
    TC4_TimerCallbackRegister(Interval1mS, (uintptr_t) NULL);
    initTimerDMA();
    timermS.timeOut = 100;
    ws2812.update = 1;
    while (true) {
        GPIO_STATUS_Set();
        ws2812_Update();
        GPIO_STATUS_Clear();

        if (timermS.interval == 1) {
            timermS.interval = 0;
            if (++LEDPattern.index >= WS2812_NUM) {
                LEDPattern.index = 0;
                if (++LEDPattern.color >= 3) {
                    LEDPattern.color = 0;
                }
            }
            for (i = 0; i < WS2812_NUM * 3; i++) {
                ws2812.color.array[i] = 0;
            }

            switch (LEDPattern.color) {
                case 0:
                {
                    ws2812.color.led[LEDPattern.index].red = 0xFF;
                }
                    break;
                case 1:
                {
                    ws2812.color.led[LEDPattern.index].green = 0xFF;
                    break;
                }
                case 2:
                {
                    ws2812.color.led[LEDPattern.index].blue = 0xFF;
                    break;
                }
            }
            ws2812.update = 1;
            //ws2812.color.array[0] = 0x81;   // force known test pattern into first position
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE);
}


/*******************************************************************************
 End of File
 */

