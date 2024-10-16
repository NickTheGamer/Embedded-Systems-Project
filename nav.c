/** @file nav.c
    @authors J.Cercado jce61, N.H. Coetzee nco63
    @date 15/10/24
    @brief implementation file for the navigation module
*/

#include "nav.h"

//Initalisation of navswitch
void nav_init (void)
{
    navswitch_init();
}

//Function to handle the Nav inputs

char handle_navswitch_input(char character)
{
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


void nav_update (void)
{
    navswitch_update ();
}


uint8_t navswitch_push (void)
{
    if (navswitch_push_event_p(NAVSWITCH_PUSH))
    {
        return 1; //lock navswitch
    } else {
        return 0;
    }
}


