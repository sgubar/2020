#ifndef TAT_H_INCLUDED
#define TAT_H_INCLUDED

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data);
void printList(const Node *head);
void deleteList(Node **head);
void fromArray(Node **head, int *arr, size_t size);
Node* removeDuplicates(Node *head);

#endif //TAT_H_INCLUDED
