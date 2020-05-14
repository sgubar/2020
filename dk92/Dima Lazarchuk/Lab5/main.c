#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	DoubleTree *tree = createDoubleTree();
	insertDoubleValueToTree(tree, 10);
	insertDoubleValueToTree(tree, 2.5);
	insertDoubleValueToTree(tree, 1.25);
	insertDoubleValueToTree(tree, 12.5);
	insertDoubleValueToTree(tree, 11.25);
	insertDoubleValueToTree(tree, 13);
	printTree(tree);
	return 0;
}
