/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */

#include "stdio.h"

/*take n of elements from user and store in an array and calculate average of the numbers*/

int main ()
{
	int i,n;
	float average=0, sum=0;
	float array[20];

	printf("Enter the number of data between 1 and 20 ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	while (n<1 || n>20)
	{
		printf("Invalid input\n");
		printf("Enter the number of data between 1 and 20 ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&n);
	}

	for (i=0;i<n;i++)
	{
		printf("%d. Enter number: ", i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&array[i]);
		sum+=array[i];
	}
	average = sum/n;
	printf("Average = %g", average);


	return 0;
}
