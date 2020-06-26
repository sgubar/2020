#include "dk91.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Node *createNode(char value)
{
    Node *result = (Node *) malloc(sizeof(Node));

    result->value = value;
    result->next = NULL;

    return result;
}

void deleteNode(Node *node)
{
    if (NULL != node)
    {
        free(node);
    }
}

void printNode(Node *node)
{
    if(node != NULL)
    {
        printf("%c ", node->value);
    }
}

List *createList()
{

    List *list = (List *) malloc(sizeof(List));


    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}

void deleteList(List *list)
{
    if (NULL == list)
    {
        return;
    }
    Node *node = list->head;

    while (NULL != node)
    {
        Node *nodeToBeRemoved = node;
        node = node->next;

        deleteNode(nodeToBeRemoved);
    }
    free(list);
}

Node *addNode(List *list, Node *newNode)
{
    if (NULL == list || NULL == newNode)
    {
        return NULL;
    }

    if (NULL == list->head && NULL == list->tail)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        Node *tail = list->tail;
        list->tail = newNode;

        if (NULL != tail)
        {
            tail->next = list->tail;
        }
    }

    list->count += 1;

    return newNode;
}

Node *getNodeAtIndex(const List *list, int index)
{
    Node *theResult = NULL;

    if (NULL != list && index < list->count)
    {
        int i = 0;
        Node *node = list->head;

        do
        {
            if (i == index)
            {
                theResult = node;
                break;
            }

            i++;
            node = node->next;

        } while (NULL != node);
    }

    return theResult;
}

void printList(const List *list)
{
    if (NULL == list)
        return;
    for(int i=0; i<list->count; i++)
    {
        printNode(getNodeAtIndex(list, i));
    }
}

int listCount(List *list)
{
    int result = -1;
    if (NULL != list)
    {
        result = list->count;
    }
    return result;
}

int bracketBallanceCheck(FILE *aFile)
{
    if(aFile != NULL)
    {
        List *openList = createList();
        List *closeList = createList();

        int checkPoint = 0;
        do
        {
            checkPoint = getc(aFile);
            if(checkPoint == '{')
            {
                Node *openBracketNode = createNode('{');
                addNode(openList, openBracketNode);
            }

            if(checkPoint == '}')
            {
                Node *closeBracketNode = createNode('}');
                addNode(closeList, closeBracketNode);
            }

        }
        while(checkPoint != EOF);

        if(listCount(openList) == listCount(closeList))
        {
            deleteList(openList);
            deleteList(closeList);
            return 0;
        }

        deleteList(openList);
        deleteList(closeList);
        return 1;
    }
    return 2;
}
