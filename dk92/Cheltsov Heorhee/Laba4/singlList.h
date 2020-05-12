//
// Created by chelt on 11.05.2020.
//

#ifndef LR4_SINGLLIST_H
#define LR4_SINGLLIST_H

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
    int size;
    char *words[10];
    IntNode *nextNode;//<! - the reference to next node
};

//Create a new Node with int value
IntNode *SLCreateNodeWithIntValue(char w[], int aValue); //
//Free a created node
void SLFreeIntNode(IntNode *aNode);


#endif //LR4_SINGLLIST_H
