#include "linked_list.h"

List *list_new(char val)
{
	List *list = (List *)malloc(sizeof(List));
	list->val = val;
	list->next = NULL;
	return list;
}

void list_add(List **list, char val)
{
	for (; *list != NULL; list = &(*list)->next)
		;
	*list = list_new(val);
}

void list_reverse(List **list)
{
	List *prev = NULL;
	List *current = *list;
	List *next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
}
