/*
 * main.c
 *
 *  Created on: Nov 9, 2023
 *      Author: HP
 */

#include "stdio.h"

/*Calculate power of number using recursion*/

int power (int n, int m);

int main()
{
	int n,m,p;
	printf("enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	printf("enter a power number (positive): ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&m);

	p = power(n,m);
	printf("%d^%d=%d", n, m, p);

	return 0;
}

int power (int n, int m)
{
	static int p=1;
	p*=n;
	m--;
	if(m>0)
	{
		power (n, m);
	}
	return p;
}
