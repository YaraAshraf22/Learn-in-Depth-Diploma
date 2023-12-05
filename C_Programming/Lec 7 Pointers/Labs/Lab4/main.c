/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: HP
 */

#include "stdio.h"

struct Sdataset
{
	unsigned char data1;
	unsigned int data2;
	unsigned char data3;
	unsigned short data4;
} data;

void print_memory_range (char*base, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%p \t %x \n",base, (unsigned char)*base);
		base++;
	}
}
int main ()
{
	data.data1=0x11;
	data.data2=0xFFFFEEEE;
	data.data3=0x22;
	data.data4=0xABCD;

	print_memory_range(&data,sizeof(data));

	char* p=&data;
	printf("p+8=%x \n", (unsigned char)*(p+8));

	struct Sdataset* Pstruct = &data;
	printf("p+8=%x \n", (unsigned char)Pstruct->data3);

	return 0;
}

