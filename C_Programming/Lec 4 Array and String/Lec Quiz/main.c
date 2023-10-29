/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */


#include "stdio.h"
#include "string.h"

int main ()
{
	int x[1000];
	int i, n=0;
	for (i=0;i<1000;i++)
	{
		x[i]=rand();
	}

	for (i=1;i<999;i++)
	{
		if((x[i]>x[i-1]) && (x[i]>x[i+1]))
		n++;
	}

	printf("number of values that satisfy the condition is %d",n);
	return 0;
}
