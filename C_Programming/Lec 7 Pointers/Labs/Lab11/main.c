/*
 * main.c
 *
 *  Created on: Dec 7, 2023
 *      Author: HP
 */
#include "stdio.h"

void (* PFun)();

void printf_diploma()
{
	printf("Learn in depth \n");
}

int main ()
{
	printf_diploma();
	PFun = printf_diploma;
	PFun();
	return 0;
}

