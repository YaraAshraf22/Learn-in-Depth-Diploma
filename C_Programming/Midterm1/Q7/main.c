/*
 * main.c
 *
 *  Created on: Nov 21, 2023
 *      Author: HP
 */
/*c function to sum numbers from 1 to 100(without loop)*/

#include "stdio.h"

void sum (void);
int main ()
{

	printf("Sum of numbers from 1 to 100:\n");
	sum();
	return 0;
}

void sum (void)
{
	static int i=1;
	static int s;

	s+=(i++);

	if (i<=100)
	{
		sum();
	}
	else
		printf("%d", s);

}
