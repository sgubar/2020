#ifndef LIST_H
#define LIST_H
#include <stdbool.h>


typedef struct node node;
struct node {
  char value;
  node* prev;
  node* next;
};

node* newnode(char value);
node* listadd(node* s, char value);
void listprint(node* s);
node* read_list_from_file(const char* filename);
bool ispalindrome(node* leftmost);

#endif

