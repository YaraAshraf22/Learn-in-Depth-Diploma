/*
 * main.c
 *
 *  Created on: Nov 18, 2023
 *      Author: HP
 */

/* c function to print all prime numbers between two numbers?*/

#include "stdio.h"

void prime(int num1, int num2);

int main ()
{
	int num1, num2;
	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &num1, &num2);

	prime( num1, num2);
	return 0;
}

void prime(int num1, int num2)
{
	int i,j,k=0, not_prime;
	int prime[20]={0};
	for (i=num1+1;i<num2;i++)
	{
		not_prime=0;
		for (j=2;j<i;j++)
		{
			if(i%j==0)
			{
				not_prime=1;
				break;
			}

		}
		if (not_prime==0)
		{
			prime[k]=i;
			k++;
		}
	}

	printf("input: n1=%d, n2=%d -> output: ", num1, num2);
	for(i=0;i<k;i++)
	{
		printf("%d ", prime[i]);
	}
}
