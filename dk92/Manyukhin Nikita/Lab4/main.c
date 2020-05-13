#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  node* s = read_list_from_file("File.txt");
  listprint(s);
  printf("%s\n", ispalindrome(s) ? "is palindrome" : "is not palindrome");

  return 0;
}
