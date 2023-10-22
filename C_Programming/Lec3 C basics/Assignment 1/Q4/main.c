/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */


#include "stdio.h"

int main (void)
{
	float x,y,product;
	printf("Enter two numbers:");
	fflush(stdin); fflush(stdout);
	scanf("%f \n %f", &x, &y);
	product= x*y;
	printf("product:%f", product);
	return 0;
}
