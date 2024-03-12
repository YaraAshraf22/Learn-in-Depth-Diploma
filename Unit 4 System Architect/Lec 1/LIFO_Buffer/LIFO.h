/*
 * LIFO.h
 *
 *  Created on: Mar 5, 2024
 *      Author: HP
 */

#ifndef LIFO_H_
#define LIFO_H_

//LIFO Buffer data types
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//APIs
LIFO_status LIFO_init (LIFO_Buf_t* LIFO_Buf, unsigned int* base,unsigned int length);
LIFO_status LIFO_Add_item (LIFO_Buf_t* LIFO_Buf, unsigned int item);
LIFO_status LIFO_Get_item (LIFO_Buf_t* LIFO_Buf, unsigned int* item);


#endif /* LIFO_H_ */
