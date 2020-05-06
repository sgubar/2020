#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    char val;
    struct list *next;
} List;

List *list_new(char val);
void list_add(List **list, char val);
void list_free(List *list);
void list_reverse(List **list);

#endif