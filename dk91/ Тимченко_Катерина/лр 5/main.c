#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree *myTree = CreateTree();

    AddNode(myTree, 11.4);
    AddNode(myTree, 15.7);
    AddNode(myTree, 4.5);

    PrintTree(myTree);

    printf("\nIndex of search element: %d\n", FindNode(myTree, 4.5)->value);
    Node *nodeToDel = FindNode(myTree, 4.5);
    printf("\nDelete node 4.5\n\n");

    DeleteNode(myTree, nodeToDel->value);
    PrintTree(myTree);
    printf("\nDelete nodes 11.4 and 15.7\n");

    DeleteNode(myTree, 11.4);
    DeleteNode(myTree, 15.7);
    PrintTree(myTree);
    DeleteTree(myTree);
    return 0;
}
