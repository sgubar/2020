//
//  Functions.c
//  LaboratoryWork3
//
//  Created by Nazar Diadiun on 20.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include "Functions.h"

#include <time.h>

#define inputFilePath "/Users/nazar/Desktop/Labs/LaboratoryWork3/LaboratoryWork3/Input.txt"
#define outputFilePath "/Users/nazar/Desktop/Labs/LaboratoryWork3/LaboratoryWork3/Output.txt"

void shellsort(char* arr, int ArraySize)
{
    int i, j, k, tmp;
    printf("Shell Sorting...\n");
    clock_t start = clock();
    for (i = ArraySize / 2; i > 0; i = i / 2)
    {
        for (j = i; j < ArraySize; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
    
    clock_t end = clock();
    float time1 = end - start;
    printf("Shell Sorting Time: %0.10f\n", time1/CLOCKS_PER_SEC);
    
    printf("Shell Sorting Completed\n");
    
    SymbolSearch(arr, ArraySize);
    
    fileWrite(arr);
}

long binarysearch(char symbol, char* array, long ArraySize)
{
    long middle, lower = 0, upper = ArraySize - 1;
    printf("Binary Search...\n");
    clock_t start = clock();
    while(lower <= upper)
    {
        middle = (lower + upper) / 2;

        if(array[middle] == symbol)
            return 0;

        else if(array[middle] < symbol)
            lower = middle + 1;
        else
            upper = middle - 1;
    }
    
    clock_t end = clock();
    float time = end - start;
    printf("Binary Search Time: %0.10f\n", time/CLOCKS_PER_SEC);
    return -1;
}

void SymbolSearch(char* array, long ArraySize)
{
    //read symbol from console
    char symbol;
    printf("Enter character to search: ");
    scanf("%c", &symbol);
    
    long result = binarysearch(symbol, array, ArraySize);
    if(result == 0)
    {
        printf("Symbol Founded!\n");
    }
    else
    {
        printf("Symbol not Founded!\n");
    }
}

long getCharacterCount() //My function created with 2 laboratory work
{
    FILE *in_file;
    in_file=fopen(inputFilePath,"r");
    
    if(in_file == NULL){
        printf("No such file found");
        exit(0);
    }
    
    long count = 0;
    int c;
    while((c=fgetc(in_file)))
    {
      if(c == EOF) break;
      count+=1;
    }
    count -= 1;
    
    fclose(in_file);
    return count;
}

char* fileprocess(long ArraySize) //My function created with 2 laboratory work
{
    FILE *in_file;
    in_file=fopen(inputFilePath,"r");
    
    if(in_file == NULL){
        printf("No such file found");
        exit(0);
    }
    
    char* a = ( char* ) calloc( ArraySize, sizeof(char) );
    int i;
    for ( i = 0; i < ArraySize; ++i )
           a[ i ] = ( char ) calloc( ArraySize, sizeof(char) );
        
    for(int i = 0; i < ArraySize; i++)
        fscanf(in_file, "%s", &a[i]);
    
    fclose(in_file);
    
    return a;
}

void fileWrite (char* matrix) //My function created with 2 laboratory work
{
    FILE  *out_file;
    out_file=fopen(outputFilePath,"w");
    
    if(out_file == NULL){
        printf("No such file found");
        exit(0);
    }
    
    fprintf(out_file, "%s ",matrix);
    
    fclose(out_file);
}
