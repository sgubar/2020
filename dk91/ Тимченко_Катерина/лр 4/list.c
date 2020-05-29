#include <stdio.h>
#include "list.h"
#include "node.h"
#include <stdlib.h>

const int kSLListError = -1;

//создание списка
CharList *SLCreateList()
{
    //выделение памяти для структуры списка
	CharList *theList = (CharList *)malloc(sizeof(CharList));

	//очищаем внутренние данные
	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;//в списке нет элементов при cont=0

	return theList;
}

void SLFreeList(CharList *aList)
{

	//проверяем входной параметр
	if (NULL == aList)
		return;

    CharNode *theNode = aList->head;

    //удаляем все элементы
		do
		{
			CharNode *theNodeToBeFree = theNode;
			theNode = theNode->nextNode;

			SLFreeCharNode(theNodeToBeFree);

		}while (NULL != theNode);

		free(aList);
}

CharNode * SLAddNode(CharList *aList, CharNode *aNewNode)
{

    //проверка входного параметра
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}

	//новый узел в конце списка
	if (NULL == aList->head && NULL == aList->tail)
	{
	    //список пустой
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		CharNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;
	return aNewNode;
}

int SLCountList(const CharList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

CharNode *SLNodeAtIndex(const CharList *aList, int anIndex)
{
	CharNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		CharNode *theNode = aList->head;

		do
		{
			if (i == anIndex)
			{
				theResult = theNode;
				break;
			}

			i++;
			theNode = theNode->nextNode;//переходим к новому узлу

		} while (NULL != theNode);
	}

	return theResult;
}

void SLSwapNodesByIndex(CharList *aList, int theLeft, int theRight)
{
    if (theLeft == theRight) return ;

    CharNode *theNode_l = SLNodeAtIndex(aList,theLeft);
    CharNode *theNode_r = SLNodeAtIndex(aList,theRight);

    int theTmp = theNode_l->size;
    theNode_l->size = theNode_r->size;
    theNode_r->size = theTmp;

    char Tmpchar[7];

    for(int i = 0; i < theNode_r->size; i++){
        Tmpchar[i] = theNode_l->words[i];
        theNode_l->words[i] = theNode_r->words[i];
        theNode_r->words[i] = Tmpchar[i];
    }
}

int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex + 1;

    while (1)
    {
        // search the bigest element
        while (theLeft < aRightIndex && SLNodeAtIndex(aList, ++theLeft)->size < aPivot);

        // search the lowest element
        while (theRight > aLeftIndex && SLNodeAtIndex(aList,--theRight)->size > aPivot);

        if (theLeft = theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            SLSwapNodesByIndex(aList, theLeft, theRight);
        }
    }

    return theLeft; // return break position
}

void quickSort(CharList *aList, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex <= aLeftIndex)
    {
        return; //the array is fully sorted
    }

    int thePivot = SLNodeAtIndex(aList, aRightIndex)->size;
    int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(aList, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(aList, thePartitionIndex + 1, aRightIndex);
}


