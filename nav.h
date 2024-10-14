/** @file nav.h
    @authors J.Cercado jce61, N.H. Coetzee nco63
    @date 15/10/24
    @brief header file for the navigation module
*/


#ifndef NAV_H
#define NAV_H

#include "navswitch.h"

//Function to show single character display
//void display_character(char character);


//Initialise navswitch
void nav_init (void);


//Handle the nav switch, and input and update the character.
char handle_navswitch_input(char character);



#endif