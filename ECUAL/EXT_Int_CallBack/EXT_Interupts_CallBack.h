/*
 * CallBack.h
 *
 *  Created on: Feb 9, 2023
 *      Author: USER
 */

#ifndef ECUAL_EXT_INT_CALLBACK_EXT_INTERUPTS_CALLBACK_H_
#define ECUAL_EXT_INT_CALLBACK_EXT_INTERUPTS_CALLBACK_H_

#define enable 			1
#define disable			2

#define Ok				0
#define N_Ok			1
u8 EXT_INT_Control(u8 state);
void pass_callBack(void (*callbak)(void));

#endif /* ECUAL_EXT_INT_CALLBACK_EXT_INTERUPTS_CALLBACK_H_ */
