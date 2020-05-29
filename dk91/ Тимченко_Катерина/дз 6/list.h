#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>

typedef struct __DoubleNode DoubleNode;

typedef struct __DoubleNode
{
    double value;
    DoubleNode *next;
};

typedef struct __DoubleList
{
	int size;
	DoubleNode *head;
	DoubleNode *tail;
}DoubleList;

DoubleNode *createNode(double aValue);
void FreeNode(DoubleNode *aNode);

DoubleList *createList();
void FreeList(DoubleList *aList);
int SizeList(const DoubleList *aList);

DoubleNode *AddElement(DoubleList *aList, DoubleNode * aNewNode);
DoubleNode *ElementsAtIndex(const DoubleList *aList, int index);
DoubleNode *AddEelementByIndex(DoubleList *aList, DoubleNode *aNewNode, int index);
DoubleNode *RemoveElement(DoubleList *aList, int index);

void SwapByIndex(DoubleList *aList, int theLeft, int theRight);
int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

#endif // LIST_H_INCLUDED
