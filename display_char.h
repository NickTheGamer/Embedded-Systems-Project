/** @file display_char.h
    @authors 
    @date 
    @brief header file for the display module
*/


#ifndef DISPLAY_CHAR_H
#define DISPLAY_CHAR_H

#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdint.h>

//initialise display
void display_char_init (uint16_t pace_rate, uint16_t message_rate);

//display character that will be sent to opponent
void display_character (char character);

//display win / loss text
void display_text (uint8_t result);

//update once per loop
void display_char_update (void);

#endif