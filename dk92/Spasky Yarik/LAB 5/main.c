#include <stdio.h>
#include "dk_tool.h"

int main() {
    intTree *LAB5 = createIntTree();

    insertIntValueToTree(LAB5, 15);
    insertIntValueToTree(LAB5, 2);
    insertIntValueToTree(LAB5, 89);
    insertIntValueToTree(LAB5, 56);
    insertIntValueToTree(LAB5, 13);
    insertIntValueToTree(LAB5, 8);
    insertIntValueToTree(LAB5, 43);
    insertIntValueToTree(LAB5, 3);

    printTree(LAB5->root);
    printf("\n");

    printf("Find node : %d\n", findNodeWithValue(LAB5, 89)-> value);

    deleteValueFromTree(LAB5, 3);
    deleteValueFromTree(LAB5, 13);
    deleteValueFromTree(LAB5, 1);

    printTree(LAB5->root);
    printf("\n");

    deleteIntTree(LAB5);

}

