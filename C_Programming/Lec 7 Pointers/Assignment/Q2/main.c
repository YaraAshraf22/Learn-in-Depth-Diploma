/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: HP
 */
/*
 * Write a program in C to print all the alphabets using a pointer.
 */
#include "stdio.h"

int main()
{
	char arr[26];

	int i;
	char* p=arr;

	for(i=0;i<26;i++,p++)
	{
		*p='A'+i;
	}

	p=arr;
	for(i=0;i<26;i++,p++)
	{
		printf("%c ", *p);
	}

	return 0;
}
