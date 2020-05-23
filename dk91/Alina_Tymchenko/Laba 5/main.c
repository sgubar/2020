#include <stdio.h>
#include "header.h"
#define MAXSIZE 5



int main(int argc, char **argv)
{
	srand(time(NULL));

	//making a tree
	BinTree *ATree = createBinTree();

	debugTree(ATree);

	printBinTree(ATree->root);

	if (NULL != findNode(ATree, 16))
		printf("Required node: %d\n", findNode(ATree, 16)->value);
	else
		printf("Node not found.\n");

	destroyBinTree(ATree);

	return 0;
}

