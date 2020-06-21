#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main()
{
    Node *root = NULL;
    insert(&root, 10.2);
    insert(&root, 12.1);
    insert(&root, 56.44);
    insert(&root, 8.4);
    insert(&root, 9.7);
    insert(&root, 7.9);
    insert(&root, 3.8);
    insert(&root, 4.7);
    inorderPrint(root);
    printf("------------------\n");
    printf("max = %.2f\n", getMaxNode(root)->data);
    printf("min = %.2f\n", getMinNode(root)->data);
    deleteValue(root, 4.7);
    deleteValue(root, 8.4);
    printf("------------------\n");
    deleteValue(root, 10.2);
    inorderPrint(root);
    delete_tree(root);
}
