/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"

/*Find largest of 3 numbers*/
void main()
{
	float a,b,c;
	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f\n%f\n%f", &a, &b, &c);

	if(a>b && a>c)
	{
		printf("Largest number = %g", a);
	}
	else if(b>a && b>c)
	{
		printf("Largest number = %g", b);
	}
	else
	{
		printf("Largest number = %g", c);
	}
}

