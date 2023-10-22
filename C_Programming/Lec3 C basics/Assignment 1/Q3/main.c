/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include <stdio.h>

void main ()
{
	int x,y,sum;
	printf("Enter two integers:");
	fflush(stdin); fflush(stdout);
	scanf("%d \n %d", &x, &y);
	sum= x+y;
	printf("Sum:%d", sum);

}
