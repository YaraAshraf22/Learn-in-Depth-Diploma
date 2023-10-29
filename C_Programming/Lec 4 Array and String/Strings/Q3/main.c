/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */


#include "stdio.h"
#include "string.h"

/*Reverse string without library function*/

int main ()
{
	char text[20], reverse[20];
	int i, length=0;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(text);

	length = strlen(text);

	for(i=0; i<length; i++)
	{
		reverse[i]=text[length-1-i];
	}
	reverse[i]='\0';
	printf("Reverse string is: %s", reverse);
	return 0;
}
