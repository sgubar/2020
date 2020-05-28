//
//  Functions.h
//  Laboratory Work 5
//
//  Created by Nazar Diadiun on 28.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#ifndef Functions_h
#define Functions_h

#include <stdio.h>
#include <stdlib.h>

struct bin_tree {
float data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void deltree(node * tree);
void print_inorder(node * tree);
node* search(node ** tree, float val);
void insert(node ** tree, float val);

#endif /* Functions_h */
