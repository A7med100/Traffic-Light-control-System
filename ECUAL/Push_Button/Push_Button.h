/*
 * Push_Button.h
 *
 *  Created on: Feb 6, 2023
 *      Author: USER
 */

#ifndef ECUAL_PUSH_BUTTON_PUSH_BUTTON_H_
#define ECUAL_PUSH_BUTTON_PUSH_BUTTON_H_

void Button_init(u8 buttonPort,u8 buttonPin);
void Button_read(u8 buttonPort,u8 buttonPin,u8 *value);

#endif /* ECUAL_PUSH_BUTTON_PUSH_BUTTON_H_ */
