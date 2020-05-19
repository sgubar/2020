#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void main() {
	TreePtr theTree = createTree();
	insertNode(theTree, "aaa");
	insertNode(theTree, "bbb");
	insertNode(theTree, "cca");
	insertNode(theTree, "aab");
	displayTree(theTree->root);
	system("pause");
	return 0;
}
