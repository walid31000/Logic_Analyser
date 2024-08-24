#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_prv.h"

/*function to set on  led */


uint8 LED_u8SetON(const Led_config_t* copy_LedObject )
{
	uint8 Local_u8Errorstate=OK;

	if(copy_LedObject!=NULL)

	{
		if(copy_LedObject->Activity_type ==ACT_LOW)

			DIO_u8SetPinValue(copy_LedObject->PORT,copy_LedObject->PIN,DIO_PIN_LOW);
		else if(copy_LedObject->Activity_type ==ACT_HIGH)
			DIO_u8SetPinValue(copy_LedObject->PORT,copy_LedObject->PIN,DIO_PIN_HIGH);
		else
		{
			Local_u8Errorstate=NOK;
		}
	}


	else
	{
		return NULL_PTR;
	}
	return Local_u8Errorstate;
}


uint8 LED_u8SetOFF(const Led_config_t* copy_LedObject )
{
	uint8 Local_u8Errorstate=OK;
	if(copy_LedObject!=NULL)

	{
		if(copy_LedObject->Activity_type ==ACT_LOW)
			DIO_u8SetPinValue(copy_LedObject->PORT,copy_LedObject->PIN,DIO_PIN_HIGH);
		else if(copy_LedObject->Activity_type ==ACT_HIGH)
			DIO_u8SetPinValue(copy_LedObject->PORT,copy_LedObject->PIN,DIO_PIN_LOW);
		else
		{
			Local_u8Errorstate=NOK;
		}
	}


	else
	{
		return NULL_PTR;
	}
	return Local_u8Errorstate;
}


uint8 LED_u8ToggleLed(const Led_config_t* copy_LedObject )
{

	uint8 Local_u8Errorstate=OK;
	if(copy_LedObject!=NULL)

	{

		DIO_u8TogglePin(copy_LedObject->PORT,copy_LedObject->PIN);
	}

	else
	{
		return NULL_PTR;
	}
	return Local_u8Errorstate;

}
