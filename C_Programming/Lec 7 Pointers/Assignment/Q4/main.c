/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: HP
 */
/*
 * Write a program in C to print the elements of an array in reverse
order.
 */
#include "stdio.h"

int main ()
{
	int num, arr[15], i;
	int *p = arr;

	printf("Input a number of elements to store in array (max 15): ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("\nInput %d elements to store in array: \n", num);

	for(i=0;i<num;i++)
	{
		printf("Element %d: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&p[i]);
	}


	printf("\nElements of array in reverse order: \n");

	for(i=num-1;i>=0;i--)
	{
		printf("Element %d: %d\n", i+1, p[i]);
	}


	return 0;
}
