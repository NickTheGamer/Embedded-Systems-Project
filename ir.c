/** @file ir.c
    @authors Justin Cercado jce61 
    @date 10/12/24
    @brief implementation file for the IR communication module
*/

#include "ir.h"
#include <avr/io.h> //for the Funkit

//intitalisation
void ir_init(void) {
    //set up code
    DDRD &= ~(1 << IR_PIN); //unsure yet, need to check this if it works just typing idea for now

    PORTD != (1 << IR_PIN);
}

int ir_signal(void) {
    
    if(!(PIND & (1 << IR_PIN))) {
        if (code == 0x1A) {
            return 1; //rock
        } else if (code == 0x1B) {
            return 2; //paper
        } else if (code == 0x1C) {
            return 3; //scissors
        }

    }

    return 0;
}
