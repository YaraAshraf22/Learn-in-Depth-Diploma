/*
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: HP
 */

#include "stdio.h"
#include "string.h"

/* Sort Employee Ages with Structures older to youngest using nested structures*/

struct Sdate
{
	int m_Day;
	int m_Month;
	int m_Year;

};

struct SEmployee
{
	char m_Name[50];
	struct Sdate m_BirthDate;
	struct Sdate m_GraduationDate;
	int m_Salary;
};

int main ()
{
	struct SEmployee employees[100], tempEmployee;
	int count = 0,i,j;
	char firstName[50], secondName[50];


	do
	{
		printf("Enter Employee first name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", firstName);

		printf("Enter Employee second name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", secondName);

		strcpy(employees[count].m_Name,firstName);
		strcat(employees[count].m_Name," ");
		strcat(employees[count].m_Name,secondName);

		printf("Enter Employee Birth Date (day/month/year), example (23/3/1970): ");
		fflush(stdin); fflush(stdout);
		scanf("%d/%d/%d",
				&employees[count].m_BirthDate.m_Day,
				&employees[count].m_BirthDate.m_Month,
				&employees[count].m_BirthDate.m_Year
		);

		printf("Enter Employee Graduation Date (day/month/year), example (16/7/2020): ");
		fflush(stdin); fflush(stdout);
		scanf("%d/%d/%d",
				&employees[count].m_GraduationDate.m_Day,
				&employees[count].m_GraduationDate.m_Month,
				&employees[count].m_GraduationDate.m_Year
		);

		printf("Enter Employee salary: ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &employees[count].m_Salary);

		count++;

	}while(count<3);

	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(
					employees[i].m_BirthDate.m_Year>employees[j].m_BirthDate.m_Year ||
					(employees[i].m_BirthDate.m_Year==employees[j].m_BirthDate.m_Year && employees[i].m_BirthDate.m_Month>employees[j].m_BirthDate.m_Month) ||
					(employees[i].m_BirthDate.m_Year==employees[j].m_BirthDate.m_Year && employees[i].m_BirthDate.m_Month==employees[j].m_BirthDate.m_Month &&
							employees[i].m_BirthDate.m_Day==employees[j].m_BirthDate.m_Day)
			)
			{
				tempEmployee = employees[i];
				employees[i] = employees[j];
				employees[j] = tempEmployee;

			}

		}
	}

	for(i=0;i<count;i++)
	{
		printf("name: %s, Birth Date: %d/%d/%d, Graduation Date: %d/%d/%d, Salary: %d\n",
				employees[i].m_Name,
				employees[i].m_BirthDate.m_Day,employees[i].m_BirthDate.m_Month,employees[i].m_BirthDate.m_Year,
				employees[i].m_GraduationDate.m_Day,employees[i].m_GraduationDate.m_Month,employees[i].m_GraduationDate.m_Year,
				employees[i].m_Salary);
	}

	return 0;
}


