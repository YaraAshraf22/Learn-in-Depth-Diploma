/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */

#include "stdio.h"

/*Find factorial of a number*/
void main ()
{
	int factorial=1, i, n;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	if (n>0)
	{
		for (i=1;i<=n;i++)
			{
				factorial *= i;
			}
		printf("Factorial = %d", factorial);
	}
	else if (n<0)
	{
		printf("Error! Factorial of negative number doesn't exist.");
	}
	else
	{
		printf("Factorial = 1");
	}
}
