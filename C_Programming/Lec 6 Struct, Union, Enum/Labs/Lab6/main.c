/*
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: HP
 */
/*
 * Using Enum and structure
 */
#include "stdio.h"

enum Gender {Male, Female};

struct SPerson
{
	char m_Name [50];
	enum Gender m_Gender;
};

int main ()
{
	int i;
	struct SPerson persons[] ={
			{"Yara Ashraf", Female},{"Hazem Ahmed", Male}
	};

	for (i=0;i<sizeof(persons)/sizeof(struct SPerson); i++)
	{
		printf("%s - %s\n", persons[i].m_Name,((persons[i].m_Gender==Male)?"Male":"Female"));
	}
	return 0;
}
