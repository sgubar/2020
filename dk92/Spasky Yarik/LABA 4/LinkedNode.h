#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <stdio.h>

typedef struct __IntNode IntNode;

struct __IntNode
{
	int data;
	IntNode *nextNode;
};


IntNode *CreateNode(int adata);

void FreeNode(IntNode *aNode);

#endif
