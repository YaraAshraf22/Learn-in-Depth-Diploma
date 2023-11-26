/*
 * main.c
 *
 *  Created on: Nov 21, 2023
 *      Author: HP
 */

#include "stdio.h"
/* c function to count number of 1s in a binary number*/

int count_binary(int num);

int main ()
{
	int num, number_of_ones;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	number_of_ones = count_binary(num);
	printf("Number of 1's in %d is: %d", num, number_of_ones);
	return 0;
}

int count_binary(int num)
{
	int n_ones=0, i=0;
	for (i=0;i<31;i++)
	{
		if(((num>>i)&1) == 1)
			n_ones++;
	}
	return n_ones;
}
