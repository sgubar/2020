#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "hhh.h"
int main()
{
    int masive[1000];
    int i = 0;
    Create(masive, 1000);
    bubbleSort(masive ,1000);
    out(masive, 1000);
    selectionSort(masive, 1000);
    out(masive, 1000);
    insertionSort(masive, 1000);
    out(masive, 1000);
}
