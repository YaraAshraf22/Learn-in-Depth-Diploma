/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"

void main ()
{
	float a, b, c;
	printf("Enter value of a:");
	fflush(stdin); fflush(stdout);
	scanf("%f", &a);

	printf("Enter value of b:");
	fflush(stdin); fflush(stdout);
	scanf("%f", &b);

	c=a;
	a=b;
	b=c;
	printf("\nAfter swapping, value of a = %g", a);
	printf("\nAfter swapping, value of b = %g", b);
}
