/*
 * FIFO.h
 *
 *  Created on: Mar 5, 2024
 *      Author: HP
 */

#include "stdio.h"
#include "stdint.h"

//User configuration
//Select element type
#define element_type uint8_t

//Buffer
#define width 5
element_type UART_Buffer[width];

//FIFO data types
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_NULL,
	FIFO_full,
	FIFO_empty
}FIFO_status;

//FIFO APIs
FIFO_status FIFO_init (FIFO_Buf_t* FIFO_buf, element_type* buf,unsigned int length);
FIFO_status FIFO_Enqueue (FIFO_Buf_t* FIFO_buf, element_type item);
FIFO_status FIFO_Dequeue (FIFO_Buf_t* FIFO_buf, element_type* item);
FIFO_status FIFO_is_full (FIFO_Buf_t* FIFO_buf);
void FIFO_print (FIFO_Buf_t* FIFO_buf);

