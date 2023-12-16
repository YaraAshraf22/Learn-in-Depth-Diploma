/*
 * main.c
 *
 *  Created on: Dec 15, 2023
 *      Author: HP
 *
 *  Pointer to function as argument to sort an array
 */

#include "stdio.h"

void swap (int *a, int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
int compare (int a, int b)
{
	if(a>b)
		return 1;
	return -1;
}
void sort_array (int* arr, int size, int (*compare)(int,int))
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(compare(arr[i],arr[j])>0)
			{
				swap(&arr[i],&arr[j]);
			}
		}
	}
}
int main ()
{

	int arr[]={5,4,7,1,9,15,0};
	int size, i;
	size=sizeof(arr)/sizeof(*arr);
	sort_array(arr,size,compare);
	for(i=0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
