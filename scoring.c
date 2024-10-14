/** @file scoring.c
    @authors N.H. Coetzee: nco63
    @date 11/10/2024
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
}

uint8_t compare (char selfChoice, char enemyChoice)
{
    if (selfChoice == enemyChoice) {
        return draw;
    }

    else if (selfChoice == 'R') {
        if (enemyChoice == 'P') {
            enemyScore++;
            return lose;
        } else if (enemyChoice == 'S') {
            playerScore++;
            return win;
        }
    }

    else if (selfChoice == 'P') {
        if (enemyChoice == 'R') {
            playerScore++;
            return win;

        } else if (enemyChoice == 'S') {
            enemyScore++;
            return lose;
        }
    }

    else if (selfChoice == 'S') {
        if (enemyChoice == 'R') {
            enemyScore++;
            return lose;
        } else if (enemyChoice == 'P') {
            playerScore++;
            return win;
        }
    }

    return ERROR;
}

uint8_t checkWin (void)
{
    if (playerScore >= MAX_SCORE && enemyScore < MAX_SCORE) {
        return win;
    } else if (enemyScore >= MAX_SCORE && playerScore < MAX_SCORE) {
        return lose;
    }

    else {
        return ERROR;
    }
}