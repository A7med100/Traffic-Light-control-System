#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"
#include "INT_interface.h"
#include "INT_Registers.h"
#include "INT_Private.h"

void (*ptrcallback)(void);

void INT_SetCallBack(void (*callback)(void))
{
	//making global pointer points to function address
	ptrcallback=callback;
}

u8 INT_ControlSense(u8 intNum,u8 sense)
{
	//verifying input data
	if(sense>0&&sense<5)
	  {
		switch(intNum)
		{
		//Configuring desired interrupt with desired sense signal
		case INT0:
			//bit masking to ensure input data will not be affected
			MCUCR &=INT0_Sense_mask;
			//assigning SC01&ISC00 with desired sense
			MCUCR |= sense;break;
		case INT1:
			sense  = sense<<2;
			MCUCR &= INT1_Sense_mask;
			//assigning SC03&ISC02 with desired sense
			MCUCR |= sense;break;
		case INT2:
			sense  = sense<<ISC2;
			MCUCR &= INT2_Sense_mask;
			//assigning ISC2 with desired sense
			MCUCSR |= sense;break;
		default: return N_Ok;
		}
		return Ok;
	}
	else
		return N_Ok;
}

u8 INT_Enable(u8 intNum)
{
	//verifying input data
	if(intNum>=INT2&&intNum<=INT1)
	{
		//enabling desired input
		SET_BIT(GICR,intNum);
		return Ok;
	}
	else
		return N_Ok;
}
u8 INT_Disable(u8 intNum)
{
	//verifying input data
	if(intNum>=INT2&&intNum<=INT1)
	{
		//disabling desired input
		CLR_BIT(GICR,intNum);
		return Ok;
	}
	else
		return N_Ok;
}



void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	//handling desired actions
	ptrcallback();
}

