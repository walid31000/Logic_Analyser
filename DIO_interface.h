/** ************************************************************
 * @file   DIO_interface.h
 * @brief  prototypes of public function API & defines
 * @author   Walid Megherbi
 *           <BR>
 *           <EM>
 *           Github: https://github.com/walid31000
 *           </EM>
 * @version   1.0.0
 * @date     31/5/2023
 * @copyright Walid Megherbi
 *
 *
 * @image  html DIO_test "Hardware schematic"
 *         <BR>
 * @details <B> Details </B>
 *          <B> Turn on the Led with each press on the switch
 *          <BR>
 *          <B> Target </B> ATMEGA 32
 *          <BR>
 *          <B> internal clock </B> 8MHZ
 *          <BR>
 *          <B> Compiler </B>  GCC
 *
 *
 */




#ifndef  DIO_INTERFACE_H
#define DIO_INTERFACE_H
/**
 * @brief Enumeration for the available ports.
 */
typedef enum
{
	
  DIO_PORTA ,    /**< Port A */
  DIO_PORTB ,    /**< Port B */
  DIO_PORTC ,    /**< Port C */
  DIO_PORTD      /**< Port D */

}DIO_Port_t;

/**
 * @brief Enumeration for the available pins.
 */
typedef enum
{
    DIO_PIN0,  //!< pin number 0
	DIO_PIN1,  //!< pin number 1
	DIO_PIN2,  //!< pin number 2
	DIO_PIN3,  //!< pin number 3
	DIO_PIN4,  //!< pin number 4
	DIO_PIN5,  //!< pin number 5
	DIO_PIN6,  //!< pin number 6
	DIO_PIN7   //!< pin number 7

}DIO_Pin_t;

/**
 * @brief Enumeration for the pin direction.
 */
typedef enum
{
     DIO_PIN_INPUT,   //!<Bit value for input state
	 DIO_PIN_OUTPUT   //!<Bit value for output state

}DIO_PinDir_t;

/**
 * @brief Enumeration for the pin values.
 */


typedef enum
{
	DIO_PIN_LOW,   //!<Logic Low
	DIO_PIN_HIGH   //!<Logic High
}DIO_PinVal_t;	

//============================Functions prototypes =============================================
/**
*************************************************************************************************
*************************************************************************************************
***********************************************************************************************


 * @brief Sets the direction of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @param copy_Dir The direction of the pin (input or output).
 * @return uint8 Status of the operation (0 for success, 1 for failure).
 */


uint8 DIO_u8SetPinDirection (DIO_Port_t copy_Port, DIO_Pin_t copy_PinNum,DIO_PinDir_t copy_Dir);

/**
 * @brief Sets the direction of all pins in a port.
 *
 * @param copy_Port The port whose pins' directions are to be set.
 * @param copy_u8PortDir The direction for all pins in the port.
 * @return uint8 Status of the operation (0 for success, 1 for failure).
 */


uint8 DIO_SetPortDirection (DIO_Port_t copy_Port ,uint8 copy_u8Port_Dir );


/**
 * @brief Sets the value of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @param copy_Val The value to set the pin (high or low).
 * @return uint8 Error Status of the operation (0 for success, 1 for failure).
 */

uint8 DIO_u8SetPinValue (DIO_Port_t copy_Port, DIO_Pin_t copy_PinNum,DIO_PinVal_t  copy_Val); 

/**
 * @brief Sets the value of all pins in a port.
 *
 * @param copy_Port The port whose pins' values are to be set.
 * @param copy_u8PortVal The value to set for all pins in the port.
 * @return uint8  Status of the operation (0 for success, 1 for failure).
 */


uint8 DIO_SetPortValue (DIO_Port_t copy_Port ,uint8 copy_u8PortVal );

/**
 * @brief Gets the value of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @param copy_pVal Pointer to store the retrieved value of the pin.
 * @return uint8 Status of the operation (0 for success, 1 for failure).
 */


uint8  DIO_u8GetPinValue (DIO_Port_t copy_Port, DIO_Pin_t copy_PinNum, DIO_PinVal_t*  copy_pVal);

/**
 * @brief Toggles the value of a specific pin.
 *
 * @param copy_Port The port of the pin.
 * @param copy_PinNum The pin number.
 * @return uint8 Status of the operation (0 for success, 1 for failure).
 */


uint8 DIO_u8TogglePin(DIO_Port_t copy_Port,DIO_Pin_t copy_PinNum);





#endif
