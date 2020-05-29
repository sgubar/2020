#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//предварительная декларация
typedef struct __CharNode CharNode;

typedef struct __CharNode
{
    int size;
    char *words;
	CharNode *nextNode;
};

//новый узел со значением int
CharNode *SLCreateNodeWithCharValue(char value[], int aValue);
//освобождение созданого узла
void SLFreeCharNode(CharNode *aNode);

#endif // NODE_H_INCLUDED
