/* 
 * File:   inductance.h
 * Author: C07445
 *
 * Created on September 2, 2020, 5:18 PM
 */

#ifndef INDUCTANCE_H
#define	INDUCTANCE_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct {
    uint16_t cycle;
    uint16_t cyclePrev;
    uint8_t count;
    uint32_t frequency;
    uint32_t accumulator;
    unsigned sample : 1;
    uint16_t peakVoltage;
}LCFreqS;


#ifdef	__cplusplus
}
#endif

#endif	/* INDUCTANCE_H */

