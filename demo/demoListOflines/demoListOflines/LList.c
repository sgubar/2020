//
//  LList.c
//  demoListOflines
//
//  Created by Slava Gubar on 4/22/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include "LList.h"
#include <stdlib.h>
#include <strings.h>

LLineNode *createLineNode(Line *aLine);

//init/destroy
LList *createListOfLines(void)
{
	LList *theList = (LList *)malloc(sizeof(LList));
	
	if (NULL != theList)
	{
		bzero(theList, sizeof(LList));
	
//		theList->count = 0;
//		theList->head = NULL;
//		theList->tail = NULL;
	}
	
	return theList;
}

LLineNode *createLineNode(Line *aLine)
{
	if (NULL == aLine)
	{
		return NULL;
	}
	
	LLineNode *theNode = (LLineNode *)malloc(sizeof(LLineNode));
	
	if (NULL != theNode)
	{
		bzero(theNode, sizeof(LLineNode));
		theNode->line = createLine(aLine->A, aLine->B);
	}
	
	return theNode;
}

void destroyListOfLines(LList *aList)
{
	if (NULL == aList)
	{
		return;
	}
	
	// interate through the list
	LLineNode *theNode = aList->head;
	while(NULL != theNode)
	{
		LLineNode *toRemove = theNode;
		theNode = theNode->next;
		destroyLine(toRemove->line);
	
		free(toRemove);
	}

	free(aList);
}

//
void addLineToList(LList *aList, Line *aLine)
{
	if (NULL == aList || NULL == aLine)
	{
		return;
	}
	
	LLineNode *theNewNode = createLineNode(aLine);
	
	if (NULL == theNewNode)
	{
		return ;
	}
	
	if (NULL == aList->head && aList->head == aList->tail)
	{
		//empty list
		aList->head = aList->tail = theNewNode;
	}
	else
	{
		// not empty list
		aList->tail->next = theNewNode;
		theNewNode->prev = aList->tail;
		aList->tail = theNewNode;
	}
	
	aList->count ++;
}

LLineNode *lineAtIndex(LList *aList, int anIndex)
{
	if (NULL == aList || 0 == aList->count || anIndex >= aList->count)
	{
		return NULL;
	}
	
	LLineNode *theResult = aList->head;
	
	while (NULL != theResult && anIndex-- > 0)
	{
		theResult = theResult->next;
	}
	
	return theResult;
}

LLineNode *middleNode(LList *aList)
{
	if (NULL == aList || (NULL == aList->head && aList->head == aList->tail))
	{
		return NULL;
	}
	
	LLineNode *theNode = aList->head;
	int index = 0;
	LLineNode *middleNode = theNode;
	
	while(NULL != theNode)
	{
		if ((index + 1) % 2 == 0)
		{
			middleNode = theNode;
		}
	
		theNode = theNode->next;
		index ++;
	}
	
	return middleNode;
}
