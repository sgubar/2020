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

    Node *nodeToDel = FindNode(myTree, 4.5);

    DeleteNode(myTree, nodeToDel->value);
    PrintTree(myTree);

    DeleteNode(myTree, 11.4);
    DeleteNode(myTree, 15.7);
    DeleteTree(myTree);
    return 0;
}
