/*
 * main.c
 *
 *  Created on: Mar 5, 2024
 *      Author: HP
 */


#include "FIFO.h"


void main ()
{
	FIFO_Buf_t FIFO_UART;
	element_type i=0, temp;

	if(FIFO_init(&FIFO_UART, UART_Buffer ,5) == FIFO_no_error)
	{
		printf("FIFO init is done. \n");
	}

	for (i=0; i<7 ; i++)
	{
		printf("FIFO enqueue (%x) \n", i);
		if(FIFO_Enqueue(&FIFO_UART,i) == FIFO_no_error)
			printf("FIFO Enqueue Done. \n");
		else
			printf("FIFO Enqueue Failed. \n");
	}

	FIFO_print(&FIFO_UART);
	if(FIFO_Dequeue(&FIFO_UART,&temp) == FIFO_no_error)
		printf("FIFO Dequeue %x --- Done. \n", temp);
	if(FIFO_Dequeue(&FIFO_UART,&temp) == FIFO_no_error)
		printf("FIFO Dequeue %x --- Done. \n", temp);

	FIFO_print(&FIFO_UART);

}
