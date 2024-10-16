/** @file ir.h
    @authors N.H. Coetzee: nco63
    @date started: 1/10/2024 last edited: 15/10/2024
    @brief header file for the IR communication module
*/

#ifndef LED_H
#define LED_H

#include "pio.h"
#include <stdint.h>

/** Turn LED1 on.  */
void led_on (void);


/** Turn LED1 off.  */
void led_off (void);


/** Initialise LED1.  */
void led_init (void);


#endif