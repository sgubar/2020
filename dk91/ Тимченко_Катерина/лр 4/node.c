#include "node.h "
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

CharNode *SLCreateNodeWithCharValue(char value[], int aValue)
{
	CharNode *theResult = (CharNode *)malloc(sizeof(CharNode));

    theResult->size = aValue;

    for(int i = 0; i < aValue; i++){
        theResult->words[i] = value[i];
    }
	theResult->nextNode = NULL;

	return theResult;
}

void SLFreeCharNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}
