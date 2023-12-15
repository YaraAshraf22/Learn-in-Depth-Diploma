/*
 * main.c
 *
 *  Created on: Dec 15, 2023
 *      Author: HP
 */

#include "stdio.h"
/*
 * using pointer to pass array
 */

#define M 3
#define N 3

/*
void print (int arr[][N])
{
	int i,j;
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%d ",arr[i][j]);
		}
	}
}
int main ()
{
	int arr[][N]={{1,2,3},{4,5,6},{7,8,9}};
	print(arr);
	return 0;
}
 */

/*
void print (int (*arr)[][N])
{
	int i,j;
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%d ",(*arr)[i][j]);
		}
	}
}
int main ()
{
	int arr[][N]={{1,2,3},{4,5,6},{7,8,9}};
	print(&arr);
	return 0;
}
 */


void print (int (*arr)[])
{
	int i;
	for (i=0;i<M*N;i++)
	{
		printf("%d ",(*arr)[i]);
	}
}
int main ()
{
	int arr[][N]={{1,2,3},{4,5,6},{7,8,9}};
	print(arr);
	return 0;
}



/*
void print (int *arr)
{
	int i;
	for (i=0;i<M*N;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main ()
{
	int arr[][N]={{1,2,3},{4,5,6},{7,8,9}};
	print(&arr[0][0]);
	return 0;
}
*/
