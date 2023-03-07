/*
 * INT_Registers.h
 *
 *  Created on: Oct 3, 2022
 *      Author: USER
 */

#ifndef INT_REGISTERS_H_
#define INT_REGISTERS_H_

#define MCUCR  		 			*((volatile u8*)0x55)
#define MCUCSR  	 			*((volatile u8*)0x54)
#define GICR 		 			*((volatile u8*)0x5B)
#define GIFR 		 			*((volatile u8*)0x5A)


#endif /* INT_REGISTERS_H_ */
