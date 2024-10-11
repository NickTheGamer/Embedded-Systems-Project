/** @file ir.h
    @authors Justin Cercado @jce61
    @date 12/10/2024
    @brief header file for the IR communication module
*/


#ifndef IR_H
#define IR_H

//initialise IR 
void ir_init(void);

//Player move based on signal time(1 = rock, 2 = Paper, 3 = Scissors)
int ir_get_signal(void);


#endif //IR_H