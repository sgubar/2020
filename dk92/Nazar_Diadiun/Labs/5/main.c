//
//  main.c
//  Laboratory Work 5
//
//  Created by Nazar Diadiun on 28.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include "Functions.h"


int main(int argc, const char * argv[]) {

    node *root;
    node *tmp;
    int NodesCount = 0;

    root = NULL;
    
    /* Inserting nodes into tree */
    
    printf("How much nodes do you want to fill: ");
    scanf("%d", &NodesCount);
    
    for(int count = 0; count < NodesCount; count++)
    {
        float DataToFill = 0.00;
        printf("Enter data: ");
        scanf("%f", &DataToFill);
        insert(&root, DataToFill);
    }

    /* Printing nodes of tree */
    printf("In Order Display\n");
    print_inorder(root);

    float WhatToFind = 0.00;
    printf("What do you want to find in tree: ");
    scanf("%f", &WhatToFind);

    // Search node into tree
    tmp = search(&root, WhatToFind);
    if (tmp)
        printf("Searched node = %f\n", tmp->data);
    else
        printf("Data Not found in tree.\n");

    /* Deleting all nodes of tree */
    deltree(root);
    
}
