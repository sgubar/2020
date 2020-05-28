#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *left_node, *right_node;
    float value;
    int nesting;
    char* positon;

} Node;

Node *create_node(float value);
void reversed_print(Node *n);
void insert_node(Node **root, Node *child);
Node *search_value(Node *root, float value);
int delete_node(Node **root, Node *node_to_delete);
void delete_tree(Node *root);

#endif //TREE_H