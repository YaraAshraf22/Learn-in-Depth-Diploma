/*
 * main.c
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup ()
{
	//To init all drivers
	//init interrupts
	//init HAL: US_Driver , DC_Motor_Driver
	//init Blocks
	US_init();
	DC_init();
	//set states of the pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}
void main ()
{

	//volatile to prevent optimization
	volatile unsigned int delay;

	setup();
	while(1)
	{
		//Call state of each block
		US_state();
		CA_state();
		DC_state();
		//delay
		for(delay = 0 ; delay <= 10000 ; delay++);
	}
}
