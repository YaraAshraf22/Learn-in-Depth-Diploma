/*
 * main.c
 *
 *  Created on: Dec 15, 2023
 *      Author: HP
 *
 *      Array of ptr to struct
 */

#include "stdio.h"

#define n_struct 2

struct mystruct{
	int age;
	char name[20];
};

int main ()
{
	int i;
	struct mystruct Smystruct[n_struct]={{24,"Mohamed"},{40,"Gamal"}};
	struct mystruct *P_struct[n_struct];

	for (i=0;i<n_struct;i++)
	{
		P_struct[i]=&Smystruct[i];
	}

	for (i=0;i<n_struct;i++)
	{
		printf("%d %s\n", P_struct[i]->age,  P_struct[i]->name);

	}
	return 0;
}

