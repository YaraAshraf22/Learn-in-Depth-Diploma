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

void US_Get_Distance (int d)
{
	CA_distance = d;
	(CA_distance > CA_threshold)? (CA_state = STATE(CA_driving)) : (CA_state = STATE(CA_waiting));
	printf ("US ----- distance = %d ----> CA\n", CA_distance);
}
STATE_define(CA_waiting)
{
	//Set state
	CA_state_ID = CA_waiting;
	printf("CA_waiting: distance = %d, speed = %d \n", CA_distance, CA_speed);

	//State Action
	//Call DC_Motor
	CA_speed = 0;
	DC_Motor_Speed (CA_speed);
}
STATE_define(CA_driving)
{
	//Set state
	CA_state_ID = CA_driving;
	printf("CA_driving: distance = %d, speed = %d \n", CA_distance, CA_speed);

	//State Action
	//Call DC_Motor
	CA_speed = 30;
	DC_Motor_Speed (CA_speed);
}

