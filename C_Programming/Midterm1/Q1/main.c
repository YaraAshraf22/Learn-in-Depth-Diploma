/*
 * main.c
 *
 *  Created on: Nov 18, 2023
 *      Author: HP
 */

/*C function to take a number and sum all digits*/

#include "stdio.h"

int sum_digits(int num);
int main ()
{
	int num, sum;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	sum = sum_digits(num);
	printf("input: %d -> output: %d", num, sum);
	return 0;
}

int sum_digits(int num)
{
	static int sum;
	int remainder =0;

	remainder=num%10;
	sum+=remainder;
	if(num!=0)
		sum_digits(num/10);
	return sum;
}



#include "string.h"

/*void num_to_sum(char num[], int size);

int main ()
{
	char num[10];
	int size;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%s",num);
	size=strlen(num);
	num_to_sum(num, size);
	return 0;
}

void num_to_sum(char num[], int size)
{
	int sum=0, i=0;
	int arr[10];
	while(i<size)
	{
		arr[i]=num[i]-48;
		sum+=arr[i];
		i++;
	}
	printf("input: %s -> output: %d", num, sum);
}*/


