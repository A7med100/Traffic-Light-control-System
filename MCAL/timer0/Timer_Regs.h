/*
 * Timer_Regs.h
 *
 *  Created on: Oct 9, 2022
 *      Author: USER
 */

#ifndef TIMER_REGS_H_
#define TIMER_REGS_H_

#define  Timer_TCCR0					*((volatile u8*)0x53)
#define  Timer_TCNT0					*((volatile u8*)0x52)
#define  Timer_OCR0						*((volatile u8*)0x5C)
#define  Timer_TIMSK					*((volatile u8*)0x59)
#define  Timer_TIFR 					*((volatile u8*)0x58)

#endif /* TIMER_REGS_H_ */
