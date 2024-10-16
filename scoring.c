/** @file scoring.c
    @authors N.H. Coetzee: nco63
    @date started: 11/10/2024 last edited: 
    @brief implementation file for the scoring module
*/

#include "scoring.h"
#define MAX_SCORE 3
#define ERROR 5

void scoring_init (void)
{
    playerScore = 0;
    enemyScore = 0;
    win = 1;
    lose = 0;
    draw = 2;
    game_incomplete = 3;
}

void compare (char selfChoice, char enemyChoice)
{

    if (selfChoice == 'R') {
        if (enemyChoice == 'P') {
            enemyScore++;
        } else if (enemyChoice == 'S') {
            playerScore++;
            //led_flash ();
        }
    }

    else if (selfChoice == 'P') {
        if (enemyChoice == 'R') {
            playerScore++;
            //led_flash ();

        } else if (enemyChoice == 'S') {
            enemyScore++;
        }
    }

    else if (selfChoice == 'S') {
        if (enemyChoice == 'R') {
            enemyScore++;
        } else if (enemyChoice == 'P') {
            playerScore++;
            //led_flash ();
        }
    }
}

uint8_t checkWin (void)
{
    if (playerScore >= MAX_SCORE && enemyScore < MAX_SCORE) {
        return win;
    } else if (enemyScore >= MAX_SCORE && playerScore < MAX_SCORE) {
        return lose;
    }

    else {
        return game_incomplete;
    }
}