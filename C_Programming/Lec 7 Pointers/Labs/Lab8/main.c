/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: HP
 */

#include "stdio.h"
/*
 * void pointer
 */
int main ()
{
	int x=5;
	double y=10.3;
	void*p;

	p=&x;
	*(int*)p=8;
	printf("x = %d\r\n",x);

	p=&y;
	*(double*)p=3.3;
	printf("y = %lf\r\n",y);

	return 0;
}

