#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{

	Node *thetree = NULL;

	int val = 0;


    add_node(&thetree, 50);                         //створення дерева
    add_node(&thetree, 30);
    add_node(&thetree, 60);
    add_node(&thetree, 20);
    add_node(&thetree, 40);
    add_node(&thetree, 54);
    add_node(&thetree, 64);
    add_node(&thetree, 17);
    add_node(&thetree, 25);
    add_node(&thetree, 35);
    add_node(&thetree, 45);
    add_node(&thetree, 52);
    add_node(&thetree, 55);
    add_node(&thetree, 62);
    add_node(&thetree, 67);


    printf("Tree:\n");                            //друк дерева
    tree_print(thetree);


    printf("\n\nEnter element to search:");           //пошук елементу
    scanf("%d", &val);
    if(search(thetree, val) == 1)
    printf("=====Found!=====");
    else
    printf("=====Not found=====");


    printf("\n\nEnter the element to be deleted from the tree:");           //видалення елементу
    scanf("%d", &val);
    delete_node(thetree, val);


    printf("\nTree with deleted element:\n");        //друк дерева з видаленим елементом
    tree_print(thetree);


    tree_free(thetree);                              //видалення дерева
    printf("\n\n=====Tree deleted!=====");
    return 0;

}
