/** @file ir.h
    @authors Justin Cercado @jce61,  N.H. Coetzee nco63
    @date 12/10/2024
    @brief header file for the IR communication module
*/


#ifndef IR_H
#define IR_H

//initialise IR 
void ir_init (void);


//send character from IR
void ir_send (char character);


//Recieve character from IR and call the scoring method
void ir_receive (char character_selected);


#endif //IR_H