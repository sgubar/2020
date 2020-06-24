#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tat.h"

void push(Node **head, int data)//вставка елементу в початок списку
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void printList(const Node *head)
{
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void deleteList(Node **head)
{
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}
void fromArray(Node **head, int *arr, size_t size)
{
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}

Node* removeDuplicates(Node *head)
{
    Node *t, *p, *i, *prev;
    for(p = head; p != NULL; p = p->next)
    {
        prev = p;
        for(i = p->next; i != NULL; )
        {
            if(i->value == p->value)
            {
                t = prev->next = i->next;
                free(i);
                i = t;
                continue;
            }
            prev = i;
            i = i->next;
        }
    }
    return head;
}
