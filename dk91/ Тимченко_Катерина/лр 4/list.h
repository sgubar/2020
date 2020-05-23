#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//предварительная декларация
typedef struct __CharNode CharNode;

typedef struct __CharList
{
	CharNode *head;
	CharNode *tail;
	int size;
	char *words[7];
	int count;
}CharList;

extern const int kSLListError;

//создание или удаление списка
CharList *SLCreateList();
void SLFreeList(CharList *aList);

CharNode * SLAddNode(CharList *aList, CharNode *aNewNode);

int SLCountList(const CharList *aList);
CharNode *SLNodeAtIndex(const CharList *aList, int anIndex);

void SLSwapNodesByIndex(CharList *aList, int theLeft, int theRight);
void quickSort(CharList *aList, int aLeftIndex, int aRightIndex);
int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void doPrintSLList(const CharList *aList);

#endif
