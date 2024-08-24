#ifndef TIMER_REG_H
#define TIMER_REG_H

#define   TCCR0              *((volatile uint8*) 0X53)

#define    TCCR0_WGM01          3U
#define    TCCR0_WGM00          6U

#define    TCCR0_COM00          4U
#define    TCCR0_COM01          5U


#define   TCNT0              *((volatile uint8*) 0X52)    // Timer register

#define   TIMSK              *((volatile uint8*) 0X59) //overflow timer Enable

#define   TIMSK_TOIE0        0U

#define   TIMSK_OCIE0        1U  /*Enable Timer output compare match  interrupt*/

#define   OCR0              *((volatile uint8*) 0X5C) // timer output compare register

#endif
