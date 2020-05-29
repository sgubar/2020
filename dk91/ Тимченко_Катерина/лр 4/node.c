#include "node.h "
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

CharNode *SLCreateNodeWithCharValue(char value[], int aValue)
{
	CharNode *theResult = (CharNode *)malloc(sizeof(CharNode));
    theResult->words = (char *)malloc(sizeof(char)*(aValue+1));
    theResult->size = aValue;

    for(int i = 0; i < aValue; i++){
        theResult->words[i] = value[i];
    }
    theResult->words[aValue] = '\0';
	theResult->nextNode = NULL;

	return theResult;
}

void SLFreeCharNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
	    free(aNode->words);
		free(aNode);
	}
}
