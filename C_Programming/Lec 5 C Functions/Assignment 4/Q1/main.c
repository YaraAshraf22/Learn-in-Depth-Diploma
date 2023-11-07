/*
 * main.c
 *
 *  Created on: Nov 7, 2023
 *      Author: HP
 */

#include "stdio.h"

/*prime num between two intervals using user-defined function*/

void calcprime(int n1, int n2);

int main ()
{
	int n1,n2;
	printf("enter two numbers between 1 and 100: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&n1, &n2);

	printf("prime numbers between %d and %d are: ", n1, n2);
	calcprime(n1,n2);

	return 0;
}


void calcprime(int n1, int n2)
{
	int i,j,k=0;
	int arr[100]={0};


	for (i=n1+1;i<n2;i++)
	{
		for (j=2;j<i;j++)
		{
			if (i%j==0)
			{
				break;
			}
		}
		if (j==i)
		{
			arr[k]=i;
			k++;
		}

	}

	for (i=0;i<k;i++)
		printf("%d ", arr[i]);

}
