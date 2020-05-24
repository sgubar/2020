#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char const *argv[])								// каша в мейні
{
	Tree* theTree = createTree();			//створення дерева

	postOrderTravers(theTree->root);		// друк створеного дерева

	printf("\nVvedi iskaemoe 4islo : ");	// введення шуканого елементу дерева
	double val;
	scanf("%lf", &val);

	Node* tmp = SearchNode(theTree->root, val);  // пошук елемента дерева
	if(tmp)printf("%x\n", tmp);
	else printf("Elem -\n");

	printf("Vvedi 4islo rm : ");		// введення елементу для видалення
	scanf("%lf", &val);
	rmNode(theTree->root, val);

	postOrderTravers(theTree->root);		// друк дерева з видаленим елементом

	ClearNode(theTree->root);		// звільнення пом'яті від дерева
	free(theTree);

	return 0;
}
