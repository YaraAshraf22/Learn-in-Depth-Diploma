/*
 * main.c
 *
 *  Created on: Dec 16, 2023
 *      Author: HP
 *
 */

#include "stdio.h"

int addnum(int a, int b)
{
	return a+b;
}
int subnum(int a, int b)
{
	return a-b;
}
int mulnum(int a, int b)
{
	return a*b;
}


int main ()
{
	int choice, num1, num2, result;
	int (* ptr[])(int,int)={addnum,subnum,mulnum};

	printf("Enter choice 0-Add, 1-Subtract, 2-Multiply: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &choice);

	printf("Enter num1: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num1);

	printf("Enter num2: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num2);

	result=(* ptr[choice])(num1,num2);
	printf("Result= %d", result);
	return 0;
}
/*
int main ()
{
	int choice, num1, num2, result;
	printf("Enter choice 0-Add, 1-Subtract, 2-Multiply: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &choice);

	printf("Enter num1: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num1);

	printf("Enter num2: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num2);

	switch(choice)
	{
	case 0:
	{
		result=addnum(num1,num2);
		break;
	}
	case 1:
	{
		result=subnum(num1,num2);
		break;
	}
	case 2:
	{
		result=mulnum(num1,num2);
		break;
	}
	}

	printf("Result= %d", result);
	return 0;
}
 */
