#include "list.h"
#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

// Constants
const int kSLListError = -1;

//Create/delete a list
IntList *SLCreateList() //use
{
    //Allocate memory for the list structure
    IntList *theList = (IntList *)malloc(sizeof(IntList));
    //Clean internal data
    theList->head = NULL; //<!- not head
    theList->tail = NULL; //<!- not tail
    theList->count = 0; //<!- initial value of count is zero - no elements in the list

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

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode) //use
{
    // Check the input parameter
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