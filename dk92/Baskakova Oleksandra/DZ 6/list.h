#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node, *NodePtr;

typedef struct list
{
    int size;
    NodePtr head;
} List, *ListPtr;

ListPtr create_list();
int push_element(ListPtr list, int val);
int add_element_by_index(ListPtr list, int index, int val);
int remove_element(ListPtr list, int value);
void print_list(ListPtr list);
void free_list(List *list);
void quick_sort(ListPtr list);
void push_random_elements(ListPtr list, int size);

#endif