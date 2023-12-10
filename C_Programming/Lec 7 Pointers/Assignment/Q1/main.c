/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: HP
 */
/*
 * Write a program in C to demonstrate how to handle the pointers
in the program.
 */

#include "stdio.h"
int main ()
{
	int m=29;
	printf("Address of m : 0x%x\n", (unsigned int)&m);
	printf("Value of m: %d\r\n",m);

	int* ab=&m;
	printf("Now ab is assigned with the address of m\n");
	printf("Address of pointer ab: 0x%x\n", (unsigned int)ab);
	printf("Content of pointer ab: %d\r\n",*ab);

	m=34;
	printf("Now value of m assigned to 34\n");
	printf("Address of pointer ab: 0x%x\n", (unsigned int)ab);
	printf("Content of pointer ab: %d\r\n",*ab);

	*ab=7;
	printf("Now pointer variable is assigned with value 7\n");
	printf("Address of m : 0x%x\n", (unsigned int)&m);
	printf("Value of m: %d\n",m);
	return 0;
}

