#include <stdio.h>
#include <stdlib.h>
#include "tat.h"

int main()
{
  Node* head = NULL;
  int arr[] = {65,2,26,4,15,26,65,279,65,150};
  fromArray(&head, arr, 10);
  printList(head);
  printf("\n");
  removeDuplicates(head);
  printList(head);
  deleteList(&head);

}
