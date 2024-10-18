/** @file display_char.c
    @authors N.H. Coetzee: nco63
    @date started: 14/10/2024 last edited: 18/10/2024
    @brief implementation file for the display module
*/

#include "display_char.h"

//text macros for game ending
#define WIN_TEXT "You Won!\0"
#define LOSE_TEXT "You Lost :(\0"


//initialise display
void display_char_init (uint16_t pace_rate, uint8_t message_rate)
{
    tinygl_init (pace_rate);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (message_rate);
}

//display selected choice
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

//display text when game is finished
void display_text (uint8_t result)
{
    static bool first_time = 0;

    if (!first_time) {
        tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
        first_time = 1;

        if (result) {
            tinygl_text (WIN_TEXT);
        } else {
            tinygl_text (LOSE_TEXT);
        }
    }
}

//update every tick
void display_char_update (void)
{
    tinygl_update ();
}

//reset
void display_reset (void)
{
    tinygl_clear ();
}