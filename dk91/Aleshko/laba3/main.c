#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "hhh.h"
int main()
{
    int n = 1000;
    int masive[n];
    Create(masive, n);
    clock_t time;
    time = clock();
    quicksort(masive, 0, n-1);
    time = clock() - time;
    printf("%f ", (double)time/CLOCKS_PER_SEC);
    out(masive, n);
    int point = poisk(masive, n, 6);
    if (point == -1)
    printf("No elements = 6 !\n");
    else
    printf("Element with index %d = 6", point);

}
