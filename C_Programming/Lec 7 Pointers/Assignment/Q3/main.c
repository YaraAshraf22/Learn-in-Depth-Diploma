/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: HP
 */
/*
 * Write a program in C to print a string in reverse using a pointer
 */

#include "stdio.h"
#include "string.h"

int main ()
{
	char text[50], *p;
	int length, i;
	printf("Input a string: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	length=strlen(text);
	p= &text[length-1];

	printf("Reverse string: ");
	for (i=length-1; i>=0; i--,p--)
	{
		printf("%c",*p);
	}
	return 0;
}

