#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "tool.h"

int main(int argc, char const *argv[])
{
    for(;;){
    int tree_elements_count =get_natural_int("Write down amount of elements:\n");
    Node **tree = malloc(sizeof(Node *));
    *tree = NULL;
    for (int i = 0; i < tree_elements_count; i++)
    {
        char label[50];
        snprintf(label, 50, "write down element #%d\n", i + 1);
        insert_node(tree, create_node(get_float(label)));

    }
    printf("\n");
    reversed_print(*tree);

    float value_for_search = get_float("Write down a number you are want to delete:\n");
    Node *result_node = search_value(*tree, value_for_search);

    printf("\n");

    if (result_node)
    {
        printf("Find node with searching value.\nNesting level: %d;\nPositon: %s node;\n", result_node->nesting, result_node->positon);
        delete_node(tree, result_node);
        printf("\n");
        reversed_print(*tree);
    }
    else
        printf("Node with given value does not exist\n");

    delete_tree(*tree);
    }
}
