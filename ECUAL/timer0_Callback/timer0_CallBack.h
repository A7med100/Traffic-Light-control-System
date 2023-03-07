/*
 * CallBack.h
 *
 *  Created on: Feb 13, 2023
 *      Author: USER
 */

#ifndef ECUAL_TIMER0_CALLBACK_TIMER0_CALLBACK_H_
#define ECUAL_TIMER0_CALLBACK_TIMER0_CALLBACK_H_

#define NO_Clock_Source					0
#define NO_Prescaler					1
#define Prescaler_8						2
#define Prescaler_64					3
#define Prescaler_256					4
#define Prescaler_1024					5

void timer0_passCallback(void (*notific)(void));
void timer0_Start(u8 prescaler ,u8 compareValue);
void delay(u16 overflows);

#endif /* ECUAL_TIMER0_CALLBACK_TIMER0_CALLBACK_H_ */
