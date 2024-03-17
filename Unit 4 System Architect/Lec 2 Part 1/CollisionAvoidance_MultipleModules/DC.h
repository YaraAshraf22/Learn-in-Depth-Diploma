/*
 * DC.h
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#ifndef DC_H_
#define DC_H_

#include "State.h"

//Define states

enum {
	DC_idle,
	DC_busy
}DC_state_ID;


//Declare DC state functions
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

//State pointer to function
//used in DC.c but extern in DC.h to be seen from main.c
extern void (*DC_state)();

#endif /* DC_H_ */
