/*
 * INT_interface.h
 *
 *  Created on: Oct 3, 2022
 *      Author: USER
 */

#ifndef INT_INTERFACE_H_
#define INT_INTERFACE_H_

 #define INT1					7
 #define INT0					6
 #define INT2					5
/*INTERUPT Sense Signal*/
#define  Low_Level				1
#define  Logical_Change			2
#define  Falling_Edge			3
#define  Rising_Edge			4

u8 INT_ControlSense(u8 intNum,u8 sense);
u8 INT_Enable(u8 intNum);
u8 INT_Disable(u8 intNum);
void INT_SetCallBack(void (*callback)(void));


#define Ok					0
#define N_Ok				1


#endif /* INT_INTERFACE_H_ */
