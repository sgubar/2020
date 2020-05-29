#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"


Node *add(Node *root, char val)
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->value = val;
	head->next = root;
	root = head;
	return root;
}

void print(Node *root)
{
	while (root != NULL)
	{
		printf("%c", root->value);
		root = root->next;
	}
	return;
}

void del(Node *root)
{
	Node *pre = root;
	while (root != NULL)
	{
		pre = root;
		root = root->next;
	}
	free(pre);
	return;
}
