/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */

#include "stdio.h"
#include "string.h"

/*Find length of a string manually*/
int main ()
{
	int i, length=0;
	char text[50];

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	for(i=0;i<50;i++)
	{
		if(text[i]=='\0')
			break;
		else
			length++;
	}

	printf("Length of string: %d", length);
	return 0;
}
