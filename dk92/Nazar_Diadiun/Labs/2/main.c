//
//  main.c
//  Laboratory work 2
//
//  Created by Nazar Diadiun on 24.02.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SortFunc.h"
#include <time.h>

int main()
{
    int method = 0;
    unsigned long start_time, end_time, search_time;
    
    long ArraySize = getCharacterCount();
    
    for(method = 0; method <= 2; method++)
    {
        start_time = clock();
    switch(method)
    {
        case 0:
      insertionSort(fileprocess(ArraySize), ArraySize);
        printf("InsertionSort Func Time: ");
            break;
        case 1:
        bubbleSort(fileprocess(ArraySize), ArraySize);
        printf("BubbleSort Func Time: ");
            break;
        case 2:
        selectionSort(fileprocess(ArraySize), ArraySize);
        printf("SelectionSort Func Time: ");
            break;
    }
    end_time = clock();
    search_time = end_time - start_time;
    printf("%ld\n", search_time);
    }
}
