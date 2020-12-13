/* 
 * File:   switchScan.h
 * Author: C07445
 *
 * Created on March 13, 2020, 3:15 PM
 */

#ifndef SWITCHSCAN_H
#define	SWITCHSCAN_H

#ifdef	__cplusplus
extern "C" {
#endif


#define NUM_SWITCHES 2
#define DEBOUNCECOUNT 50

    typedef enum TSWStates {
        UP = 0, UP_DEBOUNCE, DOWN, DOWN_DEBOUNCE
    } TARGET_SWITCH_STATE;

    typedef struct {
        TARGET_SWITCH_STATE state;
        uint8_t debounce;
        uint8_t change : 1;
        bool(* Position)();
    } SWITCHS;

    extern SWITCHS switchInput[NUM_SWITCHES];
    
    void switchScan(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SWITCHSCAN_H */

