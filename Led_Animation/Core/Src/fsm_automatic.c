/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2022
 *      Author: HP PV
 */


#include "fsm_automatic.h"

int status;

void fsm_automatic_run(){
	if(timer4_flag == 1){
		updateClockBuffer();
		setTimer4(1000);
	}

	if(timer3_flag == 1){
		update7SEG(index_led);
		setTimer3(125);
	}
	switch(status){
	case MODE1:
		//clearTimer5();
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 1);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 1);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);

		//ngay lap tuc chuyen sang trang thai AUTO_RED1_GREEN2
		status = AUTO_RED1_GREEN2;
		setTimer2(GreenCounter*1000);
		break;
	case AUTO_RED1_GREEN2:
		//clearTimer5();
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 0);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 1);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 1);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 0);

		//buoc vao trang thai AUTO_RED1_YELLOW2
		if(timer2_flag == 1){
			status = AUTO_RED1_YELLOW2;
			setTimer2(YellowCounter*1000);
		}

		//buoc vao trang thai MODE2 neu nhan nut 1
		if(isButton1Pressed() == 1){
			status = MODE2;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		}
		break;
	case AUTO_RED1_YELLOW2:
		//clearTimer5();
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 0);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 1);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 0);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);

		//buoc vao trang thai AUTO_GREEN1_RED2
		if(timer2_flag == 1){
			status = AUTO_GREEN1_RED2;
			setTimer2(GreenCounter*1000);
		}

		//buoc vao trang thai MODE2 neu nhan nut 1
		if(isButton1Pressed() == 1){
			status = MODE2;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		}
		break;
	case AUTO_GREEN1_RED2:
		//clearTimer5();
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 1);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 0);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 0);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 1);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);

		//buoc vao trang thai AUTO_YELLOW1_RED2
		if(timer2_flag == 1){
			status = AUTO_YELLOW1_RED2;
			setTimer2(YellowCounter*1000);
		}

		//buoc vao trang thai MODE2 neu nhan nut 1
		if(isButton1Pressed() == 1){
			status = MODE2;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		}
		break;
	case AUTO_YELLOW1_RED2:
		//clearTimer5();
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 0);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 0);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 1);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);

		//buoc vao trang thai AUTO_RED1_GREEN2
		if(timer2_flag == 1){
			status = AUTO_RED1_GREEN2;
			setTimer2(GreenCounter*1000);
		}

		//buoc vao trang thai MODE2 neu nhan nut 1
		if(isButton1Pressed() == 1){
			status = MODE2;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		}
		break;
	default:
		break;
	}
}
