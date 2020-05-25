#ifndef KGK_H_INCLUDED
#define KGK_H_INCLUDED


typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data);
void printLinkedList(const Node *head);
void deleteList(Node **head);
void fromArray(Node **head, int *arr, size_t size);
void merge(Node *a, Node *b, Node **c);
void split(Node *src, Node **low, Node **high);
void mergeSort(Node **head);

#endif // KGK_H_INCLUDED
