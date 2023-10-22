/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "stdio.h"
int main (void)
{
	char z;
	printf("Enter a character:");
	fflush(stdin); fflush(stdout);
	scanf("%c", &z);
	printf("ASCII value of %c= %d",z,z );
	return 0;
}
