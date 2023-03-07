/*
 * callBack.c

 *
 *  Created on: Feb 9, 2023
 *      Author: USER
 */
#include  "../../Utilities/STD_TYPES.h"
#include  "../../MCAL/DIO/DIO.h"
#include  "../../MCAL/EXT_Interupts/INT_interface.h"
#include  "../../MCAL/GIE/GIE.h"
#include "../EXT_Int_CallBack/EXT_Interupts_CallBack.h"

u8 EXT_INT_Control(u8 state)
{
	//initializing INT0
	SetPinDirection(portD,Pin2,Input);
	//Setting INT0 pin as pull up
	SetPinValue(portD,Pin2,High);
	//verifying input data
	if(state==enable)
	{
		INT_Enable(INT0);
		return Ok;
	}
	else if(state==disable)
	{
		INT_Disable(INT0);
		return Ok;
	}
	else
		return N_Ok;
}
void pass_callBack(void (*callbak)(void))
{
	//configuring  int0
	INT_ControlSense(INT0,Logical_Change);
	GIEnable();
	//passing input function to ISR
	INT_SetCallBack(callbak);

}


