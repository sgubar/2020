#include "tree.h"
#include <stdlib.h>
#include <string.h>

static void destroyNode(Node *aNode);
static Node *getSuccessor(Tree *aTree, Node *aDelNode);

Tree *createTree()
{
	Tree *theTree = (Tree*)malloc(sizeof(Tree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
	}

	return theTree;
}

void destroyShortTree(Tree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

Node *findNode(Tree *aTree, const char *aName)
{
	Node *theCurrentNode = aTree->root;
	int theComparisionResult = 0;

	while (0 != (theComparisionResult = strcmp(aName, theCurrentNode->name)))
	{
		theCurrentNode = (theComparisionResult < 0)
			? theCurrentNode->leftChild
			: theCurrentNode->rightChild;

		if (NULL == theCurrentNode)
		{
			break;
		}
	}

	return theCurrentNode;
}

void insertNode(Tree *aTree, char *aName)
{

	Node *theNewNode = (Node *)malloc(sizeof(Node));

	theNewNode->name = aName;
	theNewNode->leftChild = NULL;
	theNewNode->rightChild = NULL;

	if (NULL == aTree->root)
	{
		aTree->root = theNewNode;
	}
	else
	{
		Node *theCurrent = aTree->root;
		Node *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
			int theCompare = strcmp(aName, theCurrent->name);

			if (theCompare < 0)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNewNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNewNode;
					break;
				}
			}
		}
	}
}

int deleteNode(Tree *aTree, const char *aName)
{
	int theResult = 1;

	//1. Find assumed node to delete
	Node *theCurrent = aTree->root;
	Node *theParent = aTree->root;

	int isLeftChild = 1;
	int theCompare = 0;

	while (0 != (theCompare = strcmp(aName, theCurrent->name)))
	{
		theParent = theCurrent;
		if (theCompare < 0)
		{
			isLeftChild = 1; //<!- go to the left
			theCurrent = theCurrent->leftChild;
		}
		else
		{
			isLeftChild = 0; //<!- right node
			theCurrent = theCurrent->rightChild;
		}

		if (NULL == theCurrent)
		{
			// the node is node found
			return 0;
		}
	}

	//if the node does not have children then just remove it
	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = NULL;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = NULL;
		}
		else
		{
			theParent->rightChild = NULL;
		}
	}
	else if (NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = theCurrent->leftChild;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = theCurrent->leftChild;
		}
		else
		{
			theParent->rightChild = theCurrent->leftChild;
		}
	}
	else if (NULL == theCurrent->leftChild)
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = theCurrent->rightChild;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = theCurrent->rightChild;
		}
		else
		{
			theParent->rightChild = theCurrent->rightChild;
		}
	}
	else
	{
		Node *theSuccessor = getSuccessor(aTree, theCurrent);
		if (aTree->root == theSuccessor)
		{
			aTree->root = NULL;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = theSuccessor;
		}
		else
		{
			theParent->rightChild = theSuccessor;
		}

	}

	theResult = 1;

	return theResult;
}

Node *getSuccessor(Tree *aTree, Node *aDelNode)
{
	Node *theSuccessParent = aDelNode;
	Node *theSuccessor = aDelNode;
	Node *theCurrent = aDelNode->rightChild;

	while (NULL != theCurrent)
	{
		theSuccessParent = theSuccessor;
		theSuccessor = theCurrent;
		theCurrent = theCurrent->leftChild;
	}

	if (theSuccessor != aDelNode->rightChild)
	{
		theSuccessParent->leftChild = theSuccessor->rightChild;
		theSuccessor->rightChild = aDelNode->rightChild;
	}

	return theSuccessor;
}

void displayTree(Node *aNode) {
	if (!aNode) return;
    if (aNode->name) printf_s("%s \n", aNode->name);
	displayTree(aNode->leftChild);
	displayTree(aNode->rightChild);
}

void destroyNode(Node *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}
