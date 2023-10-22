/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"

/*Check if a character is an alphabet or not*/

void main()
{
	char c=0;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &c);

	/*Upper case ASCII 65-90
	  Lower case ASCII 97-122*/

	if ((c>=65 && c<=90) || (c>=97 && c<=122))
	{
		printf("%c is an alphabet", c);
	}
	else
	{
		printf("%c is not an alphabet", c);
	}
}
