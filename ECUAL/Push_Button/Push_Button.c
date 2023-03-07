/*
 * Push_Button.c
 *
 *  Created on: Feb 6, 2023
 *      Author: USER
 */
#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "Push_Button.h"

void Button_init(u8 buttonPort,u8 buttonPin)
{
	SetPinDirection(buttonPort,buttonPin,Input);
}
void Button_read(u8 buttonPort,u8 buttonPin,u8 *value)
{
	GetPinValue(buttonPort,buttonPin,value);
}
