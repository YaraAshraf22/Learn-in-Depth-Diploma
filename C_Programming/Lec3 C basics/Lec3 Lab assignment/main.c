/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"

void main ()
{
	int i,k,n=0;
	for (i=0;i<=9;i++)
	{
		for(k=0;k<=9;k++)
		{
			printf("%d\t",k+n);
			if ((k+n)==9)
				break;
		}
		n++;
		printf("\n");
	}
}

