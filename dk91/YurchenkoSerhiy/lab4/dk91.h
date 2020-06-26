#ifndef tool_4
#define Tool_4
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char value;
    struct node *next;
} Node;

Node *createNode(char value);

void deleteNode(Node *node);

typedef struct list
{
    Node *head;
    Node *tail;
    int count;
} List;

void deleteNode(Node *node);

void printNode(Node *node);

void deleteList(List *list);

List *createList(void);

Node *addNode(List *list, Node *newNode);

void printList(const List *list);

int listCount( List *list);

int bracketBallanceCheck(FILE *aFile);

#endif
