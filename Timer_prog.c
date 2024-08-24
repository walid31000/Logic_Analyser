/*Test overflow timer mode*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"

#include "Timer_interface.h"




#include "Timer_reg.h"


static  void (*TIMER_pfuncptr) (void)=NULL;

void Timer_voidInit(void)//for ovf mode
{

/*choose prescaler 8*/

TCCR0 &=0b11111000; /*clear the bits CS0,1,2*/
TCCR0|=2;


/*choose normal mode */
CLR_BIT(TCCR0,TCCR0_WGM01);
CLR_BIT(TCCR0,TCCR0_WGM00);

/*Enable overflow interrupt*/

SET_BIT(TIMSK,TIMSK_TOIE0);

}


void Timer_voidInit_CTC(void)//for CTC mode
{


/*choose CTC mode */
SET_BIT(TCCR0,TCCR0_WGM01);
CLR_BIT(TCCR0,TCCR0_WGM00);

/*output compare mode :OC0 :diconnected*/
CLR_BIT(TCCR0,TCCR0_COM00);
CLR_BIT(TCCR0,TCCR0_COM01);

/*choose prescaler 64*/

TCCR0 &=PRESCALER_MESK; /*clear the bits CS0,1,2*/
TCCR0|=TIMER_PRESCALER;

/*output compare value =250*/
OCR0 =100;

/*Enable Timer output compare match  interrupt*/

SET_BIT(TIMSK,TIMSK_OCIE0 );

}
/*Timer set callback function*/

uint8 TIMER_u8SetCallBack(void(*copy_pvFuncPtr)(void))
{
	uint8 Local_u8Errorstate=OK;
	if(copy_pvFuncPtr!=NULL)
	{
		TIMER_pfuncptr=copy_pvFuncPtr;


	}
	else
	{
		return NULL_PTR;
	}

	return Local_u8Errorstate;

}




/*TIMER conversion complete ISR*/

void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void)
{

	if(TIMER_pfuncptr!=NULL)
	{
		TIMER_pfuncptr();
	}
	else
	{
		/*Do nothing*/
	}






}



/*TIMER CTC ISR*/

void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{

	if(TIMER_pfuncptr!=NULL)
	{
		TIMER_pfuncptr();
	}






}
