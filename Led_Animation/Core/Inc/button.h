/*
 * button.h
 *
 *  Created on: Oct 31, 2022
 *      Author: HP PV
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

void getKeyInput1();
void getKeyInput2();
void getKeyInput3();

#endif /* INC_BUTTON_H_ */
