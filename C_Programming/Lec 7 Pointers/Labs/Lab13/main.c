/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: HP
 */

#include "stdio.h"

int main ()
{
	unsigned char x[10]={1,2,3,4,5,6,7,8,9,10};
	unsigned int* y= (unsigned int*)x;
	unsigned short* z=(unsigned short*)x;
	unsigned long long* d= (unsigned long long*)x;


	printf("*y=0x%x \n", *y);
	y++;

	printf("*y=0x%x \n", *y);
	y++;

	printf("*z=0x%x \n", *z);
	z++;

	printf("*z=0x%x \n", *z);
	z++;

	printf("*d=0x%x \n", *d);
	d++;

	printf("*d=0x%x \n", *d);
	d++;
	return 0;
}

