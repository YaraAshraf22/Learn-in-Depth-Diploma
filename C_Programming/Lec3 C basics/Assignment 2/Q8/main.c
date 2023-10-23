/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */

#include "stdio.h"

/*Calculator*/
void main ()
{
	char operator;
	float a, b, c;
	int x;
	printf("Enter an operator either + or - or * or / : ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &operator);
	printf("Enter two operands: ");
	fflush(stdin); fflush(stdout);
	scanf("%g\n%g", &a, &b);

	switch (operator)
	{
	case '+':
	{
		c=a+b;
		printf("%g + %g = %0.1f", a, b, c);
	}
	break;
	case '-':
	{
		c=a-b;
		printf("%g - %g = %0.1f", a, b, c);
	}
	break;
	case '*':
	{
		c=a*b;
		printf("%g * %g = %0.1f", a, b, c);
	}
	break;
	case '/':
	{
		c=a/b;
		printf("%g / %g = %0.1f", a, b, c);
	}
	break;
	default:
		printf("Invalid operator");
		break;
	}

}
