/*******************************************************************************
 * File : StringManipulation.c
 * Source File for String Manipulation
 * Description: Various of Functions that serve and manipulate with strings.
 *******************************************************************************/


/**------------------**
 **---- Includes ----**
 **------------------**/
#include "StringManipulation.h"


/**************************************
 **---- Functions Implementation ----**
 **************************************/

/*************************************************************************************
* Service Name: stringLength
* Parameters (in): pau32_array -> Pointer to array of data to search in.
*                  u8_arraySize -> Size of the array pau32_array.
*                  u32_number -> The number to be searched.
* Parameters (inout): None
* Parameters (out):None
* Return value: uint8_t -> unsigned character returns the index of the u32_number.
*                          (-1) returned if the u32_number not found.
* Description: Function to search for u32_number inside the pau32_array and return its index
*              if found, otherwise returns (-1).
* *************************************************************************************/
uint8_t stringLength(uint8_t* string1)
{
    uint8_t u8_loopIndex=0;
    while(string1[u8_loopIndex] != '\0')
    {
        u8_loopIndex++;
    }
    return u8_loopIndex+1;
}

uint8_t stringCompare(uint8_t* string1, uint8_t* string2)
{
    uint8_t u8_loopIndex=0;
    if(stringLength(string1) != stringLength(string2))
        return 0;
    while(string1[u8_loopIndex] != '\0')
    {
        if(string1[u8_loopIndex] != string2[u8_loopIndex])
            return 0;
        u8_loopIndex++;
    }
    return 1;
}


/*
uint16_t arrayToInteger(uint8_t* pu8_Array)
{
    uint8_t u8_arrLength = stringLength(pu8_Array);
    uint8_t u8_loopIndex=0;
    for(u8_loopIndex=0; u8_loopIndex<u8_arrLength; u8_loopIndex++)
    {

    }
}*/
