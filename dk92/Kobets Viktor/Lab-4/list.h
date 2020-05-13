#include <stdio.h>
#include <stdlib.h>

#ifndef Lab4TEST_LIST_H
#define Lab4TEST_LIST_H

typedef struct __IntNode IntNode;

typedef struct __IntList
{
    IntNode *head;
    IntNode *tail;
    int size;
    int count;
}IntList;

extern const int kSLListError;
//Interface
//Create/delete a list
IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);;
IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex);

#endif //Lab4TEST_LIST_H