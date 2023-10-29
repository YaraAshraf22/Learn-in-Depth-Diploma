/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */

#include "stdio.h"
#include "string.h"

/*Find the frequency of characters in a string*/

int main ()
{
	char text[50];
	char c,i, n_characters, frequency=0;

	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(text);

	printf("\nEnter a character to find frequency: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);

	n_characters = strlen(text);
	for(i=0;i<n_characters;i++)
	{
		if (text[i] == c)
		{
			frequency++;
		}
	}

	printf("\nFrequency of %c = %d", c, frequency);

	return 0;
}

