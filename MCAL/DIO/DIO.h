#ifndef DIO_H_
#define DIO_H_

#define PORTA  *((volatile u8*)0x3B)
#define PORTB  *((volatile u8*)0x38)
#define PORTC  *((volatile u8*)0x35)
#define PORTD  *((volatile u8*)0x32)

#define DDRA  *((volatile u8*)0x3A)
#define DDRB  *((volatile u8*)0x37)
#define DDRC  *((volatile u8*)0x34)
#define DDRD  *((volatile u8*)0x31)

#define PINA  *((volatile u8*)0x39)
#define PINB  *((volatile u8*)0x36)
#define PINC  *((volatile u8*)0x33)
#define PIND  *((volatile u8*)0x30)

#define Pin0 				0
#define Pin1				1
#define Pin2				2
#define Pin3				3
#define Pin4				4
#define Pin5				5
#define Pin6				6
#define Pin7				7


#define portA				0
#define portB				1
#define portC				2
#define portD				3

#define port_Output			0xff

#define Low					0
#define High				1

#define Input				0
#define Output				1

typedef enum
{
	Ok,
	invalid_port,
	invalid_pin,
	invalid_value

}DIO_Error_t;


DIO_Error_t SetPinDirection(u8 port ,u8 pinorder,u8 pinvalue);
DIO_Error_t setportvalue(u8 Port ,u8 portvalue);
DIO_Error_t SetPinValue(u8 port,u8 pinorder,u8 pinvalue);
DIO_Error_t setportdirection(u8 port, u8 portvalue);
DIO_Error_t togglePin(u8 Port,u8 PinOrder);
DIO_Error_t GetPinValue(u8 Port,u8 PinOrder,u8 *value);


#endif /* DIO_H_ */







