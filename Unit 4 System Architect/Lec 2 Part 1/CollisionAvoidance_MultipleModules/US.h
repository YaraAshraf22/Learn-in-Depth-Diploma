/*
 * US.h
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#ifndef US_H_
#define US_H_

#include "State.h"

//Define states

enum {
	US_busy
}US_state_ID;


//Declare US state functions
STATE_define(US_busy);

void US_init ();

//State pointer to function
//used in US.c but extern in US.h to be seen from main.c
extern void (*US_state)();

#endif /* US_H_ */
