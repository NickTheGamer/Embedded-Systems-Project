/** @file game.c
    @authors N.H. Coetzee: nco63, J. Cercado: jce61
    @date started: 09/10/2024 last updated: 17/10/2024
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
#define PACER_RATE 300
#define MESSAGE_RATE 10

//constants for game ending conditions
#define WIN 1
#define LOSE 0
#define GAME_INCOMPLETE 3
#define GAME_COMPLETE 4
#define IR_TICK_RATE 10


void game_loop (uint8_t* locked_in_choice, char* character_selected)
{   
    static uint8_t ir_tick = IR_TICK_RATE;

    if (*locked_in_choice == 0) {

        *character_selected = handle_navswitch_input(*character_selected);
        *locked_in_choice = navswitch_push ();
        led_off ();
        ir_tick = IR_TICK_RATE;
    }

    if (*locked_in_choice == 1) {
                
        led_on ();

        ir_tick++;
        if (ir_tick >= IR_TICK_RATE) {
            ir_send (*character_selected);
            *locked_in_choice = ir_receive (*character_selected);
            ir_tick = 0;
        }
    }

    display_character (*character_selected);
}


int main (void)
{
    //initialise drivers
    system_init ();
    pacer_init (PACER_RATE);

    uint8_t locked_in_choice = 0;
    uint8_t outcome = 0;

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
        
        game_result = checkWin ();

        if (game_result == WIN) {
            led_off ();
            outcome = WIN;
        } else if (game_result == LOSE) {
            led_off ();
            outcome = LOSE;
        }

        else if (game_result == GAME_INCOMPLETE) {
            
            game_loop(&locked_in_choice, &character_selected);

        } else if (game_result == GAME_COMPLETE) {
            display_text (outcome);
        }

    }
}
