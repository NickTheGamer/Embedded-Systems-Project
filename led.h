/** @file ir.h
    @authors N.H. Coetzee: nco63
    @date 11/10/2024
    @brief header file for the IR communication module
*/

#ifndef LED_H
#define LED_H

#include "pio.h"

/** Turn LED1 on.  */
void led_on (void);


/** Turn LED1 off.  */
void led_off (void);


/** Initialise LED1.  */
void led_init (void);


//flash LED1
void led_flash (void);


#endif