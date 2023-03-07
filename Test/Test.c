/*
 * Test.c
 *
 *  Created on: Feb 10, 2023
 *      Author: USER
 */
#include  "../Utilities/STD_TYPES.h"
#include  "../Utilities/BIT_MATH.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/EXT_Interupts/INT_interface.h"
#include "Test.h"
#include <util/delay.h>


void SetPinDirection_test(u8 port)
{
	//checking for valid values
	SetPinDirection(portD,Pin4,Output);
	u8 error=9;
	error=SetPinDirection(port,0,0);
	if(error!=0)
	{
		SetPinValue(portD,Pin4,High);
		_delay_ms(1000);
		SetPinValue(portD,Pin4,Low);
	}
	else
	{
		u8 counter;
		for(counter=0;counter<9;counter++)
		{
			error=SetPinDirection(port,counter,Output);
			_delay_ms(1000);
			error=SetPinDirection(port,counter,Input);
			_delay_ms(1000);
			if(error!=0)
			{
				SetPinValue(portD,Pin4,High);
				_delay_ms(1000);
				SetPinValue(portD,Pin4,Low);
			}
		}
		//checking for invalid value
		error=SetPinDirection(port,4,2);
		if(error!=0)
		{
			SetPinValue(portD,Pin4,High);
			_delay_ms(1000);
			SetPinValue(portD,Pin4,Low);
		}
	}
}
void SetPinValue_test(u8 port)
{
	//checking for valid values
	SetPinDirection(portD,Pin4,Output);
	u8 error=9;
	error=SetPinValue(port,0,0);
	if(error!=0)
	{
		SetPinValue(portD,Pin4,High);
		_delay_ms(1000);
		SetPinValue(portD,Pin4,Low);
	}
	else
	{
		u8 counter;
		for(counter=0;counter<9;counter++)
		{
			error=SetPinValue(port,counter,Output);
			_delay_ms(1000);
			error=SetPinValue(port,counter,Input);
			_delay_ms(1000);
			if(error!=0)
			{
				SetPinValue(portD,Pin4,High);
				_delay_ms(1000);
				SetPinValue(portD,Pin4,Low);
			}
		}
		//checking for invalid value
		error=SetPinValue(port,4,2);
		if(error!=0)
		{
			SetPinValue(portD,Pin4,High);
			_delay_ms(1000);
			SetPinValue(portD,Pin4,Low);
		}
	}
}

void togglePin_test(u8 port)
{
	//checking for valid values
	SetPinDirection(portD,Pin4,Output);
	u8 error=9;
	error=togglePin(port,0);
	if(error!=0)
	{
		SetPinValue(portD,Pin4,High);
		_delay_ms(1000);
		SetPinValue(portD,Pin4,Low);
	}
	else
	{
		u8 counter;
		for(counter=0;counter<9;counter++)
		{
			error=togglePin(port,counter);
			_delay_ms(1000);
			error=togglePin(port,counter);
			_delay_ms(1000);
			if(error!=0)
			{
				SetPinValue(portD,Pin4,High);
				_delay_ms(1000);
				SetPinValue(portD,Pin4,Low);
			}
		}
	}
}


void EXT_Int_test(u8 int_num)
{
	SetPinDirection(portD,Pin4,Output);
	GIEnable();
	u8 error =INT_ControlSense(int_num,Falling_Edge);
	if(error!=0)
	{
		SetPinValue(portD,Pin4,High);
		_delay_ms(1000);
		SetPinValue(portD,Pin4,Low);
	}
	else
	{
		u8 counter;
		for(counter=0;counter<6;counter++)
		{
			error=INT_ControlSense(int_num,counter);
			_delay_ms(1000);
			if(error!=0)
			{
				SetPinValue(portD,Pin4,High);
				_delay_ms(1000);
				SetPinValue(portD,Pin4,Low);
			}
		}
	}
	INT_Enable(int_num);
	_delay_ms(1000);
	INT_Disable(int_num);
}
