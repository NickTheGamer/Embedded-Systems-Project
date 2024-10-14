/** @file game.c
    @authors N.H. Coetzee: nco63, J. Cercado: jce61
    @date started: 09/10/2024
    @brief main loop for game
*/

#include "system.h"
#include "pacer.h"

#include "display_char.h"
#include "ir.h"
#include "scoring.h"
#include "nav.h"
#include "led.h"

//preprocessor constants for pacer
#define PACER_RATE 500
#define MESSAGE_RATE 10

int main (void)
{
    //initialise drivers
    system_init ();
    pacer_init (PACER_RATE);

    uint16_t ledTick = 0;
    bool led_is_on = 0;

    //initialise custom modules
    //display_init ();
    ir_init ();
    scoring_init ();
    //nav_init ();
    led_init ();

    //Variables to display and receive characters
    //char CharacterSelected = 'R';
    //char temp = '\0';

    while (1)
    {

        pacer_wait ();
        ledTick++;

        if (ledTick >= 200) {
            if (!led_is_on) {
                led_on();
                led_is_on = 1;
            
            } else if (led_is_on) {
                led_off();
                led_is_on = 0;
            }
            
            ledTick = 0;
        }

    }
}
