/*
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: HP
 */
/*find area of a circle, passing arguments to macros*/

#include "stdio.h"
#include "math.h"

#define pi 3.141592654
int main ()
{
	int r;
	double area;
	printf("Enter the radius: ");
	fflush(stdin); fflush (stdout);
	scanf("%d", &r);
	area=pi*pow(r,2);

	printf("Area= %0.2lf", area);
	return 0;
}
