#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "hhh.h"


Node* getFreeNode(T value, Node *parent)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

Node *getNodeByValue(Node *root, T value)
{
    while (root) {
        if (CMP_GT(root->data, value)) {
            root = root->left;
            continue;
        } else if (CMP_LT(root->data, value)) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}
Node* getMinNode(Node *root)
{
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* getMaxNode(Node *root)
{
    while (root->right) {
        root = root->right;
    }
    return root;
}
void removeNode(Node *target)
{
    if (target->left && target->right) {
        Node *localMax = getMaxNode(target->left);
        target->data = localMax->data;
        removeNode(localMax);
        return;
    } else if (target->left) {
        if (target == target->parent->left) {
            target->parent->left = target->left;
        } else {
            target->parent->right = target->left;
        }
    } else if (target->right) {
        if (target == target->parent->right) {
            target->parent->right = target->right;
        } else {
            target->parent->left = target->right;
        }
    } else {
        if (target == target->parent->left) {
            target->parent->left = NULL;
        } else {
            target->parent->right = NULL;
        }
    }
    free(target);
}

void deleteValue(Node *root, T value) {
    Node *target = getNodeByValue(root, value);
    removeNode(target);
}
void insert(Node **head, int value)
{
    Node *tmp = NULL;
    Node *ins = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp) {
        if (CMP_GT(value, tmp->data)) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (CMP_LT(value, tmp->data)) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } else {
            exit(2);
        }
    }
}

void printTree(Node *root, const char *dir, int level)
{
    if (root) {
        printf("lvl %d %s = %d\n", level, dir, root->data);
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
    }
}
Stack* createStack() {
    Stack *tmp = (Stack*) malloc(sizeof(Stack));
    tmp->limit = STACK_INIT_SIZE;
    tmp->size = 0;
    tmp->data = (Node**) malloc(tmp->limit * sizeof(Node*));
    return tmp;
}
void freeStack(Stack **s) {
    free((*s)->data);
    free(*s);
    *s = NULL;
}

void push(Stack *s, Node *item) {
    if (s->size >= s->limit) {
        s->limit *= 2;
        s->data = (Node**) realloc(s->data, s->limit * sizeof(Node*));
    }
    s->data[s->size++] = item;
}

Node* pop(Stack *s) {
    if (s->size == 0) {
        exit(7);
    }
    s->size--;
    return s->data[s->size];
}

Node* peek(Stack *s) {
    return s->data[s->size-1];
}
void iterInorder(Node *root) {
    Stack *ps = createStack();
    while (ps->size != 0 || root != NULL) {
        if (root != NULL) {
            push(ps, root);
            root = root->left;
        } else {
            root = pop(ps);
            printf("visited %d\n", root->data);
            root = root->right;
        }
    }
    freeStack(&ps);
}
