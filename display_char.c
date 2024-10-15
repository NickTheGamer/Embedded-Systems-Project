/** @file display_char.c
    @authors 
    @date 
    @brief implementation file for the display module
*/

#include "display_char.h"

#define WIN_TEXT "You Won!\0"
#define LOSE_TEXT "You Lost :(\0"


void display_char_init (uint16_t pace_rate, uint16_t message_rate)
{
    tinygl_init (pace_rate);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (message_rate);
}

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

void display_text (uint8_t result)
{
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

    if (result) {
        tinygl_text (WIN_TEXT);
    } else {
        tinygl_text (LOSE_TEXT);
    }
}

void display_char_update (void)
{
    tinygl_update ();
}