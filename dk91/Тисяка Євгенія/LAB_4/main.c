#include <stdio.h>
#include "fff.h"

int main()
{
    List *list = load_from_file("D:\\input.txt");

  listprintr(list);
  printf("\n");
   obch(list);
    return 0;
}
