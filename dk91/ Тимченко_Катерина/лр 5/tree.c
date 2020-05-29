#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

Node *getSuccessor(Tree *myTree, Node *nodeToDel);
void inorder(Node *myNode);

Tree *CreateTree()
{
    Tree *myTree = (Tree *)malloc(sizeof(Tree));
    if(myTree != NULL)
    {
        myTree->root = NULL;
        myTree->count = 0;
    }
    return myTree;
}

void DeleteTree(Tree *myTree)
{
    free(myTree);
}

void AddNode(Tree *myTree, float value)
{
    Node *myNode = (Node *)malloc(sizeof(Node));
    myNode->value = value;
    myNode->rightChild = NULL;
    myNode->leftChild = NULL;
    if(myTree->root == NULL)
    {
        myTree->root = myNode;
        myTree->count++;
    }
    else
    {
        Node *child = myTree->root;
        Node *parent = child;
        while(1)
        {
            if(value < parent->value)
            {
                child = parent->leftChild;
                if(child == NULL)
                {
                    parent->leftChild = myNode;
                    break;
                }
            }
            else
            {
                child = parent->rightChild;
                if(child == NULL)
                {
                    parent->rightChild = myNode;
                    break;
                }
            }
            parent = child;
        }
    }
}

Node *FindNode(Tree *myTree, float value)
{
    Node *myNode = myTree->root;
    if(myTree->root == NULL)
    {
        printf("\nThere are no nodes in your tree\n");
        return NULL;
    }
    else
    {
        while(value != myNode->value)
        {
            if(value < myNode->value)
            {
                if(myNode->leftChild != NULL)
                {
                    myNode = myNode->leftChild;
                }
                else
                {
                    printf("\nThere is no such node in this tree\n");
                }
            }
            else
            {
                if(myNode->rightChild != NULL)
                {
                    myNode = myNode->rightChild;
                }
                else
                {
                    printf("\nThere is no such node in this tree\n");
                }
            }
        }
        return myNode;
    }
}

void DeleteNode(Tree *myTree, float value)
{

	Node *child = myTree->root;
	Node *parent = myTree->root;

	int isLeftChild = 1;

	while (value != child->value)
	{
		parent = child;
		if (value < child->value)
		{
			isLeftChild = 1;
			child = child->leftChild;
		}
		else
		{
			isLeftChild = 0;
			child = child->rightChild;
		}

		if (NULL == child)
		{
			break;
		}
	}

	if (child->leftChild == NULL && child->rightChild == NULL)
	{
		if (myTree->root == child)
		{
			myTree->root = NULL;
		}
		else if (isLeftChild)
		{
			parent->leftChild = NULL;
		}
		else
		{
			parent->rightChild = NULL;
		}
	}
	else if (child->rightChild == NULL)
	{
		if (myTree->root == child)
		{
			myTree->root = child->leftChild;
		}
		else if (isLeftChild)
		{
			parent->leftChild = child->leftChild;
		}
		else
		{
			child->rightChild = child->leftChild;
		}
	}
	else if (child->leftChild == NULL)
	{
		if (myTree->root == child)
		{
			myTree->root = child->rightChild;
		}
		else if (isLeftChild)
		{
			parent->leftChild = child->rightChild;
		}
		else
		{
			parent->rightChild = child->rightChild;
		}
	}
	else
	{
		Node *successor = getSuccessor(myTree, child);
		if (myTree->root == successor)
		{
			myTree->root = NULL;
		}
		else if (isLeftChild)
		{
			parent->leftChild = successor;
		}
		else
		{
			parent->rightChild = successor;
		}

	}
	free(child);
}

Node *getSuccessor(Tree *myTree, Node *nodeToDel)
{
	Node *parent = nodeToDel;
	Node *successor = nodeToDel;
	Node *child = nodeToDel->rightChild;
	while (NULL != child)
	{
		parent = successor;
        successor = child;
		child = child->leftChild;
	}

	if (successor != nodeToDel->rightChild)
	{
		parent->leftChild = successor->rightChild;
		successor->rightChild = nodeToDel->rightChild;
	}

	return successor;
}

void PrintTree(Tree *myTree)
{
    if(myTree->root == NULL)
    {
        printf("\nThe tree is empty\n");
        return;
    }
    Node *myNode = myTree->root;
    inorder(myNode);
}

void inorder(Node *myNode)
{
    if(myNode == NULL)
        return;
    inorder(myNode->leftChild);
    if(myNode->value)
        printf("%.2f\n", myNode->value);
    inorder(myNode->rightChild);
}
