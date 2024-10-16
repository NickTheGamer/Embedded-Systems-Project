/** @file led.c
    @authors N.H. Coetzee: nco63
    @date started: 11/10/2024 last edited: 17/10/2024
    @brief implementation file for the led module
*/

#include "led.h"

//use pio module to access blue LED
#define LED_PIO PIO_DEFINE(PORT_C, 2)

/** Turn LED1 on.  */
void led_on (void)
{
    pio_output_high(LED_PIO);
}


/** Turn LED1 off.  */
void led_off (void)
{
    pio_output_low(LED_PIO);
}


/** Initialise LED1.  */
void led_init (void)
{
    pio_config_set(LED_PIO, PIO_OUTPUT_LOW);
}