//
//  tree.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>


void postOrder(DoubleNode *localRoot);
static void destroyNode(DoubleNode *aNode);
static DoubleNode *createDoubleNodeWithValue(double aValue);

DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyDoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		DoubleNode *theCurrent = aTree->root;
		DoubleNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
		
			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
	
		aTree->count ++;
	}
}

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue)
{
	DoubleNode *theCurrentNode = NULL;
	
	if (NULL != aTree)
	{
		DoubleNode *theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	
	return theCurrentNode;
}

void deleteNodeWithValue(DoubleTree *aTree, double aValue)
{
	DoubleNode *node = findNodeWithValue(aTree, aValue);
	if(NULL != node)
	{
		destroyNode(node);
	}
}

void printTree(DoubleTree *aTree)
{
	postOrder(aTree->root);
}

void postOrder(DoubleNode *localRoot)
{
	if(localRoot != NULL)
	{
		postOrder(localRoot->leftChild);
		postOrder(localRoot->rightChild);
		printf("%02.2f\n",localRoot->value);
	}
}
int countNodesWithTree(DoubleTree *aTree)
{
	return aTree->count;
}

#pragma mark -
void destroyNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

DoubleNode *createDoubleNodeWithValue(double aValue)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}
