/*
 * main.c
 *
 *  Created on: Dec 11, 2023
 *      Author: HP
 */
/*
 * Write a program in C to show a pointer to an array which contents
are pointer to structure.
 */

#include "stdio.h"

struct Semployee{
	char m_name[30];
	int m_ID;
};
int main ()
{
	struct Semployee employee= {"Alex",1002};
	struct Semployee *p_struct= &employee;

	struct Semployee* arr[5];

	/*ptr to array of 5 ptr to struct*/
	struct Semployee *(*p_arr)[5];

	return 0;
}
