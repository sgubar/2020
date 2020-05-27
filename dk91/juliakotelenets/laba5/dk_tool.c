#include <stdlib.h>
#include "dk_tool.h"

static void deleteNode(doubleNode *aNode);
static doubleNode *createNodeWithDoubleValue(double value);

doubleTree *createDoubleTree()
{
    doubleTree *newTree = (doubleTree*)malloc(sizeof(doubleTree));

    if(newTree != NULL)//!<- перевірити правильність розподілу пам'яті
    {
        newTree->root = NULL;//!<- за замовчуванням корінь є нульовим - дерево порожнє
        newTree->count = 0;
    }

    return newTree;
}

void deleteDoubleTree(doubleTree *aTree)
{
    deleteNode(aTree->root);
    free(aTree);
}

static void deleteNode(doubleNode *aNode)
{
    if (NULL != aNode)
    {
        deleteNode(aNode->leftChild);
        deleteNode(aNode->rightChild);

        free(aNode);
    }
}

static doubleNode *createNodeWithDoubleValue(double value)
{
    doubleNode *newNode = (doubleNode*)malloc(sizeof(doubleNode));

    if(NULL != newNode)
    {
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->value = value;
    }

    return newNode;
}

void insertDoubleValueToTree(doubleTree *aTree, double aValue)
{
    if (NULL == aTree)
            return;

    doubleNode *theNode = createNodeWithDoubleValue(aValue);
    if (NULL == theNode)
            return;

    if (NULL == aTree->root) //<! - дерево порожнє, тому корінь - наш вузол
            aTree->root = theNode;
       else
    {
        // почніть пошук відповідного місця, щоб встановити новий вузол
        doubleNode *theCurrent = aTree->root;
        doubleNode *theParent = NULL;

        while (1)
        {
            theParent = theCurrent;

            if (aValue < theCurrent->value)
            {
                theCurrent = theCurrent->leftChild;
                if (NULL == theCurrent)//<!- наше місце : шлях закінчений
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


    }
     aTree->count ++;
}



doubleNode *findNodeWithValue(doubleTree *aTree, double aValue)
{
    doubleNode *theCurrentNode = NULL;

    if (NULL != aTree)
    {
        theCurrentNode = aTree->root; //<! - починати з кореня
        while (aValue != theCurrentNode->value)
        {
            theCurrentNode = (aValue < theCurrentNode->value)
                             ? theCurrentNode->leftChild //<! - починати з кореня
                             : theCurrentNode->rightChild; //<! - ходити по дереву

            if (NULL == theCurrentNode)
            {
                printf("not found");
                break;
            }
        }
    }

    return theCurrentNode;
}

doubleNode *getSuccessor(doubleTree *aTree, doubleNode *aDelNode)
{
    doubleNode *theSuccessorParent = aDelNode;
    doubleNode *theSuccessor = aDelNode;
    doubleNode *theCurrent = aDelNode->rightChild;//<! - спочатку переходьте до правої дитини, поки присутні ліві діти


    while (NULL != theCurrent)
    {
        theSuccessorParent = theSuccessor;
        theSuccessor = theCurrent;
        theCurrent = theCurrent->leftChild;
    }

    if (theSuccessor != aDelNode->rightChild)
    {
        theSuccessorParent->leftChild = theSuccessor->rightChild;
        theSuccessor->rightChild = aDelNode->rightChild;
    }

    return theSuccessor;
}

double deleteValueFromTree(doubleTree *aTree, double aValue)
{
    double theResult = 1;
    //1. знайти припущений вузол для видалення
    doubleNode * theCurrent = aTree->root;
    doubleNode * theParent = aTree->root;

    double LeftChild = 1;

    while (aValue != theCurrent->value)
    {
        theParent = theCurrent;
        if (aValue < theCurrent->value)
        {
            LeftChild = 1;  //<!- go to the left
            theCurrent = theCurrent->leftChild;
        }
        else
        {
            LeftChild = 0;  //<!- right node
            theCurrent = theCurrent->rightChild;
        }

        if (NULL == theCurrent)
        {
            // вузол не знайдено
            return 0;
        }
    }
    //якщо у вузла немає дітей, просто видаліть його
    if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
    {
        if (aTree->root == theCurrent)
                    aTree->root = NULL;

        else if (LeftChild)
                    theParent->leftChild = NULL;

        else
                    theParent->rightChild = NULL;

    }
    else if (NULL == theCurrent->rightChild)
    {
        if (aTree->root == theCurrent)
                    aTree->root = theCurrent->leftChild;

        else if (LeftChild)
                    theParent->leftChild = theCurrent->leftChild;

        else
                    theParent->rightChild = theCurrent->leftChild;

    }
    else if (NULL == theCurrent->leftChild)
    {
        if (aTree->root == theCurrent)
                    aTree->root = theCurrent->rightChild;

        else if (LeftChild)
                    theParent->leftChild = theCurrent->rightChild;

        else
                    theParent->rightChild = theCurrent->rightChild;

    }
    else
    {
        doubleNode * theSuccessor = getSuccessor(aTree, theCurrent);
        if (aTree->root == theSuccessor)
                    aTree->root = NULL;

        else if (LeftChild)
                    theParent->leftChild = theSuccessor;

        else
                    theParent->rightChild = theSuccessor;

    }

    free(theCurrent);
    theResult = 1;

    return theResult;
}

void printTree(doubleNode *aRoot)
{
    if(aRoot==NULL)
            return;

    printTree(aRoot->leftChild);
    printf("%f " , aRoot->value);
    printTree(aRoot->rightChild);


}
