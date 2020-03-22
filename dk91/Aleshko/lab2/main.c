#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include "hidder.h"

int main()
{
    int masive[5];
    int i = 0;
    Create(masive, 5);
    array_sort(masive, 5);
    out(masive, 5);
}
