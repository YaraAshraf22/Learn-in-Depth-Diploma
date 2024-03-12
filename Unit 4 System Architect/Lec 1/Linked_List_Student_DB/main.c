/*
 * main.c
 *
 *  Created on: Mar 10, 2024
 *      Author: HP
 */

#include "Student_DB.h"

extern struct Sstudent* gpFirstStudent;

int main ()
{
	char temp_text[40];
	int Sum_nodes;
	while (1)
	{
		DPRINTF("\n =======================");
		DPRINTF("\n \t Choose one of the below options \n");
		DPRINTF("\n 1: AddStudent");
		DPRINTF("\n 2: delete_student");
		DPRINTF("\n 3: view_students");
		DPRINTF("\n 4: DeleteAll");
		DPRINTF("\n 5: Get nth node");
		DPRINTF("\n 6: Get number of nodes");
		DPRINTF("\n 7: Get nth node from the end");
		DPRINTF("\n 8: Get Middle Node");
		DPRINTF("\n 9: Detect Loop");
		DPRINTF("\n 10: Reverse List");
		DPRINTF("\n Enter Option Number: ");
		gets(temp_text);

		DPRINTF("\n =======================");
		switch(atoi(temp_text))
		{
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_Students();
			break;
		case 4:
			Delete_ALL();
			break;
		case 5:
			Get_Nth_Node ();
			break;
		case 6:
			Sum_nodes = Get_Num_Nodes (gpFirstStudent);
			DPRINTF("\n Number of nodes = %d", Sum_nodes);
			break;
		case 7:
			Get_Nth_Node_End ();
			break;
		case 8:
			Get_Middle_Node ();
			break;
		case 9:
			Detect_Loop ();
			break;
		case 10:
			Reverse_List ();

		}
	}
	return 0;
}

