#include "list.h"
#include <stdio.h>
#include <stdlib.h>

DoubleNode *createNode(double aValue)
{
    DoubleNode *theResult = (DoubleNode *)malloc(sizeof(DoubleNode));

    theResult->next = NULL;
    theResult->value = aValue;

    return theResult;
}

void FreeNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

DoubleList *createList()
{
    DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));

    theList->size = 0;
    theList->head = NULL;
    theList->tail = NULL;

    return theList;
}

void FreeList(DoubleList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	DoubleNode *aNode = aList->head;

	while (NULL != aNode)
	{
		DoubleNode *theNodeToBeFree = aNode;
		aNode = aNode->next;

		FreeNode(theNodeToBeFree);
	}

	free(aList);
}

DoubleNode *AddElement(DoubleList *aList, DoubleNode *aNewNode)
{
    if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}

    if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		DoubleNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->next = aList->tail;
		}
	}

	aList->size += 1;

	return aNewNode;
}

int SizeList(const DoubleList *aList)
{
	int theResult = -1;

	if (NULL != aList)
	{
		theResult = aList->size;
	}

	return theResult;
}

DoubleNode *ElementsAtIndex(const DoubleList *aList, int index)
{
	DoubleNode *theResult = NULL;

	if (NULL != aList && index < aList->size)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;

		do
		{
			if (i == index) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}

			i++; // increase index
			theNode = theNode->next; //<! - go to next node

		} while (NULL != theNode);
	}

	return theResult;
}

DoubleNode *AddEelementByIndex(DoubleList *aList, DoubleNode *aNewNode, int index)
{
    DoubleNode *theResult = NULL;

    if (NULL == aList || NULL == aNewNode)
		return NULL;

    if (index < 0 || aList->size < index)
		return NULL;

	if (index == 0)
	{
		if (NULL == aList->head && NULL == aList->tail)
		{
			AddElement(aList, aNewNode);
			theResult = aNewNode;
		}

		else
		{
			DoubleNode *theHead = aList->head;
			aList->head = aNewNode;
			aList->head->next = theHead;
			aList->size ++;
			theResult = aNewNode;
		}
	}

	else if (aList->size == index)
	{
		AddElement(aList, aNewNode);
		theResult = aNewNode;
	}
	else
	{
		int theOwnerIndex = index - 1;
		DoubleNode *theOwnNode = ElementsAtIndex(aList, theOwnerIndex);

		if (NULL != theOwnNode)
		{
			DoubleNode *theNextOwnNode = theOwnNode->next;
			theOwnNode->next = aNewNode;
			aNewNode->next = theNextOwnNode;

			aList->size ++;
			theResult = aNewNode;
		}
	}

	return theResult;
}

DoubleNode *RemoveElement(DoubleList *aList, int index)
{
    DoubleNode *theResult = NULL;

    if (NULL == aList)
		return NULL;

	if (index < 0 || aList->size <= index)
		return NULL;

    if (0 == index)
	{
		DoubleNode *theHead = aList->head;

		aList->head = aList->head->next;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->size --;
		theResult = theHead;
	}
    else
	{
		DoubleNode *theOwnNode = ElementsAtIndex(aList, index - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->next;
			theOwnNode->next = theResult->next;

			aList->size --;

			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}

	return theResult;
}

void SwapByIndex(DoubleList *aList, int theLeft, int theRight)
{
    if (theLeft == theRight)
        return ;

    DoubleNode *theNode_l = ElementsAtIndex(aList,theLeft);
    DoubleNode *theNode_r = ElementsAtIndex(aList,theRight);

    int theTmp = theNode_l->value;
    theNode_l->value = theNode_r->value;
    theNode_r->value = theTmp;

}

int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex + 1;

    while (1)
    {
        // search the bigest element
        while (theLeft < aRightIndex && ElementsAtIndex(aList, ++theLeft)->value < aPivot);

        // search the lowest element
        while (theRight > aLeftIndex && ElementsAtIndex(aList,--theRight)->value > aPivot);

        if (theLeft = theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            SwapByIndex(aList, theLeft, theRight);
        }
    }

    return theLeft; // return break position
}

void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; //the array is fully sorted
    }

    int thePivot = ElementsAtIndex(aList, aRightIndex)->value;
    int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(aList, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(aList, thePartitionIndex + 1, aRightIndex);
}
