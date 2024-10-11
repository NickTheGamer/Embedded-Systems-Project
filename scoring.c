/** @file scoring.c
    @authors N.H. Coetzee: nco63
    @date 11/10/2024
    @brief implementation file for the scoring module
*/

#include "scoring.h"
#define MAX_SCORE 3

void scoring_init ()
{
    playerScore = 0;
    enemyScore = 0;
    win = 1;
    lose = 0;
    draw = 2;
}

uint8_t compare (char selfChoice, char enemyChoice)
{
    if (selfChoice == 'R') {
        if (enemyChoice == 'R') {
            return draw;
        } else if (enemyChoice == 'P') {
            enemyScore++;
            return lose;
        } else if (enemyChoice == 'S') {
            playerScore++;
            return win;
        }
    }

    if (selfChoice == 'P') {
        if (enemyChoice == 'R') {
            playerScore++;
            return win;
        } else if (enemyChoice == 'P') {
            return draw;
        } else if (enemyChoice == 'S') {
            enemyScore++;
            return lose;
        }
    }

    if (selfChoice == 'S') {
        if (enemyChoice == 'R') {
            enemyScore++;
            return lose;
        } else if (enemyChoice == 'P') {
            playerScore++;
            return win;
        } else if (enemyChoice == 'S') {
            return draw;
        }
    }
}

uint8_t checkWin ()
{
    if (playerScore >= MAX_SCORE && enemyScore < MAX_SCORE) {
        return win;
    } else if (enemyScore >= MAX_SCORE && playerScore < MAX_SCORE) {
        return lose;
    }
}