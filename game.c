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
#define GAME_INCOMPLETE 3
#define GAME_COMPLETE 4
#define IR_TICK_RATE 200

int main (void)
{
    //initialise drivers
    system_init ();
    pacer_init (PACER_RATE);

    uint16_t led_tick = 0;
    bool led_is_on = 0;
    uint8_t locked_in_choice = 0;
    uint8_t outcome = 0;
    uint8_t ir_tick = 200;
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
            locked_in_choice = navswitch_push ();
            led_off ();
            //ir_tick = IR_TICK_RATE;
        }

        if (locked_in_choice == 1) {
            
            ir_tick++;
            if (ir_tick >= IR_TICK_RATE) {
                ir_send (character_selected);
                ir_tick = 0;
            }

            locked_in_choice = ir_receive (character_selected);
        }
        
        if (locked_in_choice == 1) {
            
            led_on ();
            /*led_tick++;

            if (led_tick >= 200) {
                if (!led_is_on) {
                    led_on();
                    led_is_on = 1;
            
                } else if (led_is_on) {
                    led_off();
                    led_is_on = 0;
                }
            
                led_tick = 0;
            }*/
        }
        
        game_result = checkWin ();

        if (game_result == WIN) {
            outcome = WIN;
        } else if (game_result == LOSE) {
            outcome = LOSE;
        }

        if (game_result == GAME_INCOMPLETE) {
            display_character (character_selected);
        } else if (game_result == GAME_COMPLETE) {
            display_text (outcome);
        }

    }
}
