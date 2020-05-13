#ifndef Lab4TEST_SLIST_H
#define Lab4TEST_SLIST_H

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
    int size;
    IntNode *nextNode;//<! - the reference to next node
};
//Create a new Node with int value
IntNode *SLCreateNodeWithIntValue(int aValue); //
//Free a created node
void SLFreeIntNode(IntNode *aNode);


#endif //Lab4TEST_SLIST_H