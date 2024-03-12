/*
 * main.c
 *
 *  Created on: Mar 5, 2024
 *      Author: HP
 */

#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"

#define width 5
unsigned int buffer1[width]; //in .bss

int main ()
{
	unsigned int i, temp;
	LIFO_Buf_t UART_LIFO, I2C_FIFO;

	//Static Allocation
	LIFO_init(&UART_LIFO, buffer1, width);

	//Dynamic Allocation
	unsigned int* buffer2 = (unsigned int*)malloc(width*sizeof(unsigned int));
	LIFO_init(&I2C_FIFO, buffer2, width);

	//Push
	printf("UART_LIFO Push \n");
	for(i=0; i<width ; i++)
	{
		if(LIFO_Add_item(&UART_LIFO,i) == LIFO_no_error)
			printf("UART_LIFO add: %d \n", i);
	}

	//Pop
	printf("\nUART_LIFO Pop \n");
	for(i=0; i<width ; i++)
	{
		if(LIFO_Get_item(&UART_LIFO,&temp) == LIFO_no_error)
			printf("UART_LIFO get: %d \n", temp);
	}

	return 0;
}

