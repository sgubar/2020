#include "func.h"

void FillWithData(Node** list, const Data data) {
    Node* node = malloc(sizeof(Node)); 
    node->data = data; 
    node->next = *list; 
    *list = node; 
}
void Straight(const Node* list) { 
    if (list) {
        printf("%d ", list->data);
        Straight(list->next);
    }
}
void Reverse(const Node* list) { 
    if (list) {
        Reverse(list->next);
        printf("%d ", list->data);
    }
}
