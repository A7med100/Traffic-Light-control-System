#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"
#include "DIO.h"


/*--------------------------------setportvalue--------------------------------*/

DIO_Error_t setportvalue(u8 Port ,u8 portvalue)
{
	//check input port in valid range or no
	if(Port>portD)
	{
		return invalid_port;
	}
	else
	{
		//finding desired port to be configured
		switch(Port)
		{
		//assigning input port with input portvalue
		case portA:PORTA=portvalue;break;
		case portB:PORTB=portvalue;break;
		case portC:PORTC=portvalue;break;
		case portD:PORTD=portvalue;break;
		}
	}
	return Ok;
}
/*--------------------------------setpinvalue--------------------------------*/
DIO_Error_t SetPinValue(u8 port,u8 pinorder,u8 pinvalue)
{
	//check input port in valid range or no
	if(port>portD)
	{
		return invalid_port;
	}
	//check input pinorder in valid range or no
	else if(pinorder>Pin7)
	{
		return invalid_pin;
	}
	//check input pinvalue in valid range or no
	else if(pinvalue>High)
	{
		return invalid_value;
	}
	else
	{
		//finding desired port to be configured
		switch(port)
		{
		case portA:
			//finding desired pin to be configured
			switch(pinvalue)
			{
			case 0:
				//assigning desired pin with input value
				PORTA &=  ~(1<<pinorder);break;
			case 1:
				PORTA|=(1<<pinorder);break;
			}
			break;

			case portB:
				switch(pinvalue)
				{
				case 0:
					PORTB &=  ~(1<<pinorder);break;
				case 1:
					PORTB|=(1<<pinorder);break;
				}
				break;

				case portC:
					switch(pinvalue)
					{
					case 0:
						PORTC &=  ~(1<<pinorder);break;
					case 1:
						PORTC|=(1<<pinorder);break;
					}
					break;

					case portD:
						switch(pinvalue)
						{
						case 0:
							PORTD&=  ~(1<<pinorder);break;
						case 1:
							PORTD|=(1<<pinorder);break;
						}
						break;
		}
	}
	return Ok;

}
/*--------------------------------setportdirection--------------------------------*/
DIO_Error_t setportdirection(u8 port, u8 portvalue)
{
	//check input port in valid range or no
	if(port>portD)
	{
		return invalid_port;
	}
	else
	{
		//finding desired port to be configured
		switch(port)
		{
		//assigning input port with input portvalue
		case portA:DDRA=portvalue;break;
		case portB:DDRB=portvalue;break;
		case portC:DDRC=portvalue;break;
		case portD:DDRD=portvalue;break;
		}
	}
	return Ok;
}
/*--------------------------------setpindirection--------------------------------*/
DIO_Error_t SetPinDirection(u8 port ,u8 pinorder,u8 pinvalue)
{
	//check input port in valid range or no
	if(port>portD)
	{
		return invalid_port;
	}
	//check input pinorder in valid range or no
	else if(pinorder>Pin7)
	{
		return invalid_pin;
	}
	//check input pinvalue in valid range or no
	else if(pinvalue>High)
	{
		return invalid_value;
	}
	else
	{
		//finding desired port to be configured
		switch(port)
		{
		case portA:
			//finding desired pin to be configured
			switch(pinvalue)
			{
			case 0:
				//assigning desired pin with input value
				DDRA &=  ~(1<<pinorder);break;
			case 1:
				DDRA|=(1<<pinorder);break;
			}
			break;

			case portB:
				switch(pinvalue)
				{
				case 0:
					DDRB &=  ~(1<<pinorder);break;
				case 1:
					DDRB|=(1<<pinorder);break;
				}
				break;

				case portC:
					switch(pinvalue)
					{
					case 0:
						DDRC &=  ~(1<<pinorder);break;
					case 1:
						DDRC|=(1<<pinorder);break;
					}
					break;

					case portD:
						switch(pinvalue)
						{
						case 0:
							DDRD &=  ~(1<<pinorder);break;
						case 1:
							DDRD|=(1<<pinorder);break;
						}
						break;
		}
	}
	return Ok;
}

DIO_Error_t GetPinValue(u8 Port,u8 PinOrder,u8 *value)
{
	//check input port in valid range or no
	if(Port>portD)
	{
		return invalid_port;
	}
	//check input pinorder in valid range or no
	else if(PinOrder>Pin7)
	{
		return invalid_pin;
	}
	else
	{
		//finding desired port to be configured
		switch(Port)
		{
		case portA:
			//getting value of desired pin
			*value = GET_BIT(PINA,PinOrder);break;
		case portB:
			*value = GET_BIT(PINB,PinOrder);break;
		case portC:
			*value = GET_BIT(PINC,PinOrder);break;
		case portD:
			*value = GET_BIT(PIND,PinOrder);break;
		}
	}

	return Ok;
}

DIO_Error_t togglePin(u8 Port,u8 PinOrder)
{
	//check input port in valid range or no
	if(Port>portD)
	{
		return invalid_port;
	}
	//check input pinorder in valid range or no
	else if(PinOrder>Pin7)
	{
		return invalid_pin;
	}
	else
	{
		//finding desired port to be configured
		switch(Port)
		{
		case portA:
			//toggling input pin
			TOG_BIT(PORTA,PinOrder);break;
		case portB:
			TOG_BIT(PORTB,PinOrder);break;
		case portC:
			TOG_BIT(PORTC,PinOrder);break;
		case portD:
			TOG_BIT(PORTD,PinOrder);break;
		}
	}
	return Ok;
}
