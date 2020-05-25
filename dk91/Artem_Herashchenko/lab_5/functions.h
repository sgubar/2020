#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct intNode Node;

typedef struct intNode                             //структура дерева
{
  int value;
  Node *left;
  Node *right;
  Node *root;
}Node;

Node *create_node(Node *root, int *val);            //створення кореня

void add_node(Node **thetree, int *val);            //додавання елементу

int search(Node *thetree, int val);                 //пошук елементу

void delete_node(Node *root, int val);              //видалення елементу

Node *find_max_min(Node *root, int val);            //пошук max min елементів

Node *get_node_by_value(Node *root, int val);       //отримання значення вузла

void delete_target(Node *target);                   //пошук вузла для видалення

void tree_print(Node *thetree);                     //друк дерева

void tree_free(Node *thetree);                      //видалення дерева

#endif // FUNCTIONS_H_INCLUDED
