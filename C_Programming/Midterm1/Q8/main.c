/*
 * main.c
 *
 *  Created on: Nov 22, 2023
 *      Author: HP
 */
/*c function to take an array and reverse its elements*/

#include "stdio.h"

void reverse (int arr[], int n);
int main()
{
	int n, i;
	int arr[10];
	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	printf("Enter array: ");
	fflush(stdin); fflush(stdout);
	for (i=0; i<n;i++)
	{
		scanf("%d,",&arr[i]);
	}
	reverse(arr,n);
	return 0;
}

void reverse (int arr[], int n)
{
	int j;
	printf("Reverse array: ");
	for (j=n-1;j>=0;j--)
	{
		printf("%d",arr[j]);
		if(j!=0)
			printf(", ");
	}
}


