#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct __PhoneNote
{
	char *name;
}PhoneNote, *PhoneNotePtr;

typedef struct __Node
{
	PhoneNotePtr note;
	struct __Node *leftChild;
	struct __Node *rightChild;
}Node, *NodePtr;

typedef struct __Tree
{
	NodePtr root;
}Tree, *TreePtr;

TreePtr createTree();

void displayTree(NodePtr aNode);

NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName);
int deleteNode(TreePtr aTree, const char *aName);
