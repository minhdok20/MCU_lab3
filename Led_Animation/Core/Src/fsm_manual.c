/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2022
 *      Author: HP PV
 */

#include "fsm_manual.h"

int RedCounter = 5;
int YellowCounter = 2;
int GreenCounter = 3;

void fsm_manual_run(){
	switch(status){
	case MODE2:
		clearTimer2();
		clearTimer3();
		clearTimer4();
		//tat cac led xanh va vang
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 1);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 1);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);

		//cac led do nhap nhay
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
			HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
			setTimer1(500);
		}

		//scan 4 thanh led 7 doan
		if(timer5_flag == 1) {
			led_buffer[0] = 0;
			led_buffer[1] = 2;
			led_buffer[2] = RedCounter/10;
			led_buffer[3] = RedCounter%10;
			update7SEG(index_led);
			setTimer5(125);
		}

		//chuyen sang mode tiep theo neu nhan nut 1
		if(isButton1Pressed() == 1){
			status = MODE3;
		}

		//chuyen sang mode tang gia tri led do neu nhan nut 2, dong thoi tang gia tri RedCounter
		if(isButton2Pressed() == 1){
			status = RED_INCREASE;
			if(RedCounter >= 99) {
				RedCounter = 1;
			}
			else
				RedCounter++;
		}

		//khong lam gi neu nhan nut 3
		if(isButton3Pressed() == 1){};
		break;
	case RED_INCREASE:
		//cac led do nhap nhay
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
			HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
			setTimer1(500);
		}

		//scan 4 thanh led 7 doan
		if(timer5_flag == 1) {
			led_buffer[2] = RedCounter/10;
			led_buffer[3] = RedCounter%10;
			update7SEG(index_led);
			setTimer5(125);
		}

		//tang gia tri bien RedCounter neu nhan nut 2
		if(isButton2Pressed() == 1){
			if(RedCounter >= 99) {
				RedCounter = 1;
			}
			else
				RedCounter++;
		}

		//khong lam gi neu nhan nut 1
		if(isButton1Pressed() == 1){};

		//neu nhan nut 3, kiem tra gia tri RedCounter > YellowCounter. Thoa dk, GreenCounter thay doi theo va tro ve MODE2. Nguoc lai, khong lam gi
		if(isButton3Pressed() == 1) {
			if(RedCounter > YellowCounter) {
				GreenCounter = RedCounter - YellowCounter;
				status = MODE2;
			}
		}
		break;
	case MODE3:
		clearTimer2();
		clearTimer3();
		clearTimer4();
		//tat cac led xanh va do
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, 1);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, 1);

		//cac led vang nhap nhay
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
			HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
			setTimer1(500);
		}

		//scan 4 thanh led 7 doan
		if(timer5_flag == 1) {
			led_buffer[0] = 0;
			led_buffer[1] = 3;
			led_buffer[2] = YellowCounter/10;
			led_buffer[3] = YellowCounter%10;
			update7SEG(index_led);
			setTimer5(125);
		}

		//chuyen sang mode tiep theo neu nhan nut 1
		if(isButton1Pressed() == 1){
			status = MODE4;
		}

		//chuyen sang mode tang gia tri led vang neu nhan nut 2, dong thoi tang gia tri YellowCounter
		if(isButton2Pressed() == 1){
			status = YELLOW_INCREASE;
			if(YellowCounter >= 5)
				YellowCounter = 1;
			else
				YellowCounter++;
		}

		//khong lam gi neu nhan nut 3
		if(isButton3Pressed() == 1){};
		break;
	case YELLOW_INCREASE:
		//cac led vang nhap nhay
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
			HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
			setTimer1(500);
		}

		//scan 4 thanh led 7 doan
		if(timer5_flag == 1) {
			led_buffer[2] = YellowCounter/10;
			led_buffer[3] = YellowCounter%10;
			update7SEG(index_led);
			setTimer5(125);
		}

		//tang gia tri bien YellowCounter neu nhan nut 2
		if(isButton2Pressed() == 1){
			if(YellowCounter >= 5)
				YellowCounter = 1;
			else
				YellowCounter++;
		}

		//khong lam gi neu nhan nut 1
		if(isButton1Pressed() == 1){};

		//neu nhan nut 3, kiem tra gia tri RedCounter > YellowCounter. Thoa dk, GreenCounter thay doi theo va tro ve MODE3. Nguoc lai, khong lam gi
		if(isButton3Pressed() == 1) {
			if(RedCounter > YellowCounter) {
				GreenCounter = RedCounter - YellowCounter;
				status = MODE3;
			}
		}
		break;
	case MODE4:
		clearTimer2();
		clearTimer3();
		clearTimer4();
		//tat cac led vang va do
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, 1);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, 1);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, 1);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, 1);

		//cac led xanh nhap nhay
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
			HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
			setTimer1(500);
		}

		//scan 4 thanh led 7 doan
		if(timer5_flag == 1) {
			led_buffer[0] = 0;
			led_buffer[1] = 4;
			led_buffer[2] = GreenCounter/10;
			led_buffer[3] = GreenCounter%10;
			update7SEG(index_led);
			setTimer5(125);
		}

		//chuyen sang mode auto neu nhan nut 1, dong thoi reset lai bien dem cua mode auto
		if(isButton1Pressed() == 1){
			status = MODE1;
			clearTimer2();
			clearTimer3();
			clearTimer4();
			count1 = 0;
			count2 = 0;
			timer2_flag = 1;
			timer3_flag = 1;
			timer4_flag = 1;
		}

		//tang gia tri bien GreenCounter neu nhan nut 2
		if(isButton2Pressed() == 1){
			status = GREEN_INCREASE;
			if(GreenCounter >= 99)
				GreenCounter = 1;
			else
				GreenCounter++;
		}

		//khong lam gi neu nhan nut 3
		if(isButton3Pressed() == 1){};
		break;
	case GREEN_INCREASE:
		//cac led xanh nhap nhay
		if(timer1_flag == 1){
			HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
			HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
			setTimer1(500);
		}

		//scan 4 thanh led 7 doan
		if(timer5_flag == 1) {
			led_buffer[2] = GreenCounter/10;
			led_buffer[3] = GreenCounter%10;
			update7SEG(index_led);
			setTimer5(125);
		}

		//tang gia tri bien GreenCounter neu nhan nut 2
		if(isButton2Pressed() == 1){
			if(GreenCounter >= 99)
				GreenCounter = 1;
			else
				GreenCounter++;
		}

		//khong lam gi neu nhan nut 1
		if(isButton1Pressed() == 1){};

		//neu nhan nut 3, kiem tra gia tri GreenCounter + YellowCounter < 100 && GreenCounter > YellowCounter.
		//Thoa dk, RedCounter thay doi theo va tro ve MODE4. Nguoc lai, khong lam gi
		if(isButton3Pressed() == 1) {
			if(GreenCounter + YellowCounter < 100 && GreenCounter > YellowCounter) {
				RedCounter = GreenCounter + YellowCounter;
				status = MODE4;
			}
		}
		break;
	default:
		break;
	}
}
