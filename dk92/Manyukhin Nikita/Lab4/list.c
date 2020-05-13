#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

node* newnode(char value) {
  node* ret = (node*)malloc(sizeof(node));
  ret->value = value;
  ret->prev = NULL;
  ret->next = NULL;
  return ret;
}

node* listadd(node* s, char value) {
  if (s == NULL) {
    return newnode(value);
  }
  node* t = s;
  while (t->next != NULL) {
    t = t->next;
  }
  t->next = newnode(value);
  t->next->prev = t;
  return s;
}

void listprint(node* s) {
  if (s == NULL) {
    return;
  }
  printf("[");
  for (node* t = s; t != NULL; t = t->next) {
    printf("  %c", t->value);
  }
  printf(" ]\n");
}

node* read_list_from_file(const char* filename) {
  node* ret = NULL;

  char buf[100];

  FILE* f = fopen(filename, "r");
  fgets(buf, sizeof(buf), f);
  fclose(f);

  int len = strlen(buf);

  if (buf[len - 1] == '\n') {
    buf[--len] = '\0';
  }

  for (int i = 0; i < len; i++) {
    ret = listadd(ret, buf[i]);
  }

  return ret;
}

bool ispalindrome(node* leftmost) {
  if (leftmost == NULL) {
    return true;
  }

  node* rightmost = leftmost;
  while (rightmost->next != NULL) {
    rightmost = rightmost->next;
  }

  while (leftmost != rightmost) {
    if (leftmost->value != rightmost->value) {
      return false;
    }
    leftmost = leftmost->next;
    rightmost = rightmost->prev;
  }

  return true;
}
