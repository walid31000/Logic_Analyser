/** ************************************************************
 * @file   DIO_reg.h
 *  @brief  Register definitions for the Digital Input/Output (DIO) module.
 * @details This file contains the definitions for the registers associated with the Digital Input/Output (DIO) module of the microcontroller. It provides access to the Data Direction Register (DDR), Port Register (PORT), and Input Pins Register (PIN) for each port.
 * @author   Walid Megherbi
 *           <BR>
 *           <EM>
 *           Github: https://github.com/walid31000
 *           </EM>
 * @version   1.0.0
 * @date     31/5/2023
 * @copyright Walid Megherbi

*/

#ifndef DIO_REG_H_
#define DIO_REG_H_

/**
 * @brief Data Direction Register Address for Port A.
 */
#define  DDRA                       *((volatile uint8*) 0X3A)


/**
 * @brief Data Register Address for Port A.
 */
#define  PORTA                      *((volatile uint8*) 0X3B)

/**
 * @brief Input Pins Register Address for Port A.
 */
#define  PINA                      *((volatile uint8*) 0X39)



/**
 * @brief Data Direction Register Address for Port B.
 */

#define  DDRB                       *((volatile uint8*) 0X37)

/**
 * @brief Data Register Address for Port B.
 */

#define  PORTB                      *((volatile uint8*) 0X38)

/**
 * @brief Input Pins Register Address for Port B.
 */
#define  PINB                      *((volatile uint8*) 0X36)

/**
 * @brief Data Direction Register Address for Port C.
 */



#define  DDRC                       *((volatile uint8*) 0X34)


/**
 * @brief Data Register Address for Port B.
 */
#define  PORTC                      *((volatile uint8*) 0X35)

/**
 * @brief Input Pins Register Address for Port C.
 */
#define  PINC                      *((volatile uint8*) 0X33)

/**
 * @brief Data Register Address for Port D.
 */
#define  DDRD                      *((volatile uint8*) 0X31)
/**
 * @brief Input Pins Register Address for Port D.
 */

#define  PORTD                      *((volatile uint8*) 0X32)

/**
 * @brief Input Pins Register Address for Port D.
 */
#define  PIND                      *((volatile uint8*) 0X30)











#endif
