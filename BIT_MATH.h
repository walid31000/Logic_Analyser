/**
** ************************************************************
 * @file   BIT_MATH.h
 * @brief  Bit manipulation macros.
 * @details This file contains macros for bit-level operations, such as setting, clearing, toggling, and getting the value of specific bits.
 * @author   Walid Megherbi
 *           <BR>
 *           <EM>
 *           Github: https://github.com/walid31000
 *           </EM>
 * @version   1.0.0
 * @date     31/5/2023
 * @copyright Walid Megherbi

*/




#ifndef BIT_MATH_H
#define BIT_MATH_H


/**
 * @brief Macro to set a specific bit in a variable.
 *
 * @param VAR The variable in which the bit will be set.
 * @param BIT_NUM The bit number to set (0-based).
 */


#define SET_BIT(VAR,BIT_NUM)       ( (VAR)|=(1<<(BIT_NUM) ) )



/**
 * @brief Macro to clear a specific bit in a variable.
 *
 * @param VAR The variable in which the bit will be cleared.
 * @param BIT_NUM The bit number to clear (0-based).
 */

#define CLR_BIT(VAR,BIT_NUM)       ((VAR)&=(~(1<<(BIT_NUM))))


/**
 * @brief Macro to toggle a specific bit in a variable.
 *
 * @param VAR The variable in which the bit will be toggled.
 * @param BIT_NUM The bit number to toggle (0-based).
 */


#define TOG_BIT(VAR,BIT_NUM)       ((VAR) ^=  (1<<(BIT_NUM) ) )

/**
 * @brief Macro to get the value of a specific bit in a variable.
 *
 * @param VAR The variable from which the bit value will be retrieved.
 * @param BIT_NUM The bit number to get (0-based).
 * @return The value of the specified bit (0 or 1).
 */

#define  GET_BIT(VAR,BIT_NUM)     ( ((VAR)>>(BIT_NUM) )&1)


#endif
