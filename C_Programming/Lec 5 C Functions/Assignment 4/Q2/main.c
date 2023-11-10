/*
 * main.c
 *
 *  Created on: Nov 9, 2023
 *      Author: HP
 */

#include "stdio.h"

/*calculate factorial using recursion*/

int factorial (int x);

int main ()
{
	int x, fact;
	printf("enter a positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	fact = factorial(x);
	printf("factorial of %d = %d", x, fact);
	return 0;
}

int factorial (int x)
{
	static int f=1;
	f*=x;
	x--;
	if (x>0)
	{
		factorial(x);
	}
	return f;
}
