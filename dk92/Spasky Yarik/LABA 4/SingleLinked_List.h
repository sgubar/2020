#ifndef SINGLELINKED_LIST_H
#define SINGLELINKED_LIST_H

#include <stdio.h>

typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int acount;
}IntList;

extern const int ListError;


IntList *CreateList();
void FreeList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);

int CountList(const IntList *aList);
IntNode *NodeAtIndex(const IntList *aList, int aIndex);
void doPrintList(const IntList *aList);
int Minimal(IntList *List);

IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex);

void SwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex);

#endif
