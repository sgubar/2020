//
// Created by chelt on 11.05.2020.
//

#include "singlList.h"
#include <stdio.h>
#include <stdlib.h>

IntNode *SLCreateNodeWithIntValue(char w[], int aValue) //
{
    IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));

    theResult->size = aValue;
    for(int i = 0; i < aValue; i++){
        theResult->words[i] = w[i];
    }

    theResult->nextNode = NULL;

    return theResult;
}

void SLFreeIntNode(IntNode *aNode)
{
    if (NULL != aNode)
    {
        free(aNode);
    }
}