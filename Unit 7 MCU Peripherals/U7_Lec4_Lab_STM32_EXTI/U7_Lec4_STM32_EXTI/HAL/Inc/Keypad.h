/*
 * Keypad.h
 *
 * Created: 8/11/2024 11:05:16 PM
 *  Author: HP
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"


#define KEYPAD_GPIO GPIOB

//Rows
#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
//Columns
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

void KEYPAD_INIT();
char KEYPAD_GET_CHAR();

#endif /* KEYPAD_H_ */
