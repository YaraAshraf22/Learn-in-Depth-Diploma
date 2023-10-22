/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"

/*check number is positive or negative*/

void main ()
{
	float num=0;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%g", &num);

	if (num > 0)
	{
		printf("%0.2f is positive.", num);
	}
	else if (num < 0)
	{
		printf("%0.2f is negative.", num);
	}
	else
	{
		printf("You entered a zero.");
	}
}
