/** ************************************************************
 * @file   DIO_prog.c
 *@brief   Implementation of Digital Input/Output (DIO) functions.
 * @details This file contains the implementation of functions for configuring and manipulating the Digital Input/Output (DIO) module. Functions include setting pin directions, setting pin values, toggling pin values, and reading pin values.
 * @author   Walid Megherbi
 *           <BR>
 *           <EM>
 *           Github: https://github.com/walid31000
 *           </EM>
 * @version   1.0.0
 * @date     31/5/2023
 * @copyright Walid Megherbi

*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Err_type.h"
#include "DIO_reg.h"
#include "DIO_interface.h"

/**
 * @brief Sets the direction of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @param copy_Dir The direction of the pin (input or output).
 * @return uint8 Status of the operation (OK for success, NOK for failure).
 */

uint8 DIO_u8SetPinDirection(DIO_Port_t copy_Port,DIO_Pin_t copy_PinNum, DIO_PinDir_t copy_Dir)
{
	uint8 LocalErrorState=OK;
	if((copy_PinNum<=7)&&(copy_Port<=3))
	{
		if(copy_Dir==DIO_PIN_INPUT)
		{
			switch(copy_Port)
			{
			case DIO_PORTA:CLR_BIT(DDRA,copy_PinNum);break;
			case DIO_PORTB:CLR_BIT(DDRB,copy_PinNum);break;
			case DIO_PORTC:CLR_BIT(DDRC,copy_PinNum);break;
			case DIO_PORTD:CLR_BIT(DDRD,copy_PinNum);break;
			default:LocalErrorState=NOK;break;
			}
		}
		else if(copy_Dir==DIO_PIN_OUTPUT)
		{
			switch(copy_Port)
			{
			case DIO_PORTA:SET_BIT(DDRA,copy_PinNum);break;
			case DIO_PORTB:SET_BIT(DDRB,copy_PinNum);break;
			case DIO_PORTC:SET_BIT(DDRC,copy_PinNum);break;
			case DIO_PORTD:SET_BIT(DDRD,copy_PinNum);break;
			default:LocalErrorState=NOK;break;
			}
		}
		else
		{
			LocalErrorState=NOK;
		}
	}
	else
	{
		LocalErrorState=NOK;
	}
	return LocalErrorState;

}	



/**
 * @brief Sets the direction of all pins in a port.
 *
 * @param copy_Port The port whose pins' directions are to be set.
 * @param copy_u8PortDir The direction for all pins in the port.
 * @return uint8 Status of the operation (OK for success, NOK for failure).
 */

uint8 DIO_u8SetPortDirection(DIO_Port_t copy_Port, uint8 copy_u8PortDir)
{
	uint8 LocalErrorState=OK;

	switch(copy_Port)
	{
	case DIO_PORTA:DDRA=copy_u8PortDir;break;
	case DIO_PORTB:DDRB=copy_u8PortDir;break;
	case DIO_PORTC:DDRC=copy_u8PortDir;break;
	case DIO_PORTD:DDRD=copy_u8PortDir;break;
	default:LocalErrorState=NOK;break;
	}



	return LocalErrorState;
}



/**
 * @brief Sets the value of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @param copy_Val The value to set the pin (high or low).
 * @return uint8 Status of the operation (OK for success, NOK for failure).
 */

uint8 DIO_u8SetPinValue(DIO_Port_t copy_Port,DIO_Pin_t copy_PinNum, DIO_PinVal_t copy_Val)
{
	uint8 LocalErrorState=OK;
	if((copy_PinNum<=7)&&(copy_Port<=3))
	{
		if(copy_Val==DIO_PIN_LOW)
		{
			switch(copy_Port)
			{
			case DIO_PORTA:CLR_BIT(PORTA,copy_PinNum);break;
			case DIO_PORTB:CLR_BIT(PORTB,copy_PinNum);break;
			case DIO_PORTC:CLR_BIT(PORTC,copy_PinNum);break;
			case DIO_PORTD:CLR_BIT(PORTD,copy_PinNum);break;
			default:LocalErrorState=NOK;break;
			}
		}
		else if(copy_Val==DIO_PIN_HIGH)
		{
			switch(copy_Port)
			{
			case DIO_PORTA:SET_BIT(PORTA,copy_PinNum);break;
			case DIO_PORTB:SET_BIT(PORTB,copy_PinNum);break;
			case DIO_PORTC:SET_BIT(PORTC,copy_PinNum);break;
			case DIO_PORTD:SET_BIT(PORTD,copy_PinNum);break;
			default:LocalErrorState=NOK;break;
			}
		}
		else
		{
			LocalErrorState=NOK;
		}
	}
	else
	{
		LocalErrorState=NOK;
	}
	return LocalErrorState;


}


/**
 * @brief Sets the value of all pins in a port.
 *
 * @param copy_Port The port whose pins' values are to be set.
 * @param copy_u8PortVal The value to set for all pins in the port.
 * @return uint8 Status of the operation (OK for success, NOK for failure).
 */

uint8 DIO_u8SetPortValue (DIO_Port_t copy_Port ,uint8 copy_u8PortVal)
{
	uint8 LocalErrorState=OK;

	switch(copy_Port)
	{
	case DIO_PORTA:PORTA=copy_u8PortVal;break;
	case DIO_PORTB:PORTB=copy_u8PortVal;break;
	case DIO_PORTC:PORTC=copy_u8PortVal;break;
	case DIO_PORTD:PORTD=copy_u8PortVal;break;
	default:LocalErrorState=NOK;break;
	}




	return LocalErrorState;


}	



/**
 * @brief Gets the value of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @param copy_pVal Pointer to store the retrieved value of the pin.
 * @return uint8 Status of the operation (OK for success, NOK for failure, NULL_PTR for null pointer).
 */

uint8 DIO_u8GetPinValue (DIO_Port_t copy_Port ,DIO_Pin_t copy_PinNum, DIO_PinVal_t* copy_pVal)
{
	uint8 LocalErrorState=OK;
	if(copy_pVal!=NULL)
	{
		if(copy_PinNum<=7)
		{
			switch(copy_Port)
			{
			case DIO_PORTA: *copy_pVal=GET_BIT(PINA,copy_PinNum);break;
			case DIO_PORTB: *copy_pVal=GET_BIT(PINB,copy_PinNum);break;
			case DIO_PORTC: *copy_pVal=GET_BIT(PINC,copy_PinNum);break;
			case DIO_PORTD: *copy_pVal=GET_BIT(PIND,copy_PinNum);break;
			default:LocalErrorState=NOK;break;
			}
		}
		else
		{
			LocalErrorState=NOK;
		}
	}
	else
	{
		LocalErrorState=NULL_PTR;
	}
	return LocalErrorState;
}



/**
 * @brief Toggles the value of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @return uint8 Status of the operation (OK for success, NOK for failure).
 */

uint8 DIO_u8TogglePin(DIO_Port_t copy_Port,DIO_Pin_t copy_PinNum)
{
	uint8 LocalErrorState=OK;

	if(copy_PinNum<=7)
	{
		switch(copy_Port)
		{
		case DIO_PORTA: TOG_BIT(PORTA,copy_PinNum);break;
		case DIO_PORTB: TOG_BIT(PORTB,copy_PinNum);break;
		case DIO_PORTC: TOG_BIT(PORTC,copy_PinNum);break;
		case DIO_PORTD: TOG_BIT(PORTD,copy_PinNum);break;
		default:LocalErrorState=NOK;break;
		}

	}
	else
	{
		LocalErrorState=NOK;
	}
	return LocalErrorState;

}	
