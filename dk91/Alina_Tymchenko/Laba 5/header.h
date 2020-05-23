#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <ncurses.h>

//structures
typedef struct tagNode Node;

struct tagNode
{
	int value;
	Node *leftChild;
	Node *rightChild;
};

typedef struct tagBinTree
{
	Node *root;
	int count;
}BinTree;

//tree functions
	//creation & destruction
BinTree *createBinTree();
void destroyBinTree(BinTree *aTree);
Node *createNode(int aValue);
void destroyNode(Node *aNode);

	//operations
Node *destroyTreeNode(Node *treeRoot, int aValue);
Node *getSuccessor(Node *treeRoot);
void addNode(BinTree *aTree, int aValue);
Node *findNode(BinTree *aTree, int aValue);

	//misc actions
void printBinTree(Node *aNode);
void debugTree(BinTree *ATree);

#endif // HEADER_H_INCLUDED
