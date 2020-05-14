//
//  tree.h
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
	DoubleNode *root;
	int count;
} DoubleTree;

// interface
DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);
void deleteNodeWithValue(DoubleTree *aTree, double aValue);

void mergeTrees(DoubleTree *aTreeDst, DoubleTree *aTreeSrc);

void printTree(DoubleTree *aTree);
int countNodesWithTree(DoubleTree *aTree);

#endif /* tree_h */
