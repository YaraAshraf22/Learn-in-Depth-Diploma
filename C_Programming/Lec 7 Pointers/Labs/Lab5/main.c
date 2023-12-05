/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: HP
 */

#include "stdio.h"

struct SPerson
{
	char m_name[18];
	int m_ID;
	char m_age;
	short m_salary;
	double m_weight;

};
int main ()
{
	struct SPerson manager =
	{"Mohamed Hady", 162, 39, 3000, 79.5};

	struct SPerson employees[] = {
			{"mohamed said", 163, 30, 1500, 81.0},
			{"ahmed salah", 164, 25,1200, 91.0},
			{"safa fayez", 165, 28, 1400, 65.0}
	};

	int i;
	struct SPerson* p;
	p= &manager;

	printf("manager: %s, %d, %d, %d, %lf\r\n", p->m_name, p->m_ID,
			p->m_age, p->m_salary, p->m_weight);

	p->m_salary=4000;
	printf("manager: %s, %d, %d, %d, %lf\r\n", manager.m_name, manager.m_ID,
			manager.m_age, manager.m_salary, manager.m_weight);

	p= employees;
	for(i=0; i<sizeof(employees)/sizeof(struct SPerson);i++,p++)
	{
		printf("employee %d: %s, %d, %d, %d, %lf\r\n",i+1,p->m_name, p->m_ID,
					p->m_age, p->m_salary, p->m_weight);
	}
	return 0;
}
