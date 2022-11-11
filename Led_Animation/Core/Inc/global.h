/*
 * global.h
 *
 *  Created on: Nov 1, 2022
 *      Author: HP PV
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
//#include "global.h"

#define MODE1				1
#define AUTO_RED1_GREEN2	2
#define AUTO_RED1_YELLOW2	3
#define AUTO_GREEN1_RED2	4
#define AUTO_YELLOW1_RED2	5

#define MODE2				10
#define RED_INCREASE		11

#define MODE3				20
#define YELLOW_INCREASE		21

#define MODE4				30
#define GREEN_INCREASE		31

extern int status;

extern int RedCounter;
extern int YellowCounter;
extern int GreenCounter;

extern int hour;
extern int minute;
extern int second;

//update7SEG
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void display7SEG(int num);

void update7SEG(int index);

extern int count1;
extern int count2;

void updateClockBuffer();

#endif /* INC_GLOBAL_H_ */
