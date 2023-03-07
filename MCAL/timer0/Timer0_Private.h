/*
 * Timer0_Private.h
 *
 *  Created on: Nov 7, 2022
 *      Author: USER
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_






/*------------CTC Modes-----------------*/
#define Toggle_OC0					1
#define Set_OC0						2
#define Clear_OC0					3

/*-------------Timer counter control register PINS-----------------*/
#define  TCCR_FOC						7
#define  TCCR_WGM1						6
#define  TCCR_COM1						5
#define  TCCR_COM2						4
#define  TCCR_WGM0						3
#define  TCCR_CS2						2
#define  TCCR_CS1						1
#define  TCCR_CS0						0

/*--------------Timer interrupt pins-------------*/
#define  TIMSK_OCIE0 					1
#define  TIMSK_TOIE0					0


#define  TIFR_OCF0 					1
#define  TIFR_TOF0					0

#endif /* TIMER0_PRIVATE_H_ */
