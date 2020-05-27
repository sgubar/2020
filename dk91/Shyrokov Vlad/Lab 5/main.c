#include <stdio.h>

#include <stdlib.h>

#include "Tree.h"



int main()



{

    DoubleTree* theTree=createDoubleTree();

    insertDoubleValueToTree(theTree,4);

    insertDoubleValueToTree(theTree,6);

    insertDoubleValueToTree(theTree,0.25);

    insertDoubleValueToTree(theTree,2);

    PrintTreeInPreOrder(theTree->root);

   deleteNodeWithValue(theTree,0.25);

    printf("\n");





    PrintTreeInPreOrder(theTree->root);

    destroyDoubleTree(theTree);

    //printf("Hello world!\n");

    return 0;

}
