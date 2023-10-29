/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */

/*Find transpose of a matrix*/

#include "stdio.h"
int main()
{
	int m,n,r,c;
	int a[10][10],b[10][10];

	printf("Enter rows and column of matrix (max is 10):  ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&r,&c);

	while(r>10 || r<0)
	{
		printf("Invalid row input\n");
		printf("Enter number of rows between 1 and 10: ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&r);
	}

	while (c>10 || c<0)
	{
		printf("Invalid column input\n");
		printf("Enter number of columns between 1 and 10: ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&c);

	}

	printf("Enter elements of matrix: \n");

	for(m=0;m<r;m++)
	{
		for(n=0;n<c;n++)
		{
			printf("Enter element a%d%d: ",m+1,n+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&a[m][n]);
		}
	}

	printf("\nEntered matrix: \n");
	for(m=0;m<r;m++)
	{
		for(n=0;n<c;n++)
		{
			printf("%d\t",a[m][n]);
		}
		printf("\r\n");
	}

	printf("\nTranspose of matrix: \n");
	for(m=0;m<c;m++)
	{
		for(n=0;n<r;n++)
		{
			b[m][n]=a[n][m];
			printf("%d\t",b[m][n]);
		}
		printf("\r\n");
	}
	return 0;
}
