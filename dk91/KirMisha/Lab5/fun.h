#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED

typedef float T;

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node* getFreeNode(T value, Node *parent);
Node *getNodeByValue(Node *root, T value);
Node* getMaxNode(Node *root);
Node* getMinNode(Node *root);
void removeNode(Node *target);
void insert(Node **head, float value);
void deleteValue(Node *root, T value);
void delete_tree(Node *root);
void release_node(Node *node);
void inorderPrint(Node *root);

#endif // FUN_H_INCLUDED
