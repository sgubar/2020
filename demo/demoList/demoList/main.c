//
//  main.c
//  demoList
//
//  Created by Slava Gubar on 3/1/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"
#include "quickSort.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{
	printf("Start to demo a single-linked list ...\n");
	
	IntNode *theNode2 = SLCreateNodeWithIntValue(2);
	IntNode *theNode4 = SLCreateNodeWithIntValue(4);
	
	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, SLCreateNodeWithIntValue(7));
	SLAddNode(theList, SLCreateNodeWithIntValue(8));

	IntNode *theNode = SLCreateNodeWithIntValue(5);
	
	SLInsertNodeAtIndex(theList, theNode, 4);
	SLInsertNodeAtIndex(theList, SLCreateNodeWithIntValue(10), 4);
	
	doPrintSLList(theList);
	theNode = SLRemovedNodeAtIndex(theList, 4);
	SLInsertNodeAtIndex(theList, theNode, 2);
	

	printf("After removing: \n");
	doPrintSLList(theList);
	
	printf("Sorting: \n");
	quickSort(theList, 0, theList->count - 1);
	
	doPrintSLList(theList);
	
	SLFreeList(theList);
	
	printf("Done.\n");
}

void doPrintSLList(const IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
