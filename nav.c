/** @file nav.c
    @authors Jce61, ___
    @date 15/10/24
    @brief implementation file for the navigation module
*/

#include "nav.h"
#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"

#define PACER_RATE 500  // Pacer Rate
#define MESSAGE_RATE 10 // Message Rate

// Display a character on the display
void display_character (char character)
{
    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

//Initalisation of Components on UCFK4

void system_setup(void)
{
    system_init();
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    navswitch_init();
    pacer_init(PACER_RATE);
}

//Function to handle the Nav inputs

char handle_navswitch_input(char character)
{
    navswitch_update(); // To update the state of the nav switch

    //cycle foward (R > P >S) when navswitch is pushed north
    if(navswitch_push_event_p(NAVSWITCH_NORTH))
    {
        if (character == 'R')
        {
            character = 'P';
        }
        else if (character == 'P')
        {
            character = 'S';
        }
        else 
        {
            character = 'R';
        }

    }

    //Likewise when navswitch is pushed south
    if(navswitch_push_event_p(NAVSWITCH_SOUTH))
    {
        if (character == 'R')
        {
            character = 'S';
        }
        else if (character == 'P')
        {
            character = 'R';

        }
        else 
        {
            character = 'P';

        }
        
    }
    return character;
}

//start up
int main(void);
{
    char character = 'R';
    
    system_setup();

    while (1)
    {
        pacer_wait();
        tinygl_update();

        
    //Navswitch input and update the character shown
    character = handle_navswitch_input(character);

    //display it
    display_character(character);

    }
    
    return 0;

}

