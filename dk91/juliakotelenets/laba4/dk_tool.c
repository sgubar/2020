#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"


Node* add(Node *root, char val)
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->value = val;   //creat new node
	head->next = root;
	root = head; //fiil node
	return root; //новый корень списка
}

void print(Node *root)
{
	while (root != NULL)
	{
		printf("%c", root->value); //вывод значиния элемента root
		root = root->next; //переход к следующему узлу
	}
	return;
}

void del(Node *root)
{
	Node *pre = root; //Node объекты которые хранятся в списке
	while (root != NULL)
	{
		pre = root; //предидущее значение root(корня)
		root = root->next; //следующее знаачение
	}
	free(pre); //освобождение памяти текущего корня
	return;
}

