#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "hhh.h"

int main(int argc, char const *argv[])
{
    List *list = load_from_file("input.txt");
    listprint(list);
    printf("\n");
    listprintr(list);
    return 0;
}
