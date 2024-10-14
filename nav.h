/** @file nav.h
    @authors Jce61 ___
    @date 15/10/24
    @brief header file for the navigation module
*/


#ifndef NAV_H
#define NAV_H

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"

//Function to show single character display
void display_character(char character);


//initialise the UCFK4
void system_setup(void);


//Handle the nav switch, display and input and update the character.
char handle_navswitch_input(char character);



#endif