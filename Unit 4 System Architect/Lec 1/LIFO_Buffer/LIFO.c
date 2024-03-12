/*
 * LIFO.c
 *
 *  Created on: Mar 5, 2024
 *      Author: HP
 */

#include "LIFO.h"
#include "stdio.h"

//APIs
LIFO_status LIFO_init (LIFO_Buf_t* LIFO_Buf, unsigned int* base,unsigned int length)
{
	//If Dynamic allocation is used, check if buffer sent if valid (exits) or not (null)
	if(base == NULL)
	{
		return LIFO_Null;
	}
	else
	{
		LIFO_Buf->base = base;
		LIFO_Buf->head = base;
		LIFO_Buf->length = length;
		LIFO_Buf->count = 0;
		return LIFO_no_error;
	}
}
LIFO_status LIFO_Add_item (LIFO_Buf_t* LIFO_Buf, unsigned int item)
{
	//Check if buffer exists
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_Null;

	//Check if buffer is full
	if(LIFO_Buf->count == LIFO_Buf->length)
		return LIFO_full;

	//Add the item
	*(LIFO_Buf->head) = item;
	LIFO_Buf->head++;
	LIFO_Buf->count++;
	return LIFO_no_error;

}
LIFO_status LIFO_Get_item (LIFO_Buf_t* LIFO_Buf, unsigned int* item)
{
	//Check if buffer exists
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_Null;

	//Check if buffer is empty
	if(LIFO_Buf->count == 0)
		return LIFO_empty;

	//Get the item
	LIFO_Buf->head--;
	*item = *(LIFO_Buf->head);
	LIFO_Buf->count--;
	return LIFO_no_error;
}


