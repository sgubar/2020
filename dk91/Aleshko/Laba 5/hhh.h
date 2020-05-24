#ifndef HIDK_H_INCLUDED
#define HIDK_H_INCLUDED

typedef int T;

#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

#define STACK_INIT_SIZE 100

typedef struct Stack {
    size_t size;
    size_t limit;
    Node **data;
} Stack;


Node* getFreeNode(T value, Node *parent);
Node *getNodeByValue(Node *root, T value);
Node* getMaxNode(Node *root);
Node* getMinNode(Node *root);
void removeNode(Node *target);
void insert(Node **head, int value);
void deleteValue(Node *root, T value);
void push(Stack *s, Node *item);
void freeStack(Stack **s);
void iterInorder(Node *root);
void delete_tree(Node *root);
void release_node(Node *node);

#endif // HIDK_H_INCLUDED
