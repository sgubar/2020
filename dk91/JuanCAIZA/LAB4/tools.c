#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "linked_list.h"

List *load_from_file(char *path)
{
    FILE *file = fopen(path, "r");
    char c = fgetc(file);

    List *list = list_new(c);
    while (c != EOF)
    {
        c = fgetc(file);
        if (c == EOF)
            break;
        if (isalpha(c))
            list_add(&list, c);
    }
    return list;
}

void write_to_file(List *list, char *path)
{
    FILE *file = fopen(path, "w");
    for (; list != NULL; list = list->next)
    {
        putc(list->val, file);
    }
}
