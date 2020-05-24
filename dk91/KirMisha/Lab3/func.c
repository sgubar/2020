#include "func.h"
#include <time.h>

void SortingFuntion(char* InputArray, long SizeOfArray) 
{
    int temp;
    printf("Сортировка методом Шелла\n");
    
    clock_t start = clock(); 
    
    for (long i = SizeOfArray / 2; i > 0; i = i / 2)
    {
        for (long j = i; j < SizeOfArray; j++)
        {
            for(long k = j - i; k >= 0; k = k - i)
            {
                if (InputArray[k+i] >= InputArray[k])
                    break;
                else
                {
                    temp = InputArray[k];
                    InputArray[k] = InputArray[k+i];
                    InputArray[k+i] = temp;
                }
            }
        }
    }
    clock_t end = clock(); 
    float time1 = end - start; 
    printf("Затраченное время: %0.10f\n", time1/CLOCKS_PER_SEC); 
    
    printf("Сортировка завершена\n");
    
    SearchSymbolInArray(InputArray, SizeOfArray); 
    
    WriteToFile(InputArray); 
}

long BinarySearchInArray(char WhatToFind, char* SortedArray, long SizeOfArray) 
{
    long middle, lower = 0, upper = SizeOfArray - 1;
    printf("Бинарный поиск\n");
    clock_t start = clock(); 
    while(lower <= upper)
    {
        middle = (lower + upper) / 2;

        if(SortedArray[middle] == WhatToFind)
            return 0;

        else if(SortedArray[middle] < WhatToFind)
            lower = middle + 1;
        else
            upper = middle - 1;
    }
    
    clock_t end = clock(); 
    float time = end - start; 
    printf("Затраченное время на поиск символа: %0.10f\n", time/CLOCKS_PER_SEC); 
    return -1;
}

void SearchSymbolInArray(char* SortedArray, long SizeOfArray) 
{
    char WhatToFind; 
    printf("Введите, какой символ необходимо найти в массиве: ");
    scanf("%c", &WhatToFind); 
    
    long result = BinarySearchInArray(WhatToFind, SortedArray, SizeOfArray); 
    
    if(result == 0)
        printf("Символ был найден в массиве!\n");
    else
        printf("Символа в массиве найдено не было!\n");
}

void InputFileLenght(long* SizeOfArray) 
{
    long CharacterCount = 0; 
    
    FILE *Input;
    Input = fopen(INPUT,"r"); 
    
    if(Input == NULL){ 
        printf("Файл не был найден!");
        exit(0); 
    }
    
    int c;
    while((c = fgetc(Input))) 
    {
      if(c == EOF) break; 
      CharacterCount++;
    }
    CharacterCount--; 
    
    fclose(Input); 
    *SizeOfArray = CharacterCount;
}

char* ReadFromFileToArray(long SizeOfArray)
{
    FILE *Input;
    Input=fopen(INPUT,"r"); 
    
    if(Input == NULL){ 
        printf("Файл не был найден!");
        exit(0); 
    }
    
    char* ReadedArray = (char*) malloc(sizeof(char)); 
    
    for (int i = 0; i < SizeOfArray; ++i )
           ReadedArray[i] = (char) malloc(sizeof(char));
        
    for(int i = 0; i < SizeOfArray; i++) 
        fscanf(Input, "%s", &ReadedArray[i]);
    
    fclose(Input); 
    
    return ReadedArray;
}

void WriteToFile (char* InputArray)
{
    FILE  *Output;
    Output = fopen(OUTPUT,"w"); 
    
    if(Output == NULL){ 
        printf("Файл не был найден");
        exit(0); 
    }
    
    fprintf(Output, "%s ",InputArray);
    
    fclose(Output); 
}
