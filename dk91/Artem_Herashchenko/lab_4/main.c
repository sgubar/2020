#include <stdio.h>
#include <stdlib.h>
#include "hhh.h"

int main(int argc, char const *argv[])
{
	int a, b;
	printf("Vvedite granici\n");
    List *list = load_from_file("input.txt"); //создание структуры
    scanf("%d", &a);
    scanf("%d", &b);
    printList(list, a, b);
    return 0;
}

