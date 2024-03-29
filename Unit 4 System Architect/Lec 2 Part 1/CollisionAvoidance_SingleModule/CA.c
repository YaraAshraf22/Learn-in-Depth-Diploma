/*
 * CA.c
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#include "CA.h"

//Variables of the block
static int CA_speed = 0 ;
static int CA_distance = 0;
static int CA_threshold = 50;

//State pointer to function
void (*CA_state)();

//Random distance Fn
unsigned int US_Get_Distance_Random (int l, int r, int count);

STATE_define(CA_waiting)
{
	//Set state
	CA_state_ID = CA_waiting;

	//State Action
	//Call DC_Motor
	CA_speed = 0;

	//Event Check
	//Get Random distance
	CA_distance = US_Get_Distance_Random(45,55,1);
	(CA_distance > CA_threshold)? (CA_state = STATE(CA_driving)) : (CA_state = STATE(CA_waiting));
	printf("CA_waiting: distance = %d, speed = %d \n", CA_distance, CA_speed);

}
STATE_define(CA_driving)
{
	//Set state
	CA_state_ID = CA_driving;

	//State Action
	//Call DC_Motor
	CA_speed = 30;

	//Event Check
	//Get Random distance
	CA_distance = US_Get_Distance_Random(45,55,1);
	(CA_distance > CA_threshold)? (CA_state = STATE(CA_driving)) : (CA_state = STATE(CA_waiting));
	printf("CA_driving: distance = %d, speed = %d \n", CA_distance, CA_speed);

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
