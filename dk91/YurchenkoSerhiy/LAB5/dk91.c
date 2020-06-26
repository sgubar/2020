#include "dk91.h"
#include <stdio.h>
#include <stdlib.h>
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
        DoubleNode *theCurrentNode = aTree->root;
        while (aValue != theCurrentNode->value)
        {
            theCurrentNode = (aValue < theCurrentNode->value)
                             ? theCurrentNode->leftChild
                             : theCurrentNode->rightChild;
            if (NULL == theCurrentNode)
            {
                break;
            }
        }
        return theCurrentNode;
    }
    return theCurrentNode;
}


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

void postOrder(DoubleNode *aNode)
{
    if(aNode != NULL)
    {
        postOrder(aNode ->leftChild);
        postOrder(aNode -> rightChild);
        printf("%lf ",aNode ->value);

    }
}
void printTree (DoubleTree *aTree)
{
    DoubleNode *theCurrentNode = aTree->root;
    if(aTree != NULL)
    {
        postOrder(theCurrentNode);
    }
}

DoubleNode* FindMin(DoubleNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

DoubleNode* deleteNodeWithElement(DoubleTree *aDrevo,DoubleNode* aNode, double aElement)
{
    if (aNode == NULL) {
        return NULL;
    }
    else if (aElement < aNode->value)
        aNode->leftChild = deleteNodeWithElement(aDrevo,aNode->leftChild, aElement);
    else if (aElement > aNode->value)
        aNode->rightChild = deleteNodeWithElement(aDrevo , aNode->rightChild, aElement);
    else
    {
        if (aNode->leftChild == NULL && aNode->rightChild == NULL)
        {
            free(aNode);
            aNode = NULL;
            aDrevo->count--;
        }
        else if (aNode->leftChild == NULL)
        {
            DoubleNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aDrevo->count--;
        }
        else if (aNode->rightChild == NULL)
        {
            DoubleNode *theTmp = aNode;
            aNode = aNode->leftChild;
            free(theTmp);
            aDrevo->count--;
        }
        else
        {
            DoubleNode *theTmp = FindMin(aNode->rightChild);
            aNode->value = theTmp->value;
            aNode->rightChild = deleteNodeWithElement(aDrevo, aNode->rightChild,theTmp->value);
            aDrevo->count--;
        }
    }
    return aNode;
}
