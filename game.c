/** @file game.c
    @authors N.H. Coetzee: nco63, J. Cercado: jce61
    @date started: 09/10/2024 last updated: 15/10/2024
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

//constants for game ending conditions
#define WIN 1
#define LOSE 0

int main (void)
{
    //initialise drivers
    system_init ();
    pacer_init (PACER_RATE);

    uint16_t led_tick = 0;
    bool led_is_on = 0;
    uint8_t locked_in_choice = 0;
    //uint8_t round_won;

    //initialise custom modules
    display_char_init (PACER_RATE, MESSAGE_RATE);
    ir_init ();
    scoring_init ();
    nav_init ();
    led_init ();

    //Variables to display and receive characters
    char character_selected = 'R';
    uint8_t game_result;

    while (1)
    {

        pacer_wait ();
        display_char_update ();
        nav_update ();

        if (locked_in_choice == 0) {
            character_selected = handle_navswitch_input(character_selected);
            locked_in_choice = navswitch_push (character_selected);
        }

        if (locked_in_choice == 1) {
            locked_in_choice = ir_receive (character_selected);
        }

        led_tick += 1;

        if (locked_in_choice == 1) {
            if (led_tick >= 300) {
                if (!led_is_on) {
                    led_on();
                    led_is_on = 1;
            
                } else if (led_is_on) {
                    led_off();
                    led_is_on = 0;
                }
            
                led_tick = 0;
            }
        }

        display_character (character_selected);
        game_result = checkWin ();

        if (game_result == WIN) {
            display_text (WIN);
        } else if (game_result == LOSE) {
            display_text (LOSE);
        }

    }
}
