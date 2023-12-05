/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: HP
 */

/*Pointer casting*/

#include "stdio.h"

int main ()
{
	long long int rand_address = 0x00000000FFFFAAAA;
	printf("rand_addr = %llx \n", rand_address);

	/*seen as a number so compiler o/p warning type mismatch*/
	char* addr1 = 0x00000000FFFFAAAA;
	printf("P_addr1 = %llx \n", addr1);

	char* addr2 = (char*)0x00000000FFFFAAAA;
	printf("P_addr1 = %llx \n", addr2);
	return 0;
}
