#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void main() {


    //LW5MANYUKHIN
	Tree *theTree = createTree();
	printf("Tree:\n");

	insertNode(theTree, "bbb");
	insertNode(theTree, "aaa");
	insertNode(theTree, "cca");
	insertNode(theTree, "ccc");
	insertNode(theTree, "abc");
	insertNode(theTree, "bba");
	insertNode(theTree, "bbc");

	displayTree(theTree->root);
	printf("\n");

	printf_s("Index of search element: %s", findNode(theTree, "bbc")->name);
	deleteNode(theTree, "bbc");
	printf("\nDelete Node: bbc\n");

	printf("Tree with deleted node:\n\n");
	displayTree(theTree->root);
	printf("\n");

	void destroyShortTree(theTree);
	return 0;
}
