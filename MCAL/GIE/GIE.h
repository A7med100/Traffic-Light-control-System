/*
 * GIE.h
 *
 *  Created on: Oct 21, 2022
 *      Author: USER
 */

#ifndef GIE_H_
#define GIE_H_


/*Global Interrupt Enable*/
#define SREG 					*((volatile u8*)0x5F)
#define GIE_Pin					7


void GIEnable(void);
void GIDisable(void);

#endif /* GIE_H_ */
