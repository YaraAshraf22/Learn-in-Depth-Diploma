/*
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: HP
 */

#include "stdio.h"

int main ()
{
	printf("Current time: %s\n", __TIME__);
	printf("Current date: %s\n", __DATE__);
	printf("Current line: %d\n", __LINE__);
	printf("Current file: %s\n", __FILE__);
	printf("Return non 0 if ANSI C: %d\n", __STDC__);
	return 0;

}
