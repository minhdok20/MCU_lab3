/*
 * software_timer.h
 *
 *  Created on: Oct 31, 2022
 *      Author: HP PV
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag; //blinky
extern int timer2_flag; //auto count
extern int timer3_flag;	//auto 7seg scan
extern int timer4_flag;	//count down
extern int timer5_flag; //blinky 7seg scan
extern int timer6_flag; //button long press

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);

void clearTimer1();
void clearTimer2();
void clearTimer3();
void clearTimer4();
void clearTimer5();
void clearTimer6();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
