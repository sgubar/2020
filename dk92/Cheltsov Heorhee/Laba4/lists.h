//
// Created by chelt on 10.05.2020.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef LR4_LISTS_H
#define LR4_LISTS_H

typedef struct __IntNode IntNode;

typedef struct __IntList
{
    IntNode *head;
    IntNode *tail;
    int size;
    char *words[10];
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

void SLSwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex);


#endif //LR4_LISTS_H
