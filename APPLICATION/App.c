#include "../Utilities/STD_TYPES.h"
#include "../Utilities/BIT_MATH.h"
#include "../ECUAL/LED/Led.h"
#include "../ECUAL/timer0_Callback/timer0_CallBack.h"
#include "../ECUAL/EXT_Int_CallBack/EXT_Interupts_CallBack.h"
#include "App.h"
//#include "util/delay.h"
//void pressed(void);

u8 pedstrain_button = Low;

void app_init(void)
{
	//Initializing used LEDs
	Led_init(cars_port,red_led);
	Led_init(cars_port,green_led);
	Led_init(cars_port,yellow_led);
	Led_init(pedestrian_port,red_led);
	Led_init(pedestrian_port,green_led);
	Led_init(pedestrian_port,yellow_led);

	timer0_Start(Prescaler_256,250);//
}

void app_start(void)
{
	u8 state;
	//enabling external interrupt
	EXT_INT_Control(enable);

	// desired actions to be handled on pressing
	void notific(void)
	{
		//setting pedestrian button
		pedstrain_button = High;
		//disabling external interrupt to avoid repetitive pressing
		EXT_INT_Control(disable);
	}
	//passing desired actions to ISR
	pass_callBack(&notific);

	//Normal Mode routine
	while (pedstrain_button == Low)
	{
		//state flag green
		state = green_led;
		//turn green led on
		Led_on(cars_port, green_led);
		delay_int(&pedstrain_button,5000);
		Led_off(cars_port, green_led);
		Led_off(pedestrian_port, red_led);
		//check if pedestrian button pressed
		if (pedstrain_button == High)
			break;

		//state flag yellow
		state = yellow_led;
		//blink yellow led
		Led_Blink(cars_port, yellow_led, 44, 5000,&pedstrain_button);
		if (pedstrain_button == High)
			break;

		Led_on(cars_port, red_led);
		//state flag Red
		state = red_led;
		delay_int(&pedstrain_button,5000);
		Led_off(cars_port, red_led);
		if (pedstrain_button == High)
			break;

		state = yellow_led;
		Led_Blink(cars_port, yellow_led, 44, 5000,&pedstrain_button);
		if (pedstrain_button == High)
			break;
	}

	//check flag state
	if (state != red_led)
	{
		//If pressed when red led is off,
		//  the pedestrian Red LED will be on  for five seconds,????
		Led_on(pedestrian_port, red_led);
		//_delay_ms(5000);
		delay(625);
		Led_off(pedestrian_port, red_led);

		//then both Yellow LEDs start to blink
		_2Led_Blink(pedestrian_port, yellow_led, cars_port, yellow_led, 44, 5000);
	}

	//pedestrian's Green LED and the cars' Red LEDs will be on for five seconds,
	Led_on(pedestrian_port, green_led);
	Led_on(cars_port, red_led);
	//_delay_ms(5000);
	delay(625);
	//the cars' Red LED will be off .
	Led_off(cars_port, red_led);

	//both Yellow LEDs start blinking
	_2Led_Blink(pedestrian_port, yellow_led, cars_port, yellow_led, 44, 5000);

	//pedestrian Green LED will be off
	Led_off(pedestrian_port, green_led);
	// and both the pedestrian Red LED and the cars' Green LED will be on
	Led_on(pedestrian_port, red_led);//
	//Led_on(cars_port, green_led);
	pedstrain_button = Low;
}

void delay_int(u8* breaker,u16 delayTime_ms)
{
	while(*breaker != interrup&&delayTime_ms>0)
	{
		delay(62);
		delayTime_ms-=500;
	}
}

