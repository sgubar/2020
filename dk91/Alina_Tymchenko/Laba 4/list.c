#include "list.h"
#include <stdio.h>
#include <stdlib.h>


//node functions
Node *createNode(int aValue)
{
	Node *theResult = (Node *)malloc(sizeof(Node));

	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void destroyNode(Node *aNode)
{
	if (NULL != aNode)
		free(aNode);
}


//lists functions
	//creation & destruction
List *createList()
{
	List *theList = (List *)malloc(sizeof(List));

	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;

	return theList;
}

void destroyList(List *aList)
{
	if (NULL == aList)
		return;

	Node *theNode = aList->head;
	while (NULL != theNode)
	{
		Node *theNodeToKill = theNode;
		theNode = theNode->nextNode;

		destroyNode(theNodeToKill);
	}

	free(aList);
}

	//operations
Node *addNode(List *aList, Node *aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
		return NULL;

	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;	//list was empty
	}
	else
	{
		Node *theNewTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theNewTail)
			theNewTail->nextNode = aList->tail;
	}
	aList->count += 1;

	return aNewNode;
}

	//misc actions
int countList(const List *aList)
{
	int theResult = -1;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

Node *nodeAtIndex(const List *aList, int anIndex)
{
	Node *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		Node *theNode = aList->head;

		do
		{
			if (i == anIndex)
			{
				theResult = theNode;
				break;
			}

			i++;
			theNode = theNode->nextNode;

		} while (NULL != theNode);
	}

	return theResult;
}

void swapNodes(List *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return ;

	Node *theLeftNode = nodeAtIndex(aList, aLeftIndex);
	Node *theRightNode = nodeAtIndex(aList, aRightIndex);

	int temp_v = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = temp_v;
}

void printList(const List *aList)
{
	if (NULL == aList)
		return;

	for (int i = 0; i < countList(aList); i++)
	{
		Node *theNode = nodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node.[%d] = |%d|\n", i, theNode->value);
		}
	}
}
