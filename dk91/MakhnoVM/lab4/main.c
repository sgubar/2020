#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include "tool.h"

int main(int argc, char const *argv[])
{
    char element;

    List *p_begin = scanElem(); 	// створення списку

    
    printf(" Enter key element : ");
    scanf("%c", &element);			// задання ключового елементу

    listPrint(p_begin);				// вивід структури на екран
    printf("\n");

    check(p_begin, element);		// swap елементів

    listPrint(p_begin);				// вивід нової структури на екран
   
    return 0;
}