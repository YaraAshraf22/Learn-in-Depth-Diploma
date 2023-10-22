/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

# include "stdio.h"

/*Check if number is even or odd*/
void main ()
{
	int x;
	printf("Enter an integer you want to check:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if (x%2 == 0)
	{
		printf("%d is even", x);
	}
	else
	{
		printf("%d is odd", x);
	}
}
