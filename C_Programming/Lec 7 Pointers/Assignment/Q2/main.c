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
	char arr[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
			'O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	int i;
	char* p=arr;

	for(i=0;i<26;i++,p++)
	{
		printf("%c\t", *p);
	}

	return 0;
}
