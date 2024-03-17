/*
 * DC.c
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#include "DC.h"

//Variables of the block
static int DC_speed = 0 ;

//State pointer to function
void (*DC_state)();

void DC_init ()
{
	//init PWM
	printf("DC_init \n");
}
void DC_Motor_Speed (int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf ("CA ----- speed = %d ----> DC\n", DC_speed);
}
STATE_define(DC_idle)
{
	//Set state
	DC_state_ID = DC_idle;

	//State Action
	//No change in speed

	printf("DC_idle: speed = %d \n", DC_speed);

}
STATE_define(DC_busy)
{
	//Set state
	DC_state_ID = DC_busy;

	//State Action
	//Call PWM to set speed = DC_speed

	printf("DC_busy: speed = %d \n", DC_speed);
	DC_state = STATE(DC_idle);
}

