/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: HP
 */

#include "stdio.h"
/*
 * universal compare using void pointers
 */

int compare(void*value1, void*value2, int type)
{
	int r;
	switch(type)
	{
	case 1:
	{
		if(*(int*)value1==*(int*)value2)
			r=0;
		else if (*(int*)value1>*(int*)value2)
			r=1;
		else
			r=-1;
		break;
	}
	case 2:
	{
		if(*(float*)value1==*(float*)value2)
			r=0;
		else if (*(float*)value1>*(float*)value2)
			r=1;
		else
			r=-1;
		break;
	}
	}
	return r;
}
int main ()
{
	int x1=5, x2=6, x3=5;
	float y1=10.3, y2=8.3, y3=11.9;

	printf("compare result of x1 and x2 is %d\n",compare(&x1,&x2,1));
	printf("compare result of x1 and x3 is %d\n",compare(&x1,&x3,1));
	printf("compare result of y1 and y2 is %d\n",compare(&y1,&y2,2));
	printf("compare result of y1 and y3 is %d\n",compare(&y1,&y3,2));
	return 0;
}

