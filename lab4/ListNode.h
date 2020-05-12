#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	IntNode *nextNode;//<! - the reference to next node
};

//Create a new Node with int value
IntNode *SLCreateNodeWithIntValue(int aValue);
//Free a created node
void SLFreeIntNode(IntNode *aNode);

#endif /* ListNode_h */
