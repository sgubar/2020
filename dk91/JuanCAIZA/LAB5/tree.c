#define ROOT 2
#define LEFT_CHILD 1
#define RIGHT_CHILD 0
#define NOT_A_CHILD -1

#include "tree.h"

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->nesting = 0;
    node->positon = "root";
    node->left_node = node->right_node = NULL;
    return node;
}

void symetric_print(Node *node)
{
    if (node->left_node)
        symetric_print(node->left_node);
    printf("nesting: %d, %s node, value: %d \n", node->nesting, node->positon, node->value);
    if (node->right_node)
        symetric_print(node->right_node);
}

void insert_node(Node **root, Node *child)
{
    if (!*root)
        *root = child;
    else
    {
        Node **node_socket = NULL;
        child->nesting = (*root)->nesting + 1;
        if (child->value < (*root)->value)
        {
            child->positon = "left";
            node_socket = &(*root)->left_node;
        }
        else
        {
            child->positon = "right";
            node_socket = &(*root)->right_node;
        }

        insert_node(node_socket, child);

        // insert_node(child->value <= (*root)->value ? &(*root)->left_node : &(*root)->right_node, child);
    }
}

Node *search_value(Node *root, int value)
{
    return !root ? NULL : root->value == value ? root : search_value(value >= root->value ? root->right_node : root->left_node, value);
}

void release_node(Node *node)
{
    if (node)
    {
        if (node->positon)
            free(node->positon);
        free(node);
    }
}

void update_parent_node(Node **parent_node, Node *new_node, int node_position)
{
    if (node_position == ROOT)
    {
        *parent_node = new_node;
    }
    else if (node_position == LEFT_CHILD)
    {
        (*parent_node)->left_node = new_node;
    }
    else
    {
        (*parent_node)->right_node = new_node;
    }
}

int delete_node(Node **root, Node *node_to_delete)
{
    if ((*root) == NULL)
        return 0;

    int node_position = (*root)->left_node == node_to_delete ? LEFT_CHILD : (*root)->right_node == node_to_delete ? RIGHT_CHILD : (*root) == node_to_delete ? ROOT : NOT_A_CHILD;

    if (node_position != NOT_A_CHILD)
    {
        if (node_to_delete->left_node && node_to_delete->right_node)
        {
            Node *parrent_node = *root;
            Node *current_node = node_to_delete->right_node;

            while (current_node->left_node)
            {
                parrent_node = current_node;
                current_node = current_node->left_node;
            }

            if (current_node->right_node && node_to_delete->right_node != current_node)
            {
                parrent_node->left_node = current_node->right_node;
            }
            if (node_to_delete->right_node != current_node)
                current_node->right_node = node_to_delete->right_node;

            current_node->left_node = node_to_delete->left_node;

            update_parent_node(root, current_node, node_position);
        }
        else if (node_to_delete->right_node || node_to_delete->left_node)
        {
            update_parent_node(root, node_to_delete->left_node ? node_to_delete->left_node : node_to_delete->right_node, node_position);
        }
        else
        {
            update_parent_node(root, NULL, node_position);
        }

        release_node(node_to_delete);
        return 1;
    }
    else
    {
        int result = delete_node(&(*root)->left_node, node_to_delete) + delete_node(&(*root)->right_node, node_to_delete);
        return result > 0;
    }
}

void delete_tree(Node *root)
{
    if (root->left_node)
        delete_tree(root->left_node);
    if (root->right_node)
        delete_tree(root->right_node);

    release_node(root);
}
