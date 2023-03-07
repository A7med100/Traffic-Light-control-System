#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "Led.h"
#include "../../MCAL/timer0/Timer0_Interface.h"
//#include <util/delay.h>

u8 Led_init(u8 Led_port,u8 Led_pin)
{
	//setting Led_pin as output
	u8 error=SetPinDirection(Led_port,Led_pin,Output);
	//verifying input data
	if(error==Ok)
	{
		return Ok;
	}
	else
		return N_Ok;
}

u8 Led_on(u8 Led_port,u8 Led_pin)
{
	//setting Led_pin high
	u8 error=SetPinValue(Led_port,Led_pin,High);
	//verifying input data
	if(error==Ok)
	{
		return Ok;
	}
	else
		return N_Ok;
}

u8 Led_off(u8 Led_port,u8 Led_pin)
{
	//setting Led_pin Low
	u8 error=SetPinValue(Led_port,Led_pin,Low);
	//verifying input data
	if(error==Ok)
	{
		return Ok;
	}
	else
		return N_Ok;
}

u8 Led_Blink(u8 Led_port,u8 Led_pin,u16 overflows,s16 blink_time_ms,u8 *blinkStop)
{
	u8 error;

	error=togglePin(Led_port,Led_pin);
	//check input data
	if(error==Ok)
	{
		while(blink_time_ms>=1 && *blinkStop!=High)
		{
			//blinking led by blink_delay_ms
			togglePin(Led_port,Led_pin);
			timer0_delay(overflows);
			blink_time_ms-=350;
		}
		SetPinValue(Led_port,Led_pin,Low);
		return Ok;
	}
	else
		return N_Ok;
}
u8 _2Led_Blink(u8 Led1_port,u8 Led1_pin,u8 Led2_port,u8 Led2_pin,u16 overflows,s16 blink_time_ms)
{
	u8 error1,error2;
	error1=togglePin(Led1_port,Led1_pin);
	error2=togglePin(Led2_port,Led2_pin);
	//check input data
	if(error1==Ok&&error2==Ok)
	{
		while(blink_time_ms>=1)
		{
			//blinking LEDs by blink_delay_ms
			error1=togglePin(Led1_port,Led1_pin);
			error2=togglePin(Led2_port,Led2_pin);
//			_delay_ms(500);
			timer0_delay(overflows);
			blink_time_ms-=350;
		}
		SetPinValue(Led1_port,Led1_pin,Low);
		SetPinValue(Led2_port,Led2_pin,Low);
		return Ok;
	}
	else
		return N_Ok;
}

