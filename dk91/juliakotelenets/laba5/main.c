#include <stdio.h>
#include "dk_tool.h"

int main() {
    doubleTree *derevo = createDoubleTree();

    printf("Tree: \n");

    insertDoubleValueToTree(derevo, 15);
    insertDoubleValueToTree(derevo, 2.992);
    insertDoubleValueToTree(derevo, 89.31);
    insertDoubleValueToTree(derevo, 56);
    insertDoubleValueToTree(derevo, 13.49987);
    insertDoubleValueToTree(derevo, 8);
    insertDoubleValueToTree(derevo, 43.332);
    insertDoubleValueToTree(derevo, 3);

    printTree(derevo->root);
    printf("\n");

    printf("\nFind node : %f\n", findNodeWithValue(derevo, 13.49987)-> value);

    printf("\nTree with delete value: \n");
    deleteValueFromTree(derevo, 3);
    deleteValueFromTree(derevo, 43.332);
    deleteValueFromTree(derevo, 89.31);

    printTree(derevo->root);
    printf("\n");

    deleteDoubleTree(derevo);
}

