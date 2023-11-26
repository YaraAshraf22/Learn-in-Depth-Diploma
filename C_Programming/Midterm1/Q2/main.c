/*
 * main.c
 *
 *  Created on: Nov 18, 2023
 *      Author: HP
 */

/*c function to take integer number and calculate its square root*/

#include "stdio.h"
#include "math.h"

double square_root(int num);
int main ()
{
	int num;
	double sq;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	sq = square_root(num);
	printf("input: %d -> output: %0.3lf", num, sq);
	return 0;
}

double square_root(int num)
{
	double sq;
	sq=pow(num,0.5);
	return sq;
}
