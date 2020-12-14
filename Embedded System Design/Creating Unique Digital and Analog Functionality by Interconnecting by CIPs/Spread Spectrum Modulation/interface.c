#include "interface.h"

bool button_pressed(void) {
    static bool button_pressed = false;
    static bool last_state = false;
    static bool result = false;
    static uint8_t button_debouncer = 0;

    if (button_pressed == true) {
        if (button_debouncer < 20) {
            if (BUTTON_GetValue() == 0) {
                button_debouncer = 0;
            } else {
                button_debouncer++;
            }
        } 
        if (button_debouncer == 20) {
            button_pressed = false;
            button_debouncer = 0;
        }
        
    } else {
        
        if (button_debouncer < 20) {
            if (BUTTON_GetValue() == 1) {
                button_debouncer = 0;
            } else {
                button_debouncer++;
            }
        } 
        if (button_debouncer == 20) {
            button_pressed = true;
            button_debouncer = 0;
        }
    }

    if(last_state == false && button_pressed == true) {
        result = true;
    } else {
        result = false;
    }
    
    last_state = button_pressed;
    
    return result;
}