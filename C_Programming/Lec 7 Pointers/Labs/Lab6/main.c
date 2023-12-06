/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: HP
 */

#include "stdio.h"

struct Sdate
{
	int m_day;
	int m_month;
	int m_year;
};

struct Sstudent
{
	char m_name[256];
	char m_description[256];
	struct Sdate m_birthdate;
	double m_degrees[10];
	double m_totaldegrees;
};

struct Sstudent SlowUpdateTotalDegree (struct Sstudent student)
{
	student.m_totaldegrees=0;
	int i;
	for (i=0;i<10;i++)
	{
		student.m_totaldegrees += student.m_degrees[i];
	}
	return student;
}

void FastUpdateTotalDegree (struct Sstudent* P_student)
{
	P_student->m_totaldegrees=0;
	int i;
	for (i=0;i<10;i++)
	{
		P_student->m_totaldegrees += P_student->m_degrees[i];
	}
}

int main ()
{
	struct Sstudent S = {
			"Ahmed Said", "Ahmed's Description", {22,12,1990},
			{88,98,88,92,98,87,66,94,87,99}
	};

	/*pass by value*/
	S=SlowUpdateTotalDegree (S);
	printf("total degrees of %s is %.2lf (%.2lf\%)\r\n",S.m_name,S.m_totaldegrees,(100.0*S.m_totaldegrees/1000.0));

	/*pass by reference with pointers*/
	FastUpdateTotalDegree (&S);
	printf("total degrees of %s is %lf\r\n",S.m_name,S.m_totaldegrees);

	return 0;
}
