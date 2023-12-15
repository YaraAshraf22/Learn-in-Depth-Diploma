/*
 * main.c
 *
 *  Created on: Dec 15, 2023
 *      Author: HP
 *
 *      Return 2D array using:
 *      a] return ptr to int
		b] structure
		c] ptr to struct
 */

#include "stdio.h"
#define M 2
#define N 2

/*int *func()
{
	static int a[M][N]={{1,2},{3,4}};
	return &a[0][0];
}
int main ()
{
	int *p=func();
	int i;
	for (i=0;i<M*N;i++)
	{
		printf("%d ",p[i]);
	}
	return 0;
}*/


/*int *func()
{
	static int a[M][N]={{1,2},{3,4}};
	return &a[0][0];
}
int main ()
{
	int *p=func();
	int i;
	for (i=0;i<M*N;i++)
	{
		printf("%d ",p[i]);
	}
	return 0;
}*/


/*
struct mystruct
{
	int a[M][N];
};

struct mystruct retArr()
{
	struct mystruct Sarray = {
			{
					{1,2},
					{3,4}
			}
	};

	return Sarray;
}
int main ()
{
	int i,j;
	struct mystruct Smystruct = retArr();
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%d ",Smystruct.a[i][j]);
		}
	}
	return 0;
}
 */


struct mystruct
{
	int a[M][N];
};

struct mystruct Sarray = {
		{
			{1,2},
			{3,4}
		}
};

int main ()
{
	int i,j;
	struct mystruct *P_mystruct = &Sarray;
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%d ",P_mystruct->a[i][j]);
		}
	}
	return 0;
}

