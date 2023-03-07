/*
 * Led.h
 *
 *  Created on: Feb 6, 2023
 *      Author: USER
 */

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"


#define green_led			Pin0
#define yellow_led			Pin1
#define red_led				Pin2
#define cars_port			portA

#define  pedestrian_port	portB

#define Low					0
#define High				1

#define Ok					0
#define N_Ok				1

u8 Led_init(u8 Led_port,u8 Led_pin);
u8 Led_on(u8 Led_port,u8 Led_pin);
u8 Led_off(u8 Led_port,u8 Led_pin);
u8 Led_Blink(u8 Led_port,u8 Led_pin,u16 overflows,s16 blink_time_ms,u8 *blinkStop);
u8 _2Led_Blink(u8 Led1_port,u8 Led1_pin,u8 Led2_port,u8 Led2_pin,u16 overflows,s16 blink_time_ms);

#endif /* ECUAL_LED_LED_H_ */
