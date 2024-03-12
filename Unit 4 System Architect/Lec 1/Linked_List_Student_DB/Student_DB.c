/*
 * Student_DB.c
 *
 *  Created on: Mar 10, 2024
 *      Author: HP
 */

#include "Student_DB.h"

//Global pointer the first student node
struct Sstudent* gpFirstStudent = NULL;

void Add_Student ()
{
	struct Sstudent* pNewStudent;
	struct Sstudent* pLastStudent;
	char temp_text[40];

	//Check if list is empty
	if(gpFirstStudent == NULL)
	{
		//create new record
		pNewStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));

		//assign it to first pointer
		gpFirstStudent = pNewStudent;
	}
	else //List already contains records
	{
		//navigate to last record
		pLastStudent = gpFirstStudent; //start at beginning of the list at first student

		while(pLastStudent->PNextStudent) //loop till last record that points to null
			pLastStudent = pLastStudent->PNextStudent;

		//create new record
		pNewStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
		//assign next ptr of last student to New student
		pLastStudent->PNextStudent = pNewStudent;
		//assign next ptr of new student to Null
		pNewStudent->PNextStudent = NULL;

	}

	//fill the new record
	DPRINTF("\n Enter student ID: ");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter student name: ");
	gets(pNewStudent->student.name);

	DPRINTF("\n Enter student height: ");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);

	//set next pointer of new student (current last) to null
	pNewStudent->PNextStudent = NULL;


}
unsigned int Delete_Student ()
{
	char temp_ID[10];
	unsigned int Selected_ID;

	DPRINTF("\n Enter the student ID to be deleted: ");
	gets(temp_ID);
	Selected_ID=atoi(temp_ID);

	//check if list is not empty
	if(gpFirstStudent) //if first ptr doesn't point to null
	{
		struct Sstudent* pSelectedStudent = gpFirstStudent;
		struct Sstudent* pPreviousStudent = NULL; // if the selected node is the first then its previous is NULL

		//Loop on all records
		while(pSelectedStudent)
		{
			//compare each node ID with the selected ID
			if(pSelectedStudent->student.ID == Selected_ID)
			{
				//if first student is not the selected one // prev pointer doesn't point to NULL
				if(pPreviousStudent)
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				else
				{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 0;
			}
			//go to next node
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
		DPRINTF("\t No ID match. \n");
		return 1;
	}
	else
	{
		DPRINTF("\t List is empty. \n");
		return 1;
	}
}
void View_Students ()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	unsigned int count = 0;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n Record no. %d ", count+1);
			DPRINTF("\n \t ID: %d", pCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s", pCurrentStudent->student.name);
			DPRINTF("\n \t Height: %f", pCurrentStudent->student.height);
			pCurrentStudent= pCurrentStudent->PNextStudent;
			count++;
		}
	}
}
void Delete_ALL ()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrentStudent)
		{
			struct Sstudent* pTempStudent = pCurrentStudent;
			pCurrentStudent=pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;
	}
}
unsigned int Get_Nth_Node ()
{
	char temp_index[10];
	unsigned int index, count=0;
	DPRINTF("\n Enter index: \n");
	index = atoi (gets(temp_index));

	struct Sstudent* pCurrentStudent = gpFirstStudent;
	while(pCurrentStudent)
	{
		if(count == index)
		{
			DPRINTF("\n Record index no. %d ", index);
			DPRINTF("\n \t ID: %d", pCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s", pCurrentStudent->student.name);
			DPRINTF("\n \t Height: %f", pCurrentStudent->student.height);
			return 0;
		}
		pCurrentStudent=pCurrentStudent->PNextStudent;
		count++;
	}
	return 1;
}
unsigned int Get_Num_Nodes (struct Sstudent* pCurrentStudent)
{
	static unsigned int count=0;
	if(pCurrentStudent != NULL)
	{
		count++;
		Get_Num_Nodes(pCurrentStudent->PNextStudent);
	}
	return count;
}
void Get_Nth_Node_End ()
{
	char temp_node[10];
	unsigned int i, node;
	DPRINTF("\n Enter node index from end: \n");
	node = atoi (gets(temp_node));

	struct Sstudent* pMain = gpFirstStudent;
	struct Sstudent* pReference = gpFirstStudent;

	for (i=0; i<node; i++)
	{
		pReference = pReference->PNextStudent;
	}
	while (pReference)
	{
		pReference = pReference->PNextStudent;
		pMain = pMain->PNextStudent;
	}
	DPRINTF("\n Record no. %d ", node);
	DPRINTF("\n \t ID: %d", pMain->student.ID);
	DPRINTF("\n \t Name: %s", pMain->student.name);
	DPRINTF("\n \t Height: %f", pMain->student.height);
}
void Get_Middle_Node ()
{
	unsigned int length, count=1;
	length=Get_Num_Nodes(gpFirstStudent);

	struct Sstudent* pSlow = gpFirstStudent;
	struct Sstudent* pFast = gpFirstStudent;

	while(pFast && pFast->PNextStudent)
	{
		pSlow = pSlow->PNextStudent;
		pFast = pFast->PNextStudent->PNextStudent;
		count++;
	}
	if(length%2==0) //if even
	{
		pSlow=pSlow->PNextStudent;
		count++;
	}
	DPRINTF("\n Record no. %d ", count);
	DPRINTF("\n \t ID: %d", pSlow->student.ID);
	DPRINTF("\n \t Name: %s", pSlow->student.name);
	DPRINTF("\n \t Height: %f", pSlow->student.height);
}
unsigned int Detect_Loop ()
{
	struct Sstudent* pSlow = gpFirstStudent;
	struct Sstudent* pFast = gpFirstStudent;

	while(pSlow && pFast && pFast->PNextStudent)
	{
		pSlow = pSlow->PNextStudent;
		pFast = pFast->PNextStudent->PNextStudent;
		if(pSlow == pFast)
		{
			DPRINTF("\n Loop Detected.");
			return 1;
		}
	}
	DPRINTF("\n No Loop Detected.");
	return 0;
}
unsigned int Reverse_List ()
{
	struct Sstudent *pPrevious = NULL;
	struct Sstudent *pCurrent = gpFirstStudent;
	struct Sstudent *pNext = gpFirstStudent;

	//If no list reverse can be done (empty of contains only one record)
	if(!gpFirstStudent)
	{
		DPRINTF("\n List is Empty.");
		return 1;
	}
	else if (!(gpFirstStudent->PNextStudent))
	{
		DPRINTF("\n List has only one record.");
		return 1;
	}

	//if more than one record exists
	//Loop till end of the list (null) and at each iteration reverse the link then move on to the next node
	while(pCurrent)
	{
		pNext = pCurrent->PNextStudent;
		pCurrent->PNextStudent = pPrevious;
		pPrevious = pCurrent;
		pCurrent = pNext;
	}
	// move global pointer to the last element in the list
	gpFirstStudent = pPrevious;
	return 0;
}
