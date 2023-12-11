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
	int i;
	struct Semployee employee[3]={{"John", 1001},{"Alex", 1002},{"Taylor", 1003}};

	struct Semployee* arr[3]={&employee[0],&employee[1],&employee[2]};

	/*ptr to array of 5 ptr to struct*/
	struct Semployee *(*p_arr)[]=&arr;

	for(i=0;i<3;i++)
	{
		printf("Employee [%d]:\n",i+1);
		printf("Name: %s\n",(*p_arr)[i]->m_name);
		printf("ID: %d\n\r",(*p_arr)[i]->m_ID);
	}
	return 0;
}
