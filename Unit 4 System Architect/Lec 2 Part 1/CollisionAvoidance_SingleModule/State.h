/*
 * State.h
 *
 *  Created on: Mar 16, 2024
 *      Author: HP
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

//Automatic state function to be generated
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

#endif /* STATE_H_ */
