#include "header.h"
#include <stdlib.h>
#include <string.h>

BinTree *createBinTree()
{
	BinTree *aTree = (BinTree *)malloc(sizeof(BinTree));

	if (NULL != aTree)
	{
		aTree->root = NULL;
		aTree->count = 0;
	}

	return aTree;
}

void destroyBinTree(BinTree *aTree)
{
	if (NULL != aTree)
	{
		free(aTree);
	}
}

void debugTree(BinTree *ATree)
{
	addNode(ATree, 15);
	addNode(ATree, 5);
	addNode(ATree, 17);
	addNode(ATree, 16);
	addNode(ATree, 2);
	addNode(ATree, 10);
	addNode(ATree, 19);
}

Node *createNode(int aValue)
{
	Node *theNode = (Node *)malloc(sizeof(Node));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

	//operations
void destroyNode(Node *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

Node *destroyTreeNode(Node *treeRoot, int value)
{
    if (treeRoot == NULL)
		return treeRoot;

    if (value < treeRoot->value)
        treeRoot->leftChild = destroyTreeNode(treeRoot->leftChild, value);

    else if (value > treeRoot->value)
        treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, value);

    else
    {
		//node either without any or with left or right child
        if (treeRoot->leftChild == NULL)
        {
            Node *tempNode = treeRoot->rightChild;
            destroyNode(treeRoot);
            return tempNode;
        }
        else if (treeRoot->rightChild == NULL)
        {
            Node *tempNode = treeRoot->leftChild;
            destroyNode(treeRoot);
            return tempNode;
        }

        //node with children
        Node *tempNode = getSuccessor(treeRoot->rightChild);
        treeRoot->value = tempNode->value;
        treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, tempNode->value);
    }
    return treeRoot;
}

Node *getSuccessor(Node *treeRoot)
{
    Node *theCurrent = treeRoot;

    while (theCurrent && theCurrent->leftChild != NULL)
        theCurrent = theCurrent->leftChild;

    return theCurrent;
}

void addNode(BinTree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	Node *theNode = createNode(aValue);
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
		Node *theCurrent = aTree->root;
		Node *theParent = NULL;

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

Node *findNode(BinTree *aTree, int aValue)
{
	Node *theCurrentNode = NULL;

	if (NULL != aTree->root)
	{
		theCurrentNode = aTree->root;	//start from root
		while (aValue != theCurrentNode->value) //walk through the tree
		{

			if (aValue < theCurrentNode->value)
				theCurrentNode = theCurrentNode->leftChild;
			else
				theCurrentNode = theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
				break;
		}
	}

	return theCurrentNode;
}

	//misc actions
void printBinTree(Node *aNode)
{
	if (NULL != aNode)
	{
		printBinTree(aNode->leftChild);
		printBinTree(aNode->rightChild);
		printf("[%d]\n", aNode->value);
	}
}
