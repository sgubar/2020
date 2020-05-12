
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "header.h"
int main()
{
    int n = 10000;
    int masive[n];
    int i = 0;
    Create(masive, n);
    bubbleSort(masive ,n);
    out(masive, n);

    selectionSort(masive, n);
    out(masive, n);

    insertionSort(masive, n);
    out(masive, n);
}
