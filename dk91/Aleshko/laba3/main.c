#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "hhh.h"
int main()
{
    int n = 100;
    int masive[n];
    int i = 0;
    Create(masive, n);
    clock_t time;
    time = clock();
    quicksort(masive, 0, n-1);
    time = clock() - time;
    printf("%f ", (double)time/CLOCKS_PER_SEC);
    out(masive, n);
}
