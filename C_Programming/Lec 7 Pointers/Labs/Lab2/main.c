/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: HP
 */

#include "stdio.h"

int main ()
{
	int* px= 0x0;
	char* py = 0x0;
	long long* pz = 0x0;
	printf("0x%X, 0x%X, 0x%X \n", px,py,pz);
	px++;
	py++;
	pz++;

	printf("0x%X, 0x%X, 0x%X \n", px,py,pz);
	return 0;
}
