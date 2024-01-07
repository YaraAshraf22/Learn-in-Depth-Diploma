/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stdint.h"

typedef volatile unsigned int vint32_t;

#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR		*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH		*(volatile uint32_t*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t*)(PORTA_BASE + 0x0C)

typedef union {
	vint32_t all_fields;
	struct {
		vint32_t reserved:13;
		vint32_t pin13:1;

	}pin;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0C);
int main (void)
{

	RCC_APB2ENR |= 1<<2; //enable RCC CLR to GPIOA, bit 2
	GPIOA_CRH &=0xFF0FFFFF; //clear 20 to 24
	GPIOA_CRH |=0x00200000; //write 2
	while (1)
	{

		/*GPIOA_ODR |=1<<13; 		//set bit 13
		for(int i=0;i<5000;i++);
		GPIOA_ODR &=~(1<<13);	//clear bit 13
		for(int i=0;i<5000;i++);*/

		R_ODR->pin.pin13=1;
		for(int i=0;i<5000;i++);
		R_ODR->pin.pin13=0;
		for(int i=0;i<5000;i++);

	}

	return 0;
}
