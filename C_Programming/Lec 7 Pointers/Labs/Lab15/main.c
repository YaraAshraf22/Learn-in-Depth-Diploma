/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: HP
 */

#include "stdio.h"

int main ()
{
	char *pmessage ="now is the time";
	printf("%s\n", pmessage);

	pmessage++;
	printf("%s\n", pmessage);

	int x = sizeof (pmessage);
	printf("%d\n", x);

	/**pmessage ='S';
	printf("%s\n", pmessage);*/

	return 0;
}
