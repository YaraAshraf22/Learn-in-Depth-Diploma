/*
 * FIFO.c
 *
 *  Created on: Mar 5, 2024
 *      Author: HP
 */

#include "FIFO.h"

//FIFO APIs
FIFO_status FIFO_init (FIFO_Buf_t* FIFO_buf, element_type* buf,unsigned int length)
{
	//Check if not valid
	if (buf == NULL)
		return FIFO_NULL;

	//Initiate the buffer
	FIFO_buf->base = buf;
	FIFO_buf->head = buf;
	FIFO_buf->tail = buf;
	FIFO_buf->length = length;
	FIFO_buf->count = 0;
	return FIFO_no_error;

}
FIFO_status FIFO_Enqueue (FIFO_Buf_t* FIFO_buf, element_type item)
{
	//check if valid
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
		return FIFO_NULL;

	//check if full
	if(FIFO_buf->count == FIFO_buf->length)
		return FIFO_full;

	//Add the item
	*(FIFO_buf->head) = item;
	FIFO_buf->count++;

	//For Circular FIFO
	if(FIFO_buf->head == (FIFO_buf->base + (FIFO_buf->length)*sizeof(element_type)))
		FIFO_buf->head = FIFO_buf->base;
	else
		FIFO_buf->head++;

	return FIFO_no_error;

}
FIFO_status FIFO_Dequeue (FIFO_Buf_t* FIFO_buf, element_type* item)
{
	//check if valid
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
		return FIFO_NULL;

	//check if empty
	if(FIFO_buf->count == 0)
		return FIFO_empty;

	//Remove the item
	*(item) = *(FIFO_buf->tail);
	FIFO_buf->count--;

	//Circular FIFO
	if(FIFO_buf->tail == (FIFO_buf->base + (FIFO_buf->length)*sizeof(element_type)))
		FIFO_buf->tail = FIFO_buf->base;
	else
		FIFO_buf->tail++;
	return FIFO_no_error;
}
FIFO_status FIFO_is_full (FIFO_Buf_t* FIFO_buf)
{
	//check if valid
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
		return FIFO_NULL;

	//check if full
	if(FIFO_buf->count == FIFO_buf->length)
		return FIFO_full;

	return FIFO_no_error;
}
void FIFO_print (FIFO_Buf_t* FIFO_buf)
{
	element_type* temp;
	int i;

	//if empty
	if(FIFO_buf->count == 0)
		printf("FIFO is empty \n");
	else
	{
		temp = FIFO_buf->tail;
		printf("\n ======= FIFO print ======= \n");
		for(i=0; i<FIFO_buf->count; i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
		printf("============= \n");
	}
}

