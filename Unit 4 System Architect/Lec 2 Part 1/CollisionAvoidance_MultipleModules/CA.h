/*
 * CA.h
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#ifndef CA_H_
#define CA_H_

#include "State.h"

//Define states

enum {
	CA_waiting,
	CA_driving
}CA_state_ID;


//Declare CA state functions
STATE_define(CA_waiting);
STATE_define(CA_driving);

//State pointer to function
//used in CA.c but extern in CA.h to be seen from main.c
extern void (*CA_state)();

#endif /* CA_H_ */
