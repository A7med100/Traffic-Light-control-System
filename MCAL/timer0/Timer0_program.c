#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"
#include  "Timer0_Private.h"
#include  "Timer_Regs.h"
#include "Timer0_Interface.h"

static void (*Timer_func)(void)=Null;

u8 Timer_Init(u8 wgm,u8 clk)
{
	//finding desired mode
	switch(wgm)
	{
	//Setting desired mode bits
	case normal_Mode:
		CLR_BIT(Timer_TCCR0,TCCR_WGM0);
		CLR_BIT(Timer_TCCR0,TCCR_WGM1);
		CLR_BIT(Timer_TCCR0,TCCR_COM2);
		CLR_BIT(Timer_TCCR0,TCCR_COM1);
		break;
	case PWM_Mode:
		CLR_BIT(Timer_TCCR0,TCCR_WGM0);
		SET_BIT(Timer_TCCR0,TCCR_WGM1);
		break;
	case CTC_Mode:
		SET_BIT(Timer_TCCR0,TCCR_WGM1);
		CLR_BIT(Timer_TCCR0,TCCR_WGM1);
		break;
	case fast_PWM_Mode:
		SET_BIT(Timer_TCCR0,TCCR_WGM1);
		SET_BIT(Timer_TCCR0,TCCR_WGM1);
		break;
	default: return NOT_OK;
	}
	//validating input data
	//setting Prescaler
	if(clk<6&&clk>=0)
	{
		Timer_TCCR0&=0b11111000;
		Timer_TCCR0|=clk;
		return OK;
	}
	else
		return NOT_OK;

}

u8 Timer_CompareMatchEvent(u8 mode)
{
	//check input data
	if(mode <fast_PWM_Mode)
	{
		//bit masking for COM01 COM00
		Timer_TCCR0&=0b11001111;
		mode=(mode<<4);
		Timer_TCCR0|=mode;
		return OK;
	}
	else
		return NOT_OK;
}

void Timer_CompareValue(u8 value)
{
	//assigning compare value
	Timer_OCR0=value;
}
void Timer_preload(u8 preload)
{
	//assigning preload value
	Timer_TCNT0=preload;
}



void Timer_SetCallBack(void (*ptrfunc)(void))
{
	//interrupt enable
	SET_BIT(Timer_TIMSK,TIMSK_OCIE0);
	//getting address of desired function
	Timer_func=ptrfunc;
}

void __vector_10 (void)  			__attribute__((signal));
void __vector_10 (void)
{
	//Executing desired actions on interrupt event
	Timer_func();
}

void timer0_delay(u16 Overflows)
{

	//Make timer start from zero
	Timer_TCNT0=0;
	while(0!=Overflows--)
	{
		//wait until flag is raised
		while((Timer_TIFR&(1<<TIFR_OCF0))==0);
		//clear overflow flag
		SET_BIT(Timer_TIFR,TIFR_OCF0);
	}
	//timer stop
	//Timer_TCCR0=0;
}









