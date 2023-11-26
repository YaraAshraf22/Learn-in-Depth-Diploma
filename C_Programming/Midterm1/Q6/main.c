/*
 * main.c
 *
 *  Created on: Nov 21, 2023
 *      Author: HP
 */

/*c function to return unique number in array with one loop*/

#include "stdio.h"

int get_unique(int arr[], int n);
int main ()
{
	int arr[10]={0}, i, n, unique_num;
	printf("Enter number of array elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	printf("Enter an array of numbers: ");
	fflush(stdin); fflush(stdout);
	for(i=0; i<n; i++)
	{
		scanf("%d,",&arr[i]);
	}

/*	printf("array of numbers: ");
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}*/
	unique_num = get_unique(arr, n);
	printf("Unique number is: %d", unique_num);

	return 0;
}

int get_unique(int arr[], int n)
{
	int i, n_occurrence=0;
	static int j;
	for (i=0; i<n; i++)
	{

		if(arr[j]==arr[i])
		{
			n_occurrence++;
		}

	}

	if (n_occurrence==1)
	{
		goto end;
	}
	else
	{
		j++;
		get_unique(arr, n);
	}

	end:
	return arr[j];

}
