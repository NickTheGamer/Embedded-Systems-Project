/** @file ir.c
    @authors Justin Cercado jce61, N.H. Coetzee nco63
    @date 15/10/24
    @brief implementation file for the IR communication module
*/

#include "ir.h"
#include "ir_uart.h"
#include "scoring.h"


// Initalise the IR 
void ir_init(void)
{
    ir_uart_init();
}

//Send a character from the navswitch
void ir_send(char character)
{
    if (ir_uart_write_ready_p())
    {
        ir_uart_putc(character);
    }
}

//Reciever
uint8_t ir_receive(char character_selected)
{
    if (ir_uart_read_ready_p())
    {
        char temp = ir_uart_getc();
        if (temp == 'R' || temp == 'P' || temp == 'S') {
            compare(character_selected, temp);
            return 0; //release navswitch
        }
    }
    return 1; //keep navswitch locked
}
