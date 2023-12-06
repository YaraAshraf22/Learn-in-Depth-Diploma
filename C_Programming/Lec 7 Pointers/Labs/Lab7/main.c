/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: HP
 */

#include "stdio.h"

void Sort (int values[], int nValues)
{
	int i, j, temp;
	for (i=0;i<nValues-1;i++)
	{
		for(j=i+1;j<nValues;j++)
		{
			if(values[i]>values[j])
			{
				temp=values[j];
				values[j]=values[i];
				values[i]=temp;
			}
		}
	}
}

void Sort_p (int* values, int nValues)
{
	int i, j, temp;
	for (i=0;i<nValues-1;i++)
	{
		for(j=i+1;j<nValues;j++)
		{
			if(values[i]>values[j])
			{
				temp=values[j];
				values[j]=values[i];
				values[i]=temp;
			}
		}
	}
}
int main ()
{
	int i, values[5] ={89,73,28,94,32};
/*	Sort(values,5);*/
	Sort_p(values,5);

	for(i=0; i<5; i++)
	{
		printf("%d\r\n", values[i]);
	}
	return 0;
}
