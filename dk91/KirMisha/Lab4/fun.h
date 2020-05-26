#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node {
    Data data;
    struct Node* next;
}   Node;


void FillWithData(Node** list, const Data data);
void Straight(const Node* list);
void Reverse(const Node* list);
#endif // FUN_H_INCLUDED
