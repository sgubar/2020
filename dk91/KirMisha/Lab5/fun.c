#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

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
        if (root->data > value) {
            root = root->left;
            continue;
        } else if (root->data < value) {
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
void insert(Node **head, float value)
{
    Node *tmp = NULL;
    Node *ins = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
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
void inorderPrint(Node *root)
{
    if (root == NULL)
    {
       return;
    }
    inorderPrint(root->left);
    printf("%.2f\n", root->data);
    inorderPrint(root->right);
}
void release_node(Node *node)
{
    if (node)
    {
        if (node->parent)
            free(node->parent);
        free(node);
    }
}
void delete_tree(Node *root)
{
    if (root->left)
        delete_tree(root->left);
    if (root->right)
        delete_tree(root->right);

    release_node(root);
}
