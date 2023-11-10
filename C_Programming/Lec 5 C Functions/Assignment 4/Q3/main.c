/*
 * main.c
 *
 *  Created on: Nov 9, 2023
 *      Author: HP
 */

/*Reverse a sentence using recursion*/

#include "stdio.h"
#include "string.h"

char text[50], rtext[50];
void reverse (int length);
int main()
{

	int length=0;
	printf("enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(text);
	length=strlen(text);
	reverse(length);
	return 0;
}

void reverse (int length)
{
	static int i=0;
	rtext[i]=text[length-1];
	length--;
	i++;
	if (length>=0)
	{
		reverse (length);
	}
	else
	printf("Reverse is: %s",rtext);
}

