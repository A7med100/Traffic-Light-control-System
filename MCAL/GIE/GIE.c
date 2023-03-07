#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"
#include "GIE.h"





void GIEnable(void)
{
	SET_BIT(SREG,GIE_Pin);
}

void GIDisable(void)
{
	CLR_BIT(SREG,GIE_Pin);
}
