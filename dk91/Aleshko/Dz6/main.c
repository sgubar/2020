#include <stdio.h>
#include <stdlib.h>
#include "kgk.h"

int main()
{
  Node* head = NULL;
  int arr[] = {65,2,12,90,436,6,56,239,85,150};
  fromArray(&head, arr, 10);
  printLinkedList(head);
  printf("\n");
  mergeSort(&head);
  printLinkedList(head);
  deleteList(&head);

}
