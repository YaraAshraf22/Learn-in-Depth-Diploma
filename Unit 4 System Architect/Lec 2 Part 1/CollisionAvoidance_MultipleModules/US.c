/*
 * US.c
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#include "US.h"

//Variables of the block
static int US_distance = 0;

//State pointer to function
void (*US_state)();

//Random distance Fn
unsigned int US_Get_Distance_Random (int l, int r, int count);

void US_init ()
{
	//init US Driver
	printf("US_init \n");
}
STATE_define(US_busy)
{
	//Set state
	US_state_ID = US_busy;

	//State Action
	US_distance = US_Get_Distance_Random(45,55,1);
	printf("US_waiting: distance = %d \n", US_distance);
	//Send signal to CA module
	US_Get_Distance(US_distance);
	//loop in same state
	US_state = STATE(US_busy);

}
unsigned int US_Get_Distance_Random (int l, int r, int count)
{
	int i, random_num;
	for (i=0; i<count; i++)
	{
		random_num = (rand() % (r - l + 1 )) + l;
		return random_num;
	}
}
