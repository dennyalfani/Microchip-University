#include "signal.h"

static const uint32_t system_clock = _XTAL_FREQ;
static const uint32_t NCO_overflow_value = 1048576ul;

static uint32_t calculate_frequency(uint32_t start_freq, uint32_t stop_freq, uint32_t ad_value);

static uint32_t calculate_frequency(uint32_t start_freq, uint32_t stop_freq, uint32_t ad_value) {
    uint32_t freq_step, freq_select;

    if (ad_value >= 500 && ad_value <= 524) {
        freq_select = (start_freq + stop_freq) / 2;
    } else {

        if ((stop_freq - start_freq) > (UINT32_MAX / 1024)) {
            freq_step = (stop_freq - start_freq) / 1024;
            freq_select = start_freq + freq_step * ad_value;
        } else {
            if (ad_value != 0) {
                freq_step = (stop_freq - start_freq) * ad_value;
                freq_select = start_freq + freq_step / 1024;
            } else {
                freq_select = start_freq;
            }
        }
    }
    return freq_select;
}

bool set_signal_frequency(uint32_t start_freq, uint32_t stop_freq, uint32_t ad_value) {
    uint32_t freq_select, NCO_inc_value;

    freq_select = calculate_frequency(start_freq, stop_freq, ad_value);
    NCO_inc_value = (uint32_t) ((float) freq_select
            / (float) system_clock
            * (float) NCO_overflow_value
            * 2);

    NCO1INCU = (uint8_t) ((NCO_inc_value >> 16) & 0x00FF);
    NCO1INCH = (uint8_t) ((NCO_inc_value >> 8) & 0x00FF);
    NCO1INCL = (uint8_t) (NCO_inc_value & 0x00FF);

    if (!(1048576 % NCO_inc_value)) {
        return true;
    } else {
        return false;
    }
}

void set_signal_modulation_frequency(uint32_t start_freq, uint32_t stop_freq, uint16_t ad_value) {
    float calc_spbrg;
    uint32_t modulation_frequency;

    modulation_frequency = calculate_frequency(start_freq, stop_freq, ad_value);
    BRGH = 0x01;
    BRG16 = 0x01;

    if (modulation_frequency == 0) {
        SP1BRG = UINT16_MAX;
    } else {

        calc_spbrg = (float) system_clock / (float) modulation_frequency / 8.0 - 1.0;

        if (calc_spbrg < 0.0) {
            SP1BRG = 0;
        } else if (calc_spbrg > (float) UINT16_MAX) {
            SP1BRG = UINT16_MAX;
        } else {
            SP1BRG = (uint16_t) calc_spbrg;
        }
    }
}

void interrupt_modulate_carrier_signal(void) {
    TX1REG = get_prbs();
}

void modulate_signal(bool enable) {
    if (enable) {
        PIE3bits.TXIE = 1;
    } else {
        PIE3bits.TXIE = 0;
    }
}

void mux_signal(bool enable) {
    static signal_mux_t signal = MUX_RC5;

    if (!enable) {
        signal = FIRST_MUX;
    }

    switch (signal) {
        case MUX_RC5:
            RC5PPS = 0x01; //RC5->CLC1:CLC1OUT;  
            RC6PPS = 0x00;
            break;
        case MUX_RC6:
            RC5PPS = 0x00;
            RC6PPS = 0x01; //RC6->CLC1:CLC1OUT;
            break;
        case MUX_RC5_RC6:
            RC5PPS = 0x01; //RC5->CLC1:CLC1OUT; 
            RC6PPS = 0x01; //RC6->CLC1:CLC1OUT;
            break;
        default:
            break;
    }

    if (signal == LAST_MUX) {
        signal = FIRST_MUX;
    } else {
        signal++;
    }
}