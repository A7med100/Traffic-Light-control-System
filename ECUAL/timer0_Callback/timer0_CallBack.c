/*
 * CallBack.c
 *
 *  Created on: Feb 13, 2023
 *      Author: USER
 */
#include "../../Utilities/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include  "../../MCAL/timer0/Timer0_Interface.h"
#include "../../MCAL/GIE/GIE.h"
#include "timer0_CallBack.h"


void timer0_passCallback(void (*notific)(void))
{
	Timer_SetCallBack(notific);
}

void timer0_Start(u8 prescaler ,u8 compareValue)
{
	if(compareValue==0)
	{
		Timer_Init(normal_Mode,prescaler);
	}
	else
	{
		Timer_Init(CTC_Mode,prescaler);
		Timer_CompareValue(compareValue);
	}
}

void delay(u16 overflows)
{
	timer0_delay(overflows);
}
