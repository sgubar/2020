//
//  SingleLinkedList.c
//  demoList
//
//  Created by Slava Gubar on 3/1/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
#include <stdlib.h>

// Constants
const int kSLListError = -1;

//Create/delete a list
IntList *SLCreateList()
{
	//Allocate memory for the list structure
	IntList *theList = (IntList *)malloc(sizeof(IntList));

	//Clean internal data
	theList->head = NULL; //<!- not head
	theList->tail = NULL; //<!- not tail
	theList->count = 0; //<!- initial value of count is zero - no elements in the list
	
// or
//	bzero(theList, sizeof(IntList));
	
	return theList;
}

void SLFreeList(IntList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}

	//1. Remove all elements
	IntNode *theNode = aList->head;
	
	while (NULL != theNode)
	{
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
	
		SLFreeIntNode(theNodeToBeFree);
	}

	//2. Free memory for the List structure
	free(aList);
}

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}
	
	//Add the new node to end of the list
	
	// a b c d e + G = a b c d e G
	
	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		IntNode *theTail = aList->tail;
		aList->tail = aNewNode;
	
		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;
	
	return aNewNode;
}

int SLCountList(const IntList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *SLNodeAtIndex(const IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		IntNode *theNode = aList->head;
	
		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}
		
			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node
		
		} while (NULL != theNode);
	}
	
	return theResult;
}

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
	IntNode *theResult = NULL;
	
	if (NULL == aList || NULL == aNewNode)
		return NULL;
	
	if (anIndex < 0 || aList->count < anIndex)
		return NULL;
	
	if (0 == anIndex)
	{
		if (NULL == aList->head && NULL == aList->tail)
		{
			SLAddNode(aList, aNewNode);
			theResult = aNewNode;
		}
		else
		{
			IntNode *theHead = aList->head;
			aList->head = aNewNode;
			aList->head->nextNode = theHead;
			aList->count ++;
			theResult = aNewNode;
		}
	}
	else if (aList->count == anIndex)
	{
		SLAddNode(aList, aNewNode);
		theResult = aNewNode;
	}
	else
	{
		int theOwnerIndex = anIndex - 1;
		IntNode *theOwnNode = SLNodeAtIndex(aList, theOwnerIndex);
	
		if (NULL != theOwnNode)
		{
			IntNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;
		
			aList->count ++;
			theResult = aNewNode;
		}
	}
	
	return theResult;
}

IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;
	
	if (NULL == aList)
		return NULL;
	
	if (anIndex < 0 || aList->count <= anIndex)
		return NULL;
	
	if (0 == anIndex)
	{
		IntNode *theHead = aList->head;
	
		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;
	
		aList->count --;
		theResult = theHead;
	}
	else
	{
		IntNode *theOwnNode = SLNodeAtIndex(aList, anIndex - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->nextNode;
			theOwnNode->nextNode = theResult->nextNode;
		
			aList->count --;
		
			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}
	
	return theResult;
}

void SLSwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return ;
	
	IntNode *theLeftNode = SLNodeAtIndex(aList, aLeftIndex);
	IntNode *theRightNode = SLNodeAtIndex(aList, aRightIndex);
	
	int theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}

