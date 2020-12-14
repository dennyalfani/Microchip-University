#include "set_lights.h"

void set_lights(uint16_t ad_value) {

    if (ad_value > 768) {
        LED_D5_SetHigh();
    } else {
        LED_D5_SetLow();
    }
    if (ad_value > 512) {
        LED_D4_SetHigh();
    } else {
        LED_D4_SetLow();
    }
    if (ad_value > 256) {
        LED_D3_SetHigh();
    } else {
        LED_D3_SetLow();
    }
    if (ad_value > 128) {
        LED_D2_SetHigh();
    } else {
        LED_D2_SetLow();
    }
}
