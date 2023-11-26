/*
 * main.c
 *
 *  Created on: Nov 23, 2023
 *      Author: HP
 */

#include "stdio.h"
/*c function to count max number of ones between two zeros*/

void max_of_ones(int x);
int main ()
{

	int x;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	max_of_ones(x);

	return 0;
}

void max_of_ones(int x)
{
	int i,j=0,m1,m2;
	m1=m2=0;
	int arr[10]={0};
	for(i=0;i<32;i++)
	{
		if((x>>i)&1)
		{
			m1++;
		}
		else if ((((x>>i)&1)==0) && (m1!=0))
		{
			arr[j++]=m1;
			m1=0;
		}
	}

	m2=arr[0];
	for(i=1;i<j;i++)
	{
		if(arr[i]>=m2)
		{
			m2=arr[i];
		}
	}
	printf("Max no. of ones is: %d",m2);
}
