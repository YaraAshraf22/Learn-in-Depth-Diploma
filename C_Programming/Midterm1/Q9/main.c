/*
 * main.c
 *
 *  Created on: Nov 22, 2023
 *      Author: HP
 */

/*c function to reverse words in string*/

#include "stdio.h"

void reverse(char text[]);

int main ()
{

	char text[30];
	printf("Enter string: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	reverse(text);

	return 0;

}

void reverse(char text[])
{
	int i,j=0;
	int arr_null[5]={0};

	for (i=0; i<30; i++)
	{
		if (text[i]==' ')
		{
			text[i]='\0';
			arr_null[++j]=i+1;
		}
		else if(text[i]=='\0')
		{
			break;
		}

	}

	for(i=j; i>=0; i--)
	{
		printf("%s ",text+arr_null[i]);

	}

}
