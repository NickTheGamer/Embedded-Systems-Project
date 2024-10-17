/** @file scoring.c
    @authors N.H. Coetzee: nco63
    @date started: 11/10/2024 last edited: 18/10/2024
    @brief implementation file for the scoring module
*/

#include "scoring.h"
#define MAX_SCORE 3
#define ERROR 5
#define WIN 1
#define LOSE 0
#define DRAW 2
#define GAME_INCOMPLETE 3
#define GAME_COMPLETE 4

uint8_t playerScore = 0;
uint8_t enemyScore = 0;
uint8_t game_finished_bool = 0;


void scoring_init (void)
{
    playerScore = 0;
    enemyScore = 0;
    game_finished_bool = 0;
}

void compare (char selfChoice, char enemyChoice)
{

    if (selfChoice == 'R') {
        if (enemyChoice == 'P') {
            enemyScore++;
            
        } else if (enemyChoice == 'S') {
            playerScore++;
        }
    }

    else if (selfChoice == 'P') {
        if (enemyChoice == 'R') {
            playerScore++;

        } else if (enemyChoice == 'S') {
            enemyScore++;
        }
    }

    else if (selfChoice == 'S') {
        if (enemyChoice == 'R') {
            enemyScore++;

        } else if (enemyChoice == 'P') {
            playerScore++;
        }
    }
}

uint8_t checkWin (void)
{
    if (game_finished_bool == 0) {
        if (playerScore >= MAX_SCORE && enemyScore < MAX_SCORE) {
            game_finished_bool = 1;
            return WIN;
        } else if (enemyScore >= MAX_SCORE && playerScore < MAX_SCORE) {
            game_finished_bool = 1;
            return LOSE;
        }

        else {
            return GAME_INCOMPLETE;
        }
    }

    return GAME_COMPLETE;
}