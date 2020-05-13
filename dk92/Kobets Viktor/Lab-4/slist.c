#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

IntNode *SLCreateNodeWithIntValue(int aValue)
{
    IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));

    theResult->size = aValue;
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