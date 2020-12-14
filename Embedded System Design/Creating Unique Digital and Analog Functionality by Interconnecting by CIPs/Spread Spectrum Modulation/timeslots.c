#include "timeslots.h"

timeslot_t timeslot;

inline void interrupt_set_timeslots(void) {
    static uint8_t count_ms_10 = 0;
    static uint8_t count_ms_50 = 0;

    timeslot.ms_1 = true;

    if (++count_ms_10 == 9) {
        count_ms_10 = 0;
        timeslot.ms_10 = true;
    }

    if (++count_ms_50 == 49) {
        count_ms_50 = 0;
        timeslot.ms_50 = true;
    }
}


