/*
 * Test.h
 *
 *  Created on: Feb 10, 2023
 *      Author: USER
 */

#ifndef TEST_TEST_H_
#define TEST_TEST_H_

void SetPinDirection_test(u8 port);
void SetPinValue_test(u8 port);
void togglePin_test(u8 port);
void EXT_Int_test(u8 int_num);

/* El-Main Testing Code
 * SetPinDirection_test(portA);
SetPinDirection_test(portB);
SetPinDirection_test(4);

SetPinValue_test(portA);
SetPinValue_test(portB);
SetPinValue_test(4);

togglePin_test(portA);
togglePin_test(portB);
togglePin_test(4);

EXT_Int_test(INT0);
EXT_Int_test(INT1);
EXT_Int_test(1);
 */


#endif /* TEST_TEST_H_ */
