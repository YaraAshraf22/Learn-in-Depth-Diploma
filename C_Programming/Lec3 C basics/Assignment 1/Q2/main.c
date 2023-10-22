/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"

void main ()
{
	int x;
	printf("Enter a integer:");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	printf("You entered:%d", x);

}
