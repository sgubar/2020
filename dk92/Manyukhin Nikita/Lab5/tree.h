#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct __Node
{
	char *name;
	struct __Node *leftChild;
	struct __Node *rightChild;
}Node;

typedef struct __Tree
{
	Node *root;
}Tree;

Tree *createTree();

void displayTree(Node *aNode);
void destroyShortTree(Tree *aTree);
Node *findNode(Tree *aTree, const char *aName);
void insertNode(Tree *aTree, char *aName);
int deleteNode(Tree *aTree, const char *aName);
