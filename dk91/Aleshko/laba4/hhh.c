#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "hhh.h"

List *init(char val)
{
	List *list = (List *)malloc(sizeof(List));
	list->field = val;
	list->next = NULL;
	list->prev = NULL;
	return list;
}
void addelem(List *list, char val)
{
  struct list *temp, *p;
  temp = (struct List*)malloc(sizeof(List));
  p = list->next;
  list->next = temp;
  temp->field = val;
  temp->next = p;
  temp->prev = list;
  if (p != NULL)
    p->prev = temp;
  return(temp);
}

void listprintr(List *list)
{
  struct list *p;
  p = list;
  while (p->next != NULL)
    p = p->next;
  do {
    printf("%c ", p->field);
    p = p->prev;
  } while (p != NULL);
}
void listprint(List *list)
{
  struct list *p;
  p = list;
  do {
    printf("%c ", p->field);
    p = p->next;
  } while (p != NULL);
}

List *load_from_file(char *path)
{
    FILE *file = fopen(path, "r");
    char c = fgetc(file);

    List *list = init(c);
    while (c != EOF)
    {
        c = fgetc(file);
        if (c == EOF)
            break;
        if (isalpha(c))
            addelem(list, c);
    }
    return list;
}
