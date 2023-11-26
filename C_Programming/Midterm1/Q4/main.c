/*
 * main.c
 *
 *  Created on: Nov 21, 2023
 *      Author: HP
 */

#include "stdio.h"

/*c function to reverse digits in a number*/
void reverse (int num);

int main ()
{

	int num;
	printf("enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	reverse (num);

	return 0;
}


void reverse (int num)
{
	static int digits[10], i;
	int j;
	digits[i]=num%10;
	i++;

	if(num/10!=0)
	{
		reverse(num/10);
	}
	else
	{
		for (j=0;j<i;j++)
		{
			printf("%d",digits[j]);
		}
	}


}
