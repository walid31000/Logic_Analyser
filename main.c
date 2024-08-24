/*
 * main.c
 *using timer 0 we performe delays on 3 LED :RED,Green,Bleu connected to PORTC 0,1,2 respectevely
 *LED RED is on for 5 msec,and OFF for 15 msec
 *LED GREEN is ON for 10 msec and OFF for 10 msec
 *LED BLEU is ON for 15 msec and OFF for 5 msec
 *  Created on: 11 Aug 2024
 *      Author: walid
 */

/**
 * @file 3LED_assignemnt.c
 * @brief Implementation of LED control using Timer in CTC mode.system frequency=8MHZ,prescaler=8, compare value=100
 * @details This file contains the implementation of a simple LED control system that uses a timer in CTC mode to toggle LEDs at specific intervals.
 * @date 10 Aug 2024
 * @author Walid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "Timer_interface.h"
#include "GIE_interface.h"

/**
 * @brief Timer CTC mode callback function to control LEDs.
 * @details This function is called when the Timer in CTC mode reaches the compare value. It toggles the state of three LEDs based on a counter value.
 */
void TIMER_u8CTC_LED(void);

/**
 * @brief LED configuration structure for the red LED.
 */
Led_config_t LED_RED = {DIO_PORTC, DIO_PIN0, ACT_HIGH};



/**
 * @brief LED configuration structure for the green LED.
 */
Led_config_t LED_GREEN = {DIO_PORTC, DIO_PIN1, ACT_HIGH};

/**
 * @brief LED configuration structure for the blue LED.
 */
Led_config_t LED_BLEU = {DIO_PORTC, DIO_PIN2, ACT_HIGH};

/**
 * @brief Main function to initialize the system and start the LED control loop.
 * @details The main function initializes the ports, sets up the timer in CTC mode, and enters an infinite loop where the LEDs are controlled by the timer callback.
 */
void main()
{
    PORT_voidIint();//intialize pin directions

    Timer_voidInit_CTC();

    TIMER_u8SetCallBack(&TIMER_u8CTC_LED);

    GIE_voidEnableGlobal(); //enable global interrupt
    LED_u8SetON(&LED_RED);
    LED_u8SetOFF(&LED_GREEN);
    LED_u8SetOFF(&LED_BLEU);

    while (1)
    {
        // Infinite loop to keep the program running
    }
}

/**
 * @brief Timer CTC mode interrupt service routine.
 * @details This function is called periodically by the timer interrupt. It manages the toggling of the red, blue, and green LEDs based on a counter.
 */
void TIMER_u8CTC_LED(void)
{
    static volatile uint16 Counter = 0;

    Counter++;
    if (Counter == 50)
    {
        LED_u8SetOFF(&LED_RED);
        LED_u8SetON(&LED_BLEU);
    }
    else if (Counter == 100)
    {
        LED_u8SetON(&LED_GREEN);
    }
    else if (Counter == 200)
    {
        LED_u8SetOFF(&LED_GREEN);
        LED_u8SetON(&LED_RED);
        LED_u8SetOFF(&LED_BLEU);

        Counter = 0;//reset the counter
    }
}

