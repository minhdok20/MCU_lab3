/*
 * button.c
 *
 *  Created on: Oct 31, 2022
 *      Author: HP PV
 */


#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0Button1 = NORMAL_STATE;
int KeyReg1Button1 = NORMAL_STATE;
int KeyReg2Button1 = NORMAL_STATE;
int KeyReg3Button1 = NORMAL_STATE;

int KeyReg0Button2 = NORMAL_STATE;
int KeyReg1Button2 = NORMAL_STATE;
int KeyReg2Button2 = NORMAL_STATE;
int KeyReg3Button2 = NORMAL_STATE;

int KeyReg0Button3 = NORMAL_STATE;
int KeyReg1Button3 = NORMAL_STATE;
int KeyReg2Button3 = NORMAL_STATE;
int KeyReg3Button3 = NORMAL_STATE;

int TimeOutForKeyPress1 = 200;
int TimeOutForKeyPress2 = 50;
int TimeOutForKeyPress3 = 200;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyPocess1(){
	button1_flag = 1;
}

void subKeyPocess2(){
	button2_flag = 1;
}

void subKeyPocess3(){
	button3_flag = 1;
}

void getKeyInput1(){
	KeyReg0Button1 = KeyReg1Button1;
	KeyReg1Button1 = KeyReg2Button1;
	KeyReg2Button1 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if((KeyReg1Button1 == KeyReg0Button1) && (KeyReg1Button1 == KeyReg2Button1)){
		if(KeyReg2Button1 != KeyReg3Button1){
			KeyReg3Button1 = KeyReg2Button1;
			if(KeyReg2Button1 == PRESSED_STATE){
				TimeOutForKeyPress1 = 200;
				subKeyPocess1();
			}
		} else{
			TimeOutForKeyPress1--;
			if(TimeOutForKeyPress1 == 0){
				KeyReg3Button1 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput2(){
	KeyReg0Button2 = KeyReg1Button2;
	KeyReg1Button2 = KeyReg2Button2;
	KeyReg2Button2 = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
	if((KeyReg1Button2 == KeyReg0Button2) && (KeyReg1Button2 == KeyReg2Button2)){
		if(KeyReg2Button2 != KeyReg3Button2){
			KeyReg3Button2 = KeyReg2Button2;
			if(KeyReg2Button2 == PRESSED_STATE){
				TimeOutForKeyPress2 = 50;
				subKeyPocess2();
			}
		} else{
			TimeOutForKeyPress2--;
			if(TimeOutForKeyPress2 == 0){
				KeyReg3Button2 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput3(){
	KeyReg0Button3 = KeyReg1Button3;
	KeyReg1Button3 = KeyReg2Button3;
	KeyReg2Button3 = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
	if((KeyReg1Button3 == KeyReg0Button3) && (KeyReg1Button3 == KeyReg2Button3)){
		if(KeyReg2Button3 != KeyReg3Button3){
			KeyReg3Button3 = KeyReg2Button3;
			if(KeyReg2Button3 == PRESSED_STATE){
				TimeOutForKeyPress3 = 200;
				subKeyPocess3();
			}
		} else{
			TimeOutForKeyPress3--;
			if(TimeOutForKeyPress3 == 0){
				KeyReg3Button3 = NORMAL_STATE;
			}
		}
	}
}
