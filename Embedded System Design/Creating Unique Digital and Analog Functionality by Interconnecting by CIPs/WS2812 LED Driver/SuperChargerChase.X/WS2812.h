/* 
 * File:   WS2812.h
 * Author: C07445
 *
 * Created on March 13, 2020, 2:25 PM
 */

#ifndef WS2812_H
#define	WS2812_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NUM_LEDS 8
#define LEDMAXVALUE 255

void LEDSetColor(uint8_t, uint8_t, uint8_t);
void LEDSetPixel(uint8_t);
void LEDClearPixel(uint8_t);
void LEDSetColorRandom(void);
void LEDClearAll(void);
void LEDSetAll(void);
void LEDMoveRightPixel(void);
void LEDMoveLeftPixel(void);
void WS2812Update(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* WS2812_H */

