/*
 * Student_DB.h
 *
 *  Created on: Mar 10, 2024
 *      Author: HP
 */

#ifndef STUDENT_DB_H_
#define STUDENT_DB_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DPRINTF(...)	{fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}
//Student Data
struct Sdata {
	unsigned int ID;
	char name[40];
	float height;
};

//Linked List Node
struct Sstudent {
	struct Sdata student;
	struct Sstudent* PNextStudent;
};


//APIs
void Add_Student ();
unsigned int Delete_Student ();
void View_Students ();
void Delete_ALL ();
unsigned int Get_Nth_Node ();
unsigned int Get_Num_Nodes (struct Sstudent* pCurrentStudent);
void Get_Nth_Node_End ();
void Get_Middle_Node ();
unsigned int Detect_Loop ();
unsigned int Reverse_List ();

#endif /* STUDENT_DB_H_ */
