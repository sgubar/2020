#ifndef List_h
#define List_h

#include <stdio.h>


// Predeclaration
typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

extern const int kSLListError;

//Interface
//Create/delete a list
IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex);

void SLPer(IntList *aList, int anval);


void SLSwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex);
#endif /* List_h */
