#ifndef RER_H_INCLUDED
#define RER_H_INCLUDED

typedef double T;

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
void insert(Node **head, double value);
void deleteValue(Node *root, T value);
void delete_tree(Node *root);
void release_node(Node *node);
void preorderPrint(Node *root);

#endif // RER_H_INCLUDED
