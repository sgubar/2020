#ifndef func_h
#define func_h

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
 

typedef struct Node {
    Data data;
    struct Node* next;
}   Node;


void FillWithData(Node** list, const Data data); /
void Straight(const Node* list); 
void Reverse(const Node* list); 
#endif /* func_h */
