/** @file scoring.h
    @authors N.H. Coetzee: nco63
    @date 11/10/2024
    @brief header file for the scoring module
*/


#ifndef SCORING_H
#define SCORING_H

//public scoring variables
#include <stdint.h>
#include "led.h"

uint8_t playerScore;
uint8_t enemyScore;
uint8_t win;
uint8_t lose;
uint8_t draw;
uint8_t game_incomplete;
uint8_t game_finished_bool;

//initialise scores
void scoring_init (void);

//determine the winner of the round, and flashes led1 if you won
void compare (char selfChoice, char enemyChoice);

//checks if a player has won the game, returns 1 if you won, 0 if you lost and 3 if the game isn't finished
uint8_t checkWin (void);

#endif