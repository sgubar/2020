#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "dk91.h"
int main()
{
    int masive[10000];
    int i = 0;
    Create(masive, 10000);

    bubbleSort(masive ,10000);
    print(masive, 10000);

    selectionSort(masive, 10000);
    print(masive, 10000);

    insertionSort(masive, 10000);
    print(masive, 10000);
}
