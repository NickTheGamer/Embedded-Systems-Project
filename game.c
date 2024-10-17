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
#define IR_SEND_RATE 10
#define IR_RECEIVE_RATE 10


void game_loop (uint8_t* locked_in_choice, char* character_selected)
{   
    //for ir communication
    static uint8_t ir_send_tick = IR_SEND_RATE;
    static uint8_t ir_receive_tick = IR_RECEIVE_RATE;

    if (*locked_in_choice == 0) {
        led_off ();
        *character_selected = handle_navswitch_input(*character_selected);
        *locked_in_choice = navswitch_push ();
        ir_send_tick = 0;
        ir_receive_tick = 0;
    }

    if (*locked_in_choice == 1) {
                
        led_on ();

        ir_send_tick++;
        ir_receive_tick++;

        if (ir_send_tick >= IR_SEND_RATE) {
            ir_send_tick = 0;
            ir_send (*character_selected);
        }
        if (ir_receive_tick >= IR_RECEIVE_RATE) {
            ir_receive_tick = 0;
            *locked_in_choice = ir_receive (*character_selected);
        }
    }

    display_character (*character_selected);
}


int main (void)
{
    //initialise drivers
    system_init ();
    pacer_init (PACER_RATE);

    //initialise custom modules
    display_char_init (PACER_RATE, MESSAGE_RATE);
    ir_init ();
    scoring_init ();
    nav_init ();
    led_init ();

    //Variables to display and receive characters and the game results
    uint8_t locked_in_choice = 0;
    uint8_t outcome = 0;
    char character_selected = 'R';
    uint8_t game_result;

    while (1)
    {

        //update every tick
        pacer_wait ();
        display_char_update ();
        nav_update ();
        
        //check if anybody has won the game
        game_result = checkWin ();

        if (game_result == WIN) {
            led_off ();
            outcome = WIN;
        } else if (game_result == LOSE) {
            led_off ();
            outcome = LOSE;
        }

        //run game if incomplete
        else if (game_result == GAME_INCOMPLETE) {
            
            game_loop(&locked_in_choice, &character_selected);

        //display text if complete
        } else if (game_result == GAME_COMPLETE) {
            display_text (outcome);
        }

    }
}
