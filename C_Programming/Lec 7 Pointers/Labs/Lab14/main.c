/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: HP
 */
/*
 * testing const with ptr
 * case1: error read only loc
 * case2: no error, ptr to int
 * case3: error const ptr, cannot change addr
 */
#include "stdio.h"
int main ()
{
	/*
	int a =10;
	const int* ptr=&a;
	 *ptr=30;*/

	const int a=10;
	int* ptr=&a;
	 *ptr=30;

	/*int a=10, b=5;
	int* const ptr=&a;
	ptr=&b;
	*ptr=30;*/

	printf("%d", *ptr);
	return 0;
}
