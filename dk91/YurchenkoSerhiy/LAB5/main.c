#include <stdio.h>
#include <stdlib.h>
#include "dk91.h"
int main() {
    DoubleTree *theTree = createDoubleTree();
    insertDoubleValueToTree(theTree,40.3);
    insertDoubleValueToTree(theTree,23.4);
    insertDoubleValueToTree(theTree,44);
    insertDoubleValueToTree(theTree,112.1);
    insertDoubleValueToTree(theTree,3.434);
    insertDoubleValueToTree(theTree,234.5);

    DoubleNode *SeachNode = findNodeWithValue(theTree,40.3);
    printf(" value =  %lf \n", SeachNode ->value );
    printTree(theTree);
    printf("\n");
    DoubleNode *NodeForDelete = theTree -> root;
    deleteNodeWithElement(theTree,NodeForDelete,23.4);
    printTree(theTree);
    destroyDoubleTree(theTree);
    return 0;
}
