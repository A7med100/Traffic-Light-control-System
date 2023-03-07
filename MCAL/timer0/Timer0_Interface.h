/*
 * Timer_Interface.h
 *
 *  Created on: Oct 9, 2022
 *      Author: USER
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/*-----------Clock Select------------*/
#define NO_Clock_Source					0
#define NO_Prescaler					1
#define Prescaler_8						2
#define Prescaler_64					3
#define Prescaler_256					4
#define Prescaler_1024					5

/*------------timer WGM modes-------------*/
#define  normal_Mode					0
#define  PWM_Mode						1
#define  CTC_Mode						2
#define  fast_PWM_Mode					3

u8 Timer_Init(u8 wgm,u8 clk);
void Timer_SetCallBack(void (*ptrfunc)(void));
void Timer_CompareValue(u8 value);
u8 Timer_CompareMatchEvent(u8 mode);
void Timer_preload(u8 preload);
void timer0_delay(u16 Overflows);


#endif /* TIMER0_INTERFACE_H_ */
