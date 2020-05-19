#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "list.h"

#define SIZE 8

int findIndexOfMax(const List *aList);
int findIndexOfMin(const List *aList);

int main(int argc, char **argv)
{
	srand(time(NULL));

	//making a list
	List *Values = createList();
	Node *nodeArray[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		nodeArray[i] = createNode(0 + rand() % 10);
		addNode(Values, nodeArray[i]);
	}

	printf("====MINMAX====\n");
	printf("MAX IDX = [%d]\n", findIndexOfMax(Values));
	printf("MIN IDX = [%d]\n", findIndexOfMin(Values));
	printf("===UNSORTED===\n");

	//finding max & min, applying relative sorting 2 a list
	printList(Values);
	if (findIndexOfMin(Values) < findIndexOfMax(Values))
		quickSort(Values, findIndexOfMin(Values), findIndexOfMax(Values)+1);
	else
		quickSort(Values, findIndexOfMax(Values)+1 , findIndexOfMin(Values));

	printf("====SORTED====\n");
	printList(Values);

	destroyList(Values);

	return 0;
}

int findIndexOfMax(const List *aList)
{
	int max_i = -1;
	Node *theResult = NULL;

	if (NULL != aList)
	{
		Node *theNode = aList->head;
		theResult = theNode;
		max_i = 0;

		if (NULL != theNode->nextNode)
		{
			theNode = theNode->nextNode;

			for (int i = 0; NULL != theNode; i++)
			{
				if (theResult->value < theNode->value)
				{
					theResult = theNode;
					max_i = i + 1;
				}

				theNode = theNode->nextNode;
			}
		}
	}

	return max_i;
}

int findIndexOfMin(const List *aList)
{
	int min_i = -1;
	Node *theResult = NULL;

	if (NULL != aList)
	{
		Node *theNode = aList->head;
		theResult = theNode;
		min_i = 0;

		if (NULL != theNode->nextNode)
		{
			theNode = theNode->nextNode;

			for (int i = 0; NULL != theNode; i++)
			{
				if (theResult->value > theNode->value)
				{
					theResult = theNode;
					min_i = i + 1;
				}

				theNode = theNode->nextNode;
			}
		}
	}

	return min_i;
}
