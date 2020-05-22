#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *left_node, *right_node;
    int value;
     //added only for displaying purpose
    int nesting;
    char* positon;

} Node;

Node *create_node(int value);
void symetric_print(Node *n);
void insert_node(Node **root, Node *child);
Node *search_value(Node *root, int value);
int delete_node(Node **root, Node *node_to_delete);
void delete_tree(Node *root);

