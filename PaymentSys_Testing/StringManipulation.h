/*******************************************************************************
 * File : StringManipulation.h
 * Header File for String Manipulation
 * Description: Various of Functions that serve and manipulate with strings.
 *******************************************************************************/

#ifndef _STRINGMANIPULATION_H_
#define _STRINGMANIPULATION_H_


/**------------------**
 **---- Includes ----**
 **------------------**/
#include <stdlib.h>
#include "Platform_Types.h"



/*********************************
 **---- Functions Prototype ----**
 *********************************/

/**
 ** FUNCTIONS PROTOTYPE
 **/
uint8_t stringCompare(uint8_t* string1, uint8_t* string2);
uint8_t stringLength(uint8_t* string1);
void stringCopy(uint8_t* stringSource, uint8_t* stringDestination);
#endif // _STRINGMANIPULATION_H_




