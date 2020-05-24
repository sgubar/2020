#include "func.h"
#include <time.h>

void SortingFuntion(char* InputArray, long SizeOfArray) //Функция сортировки методом Шелла
{
    int temp; //Переменная для временного хранения данных
    printf("Сортировка методом Шелла\n");
    
    clock_t start = clock(); //Засекаем время до начала работы алгоритма
    //Ниже сам алгоритм сортировки методом Шелла
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
    clock_t end = clock(); //После окончания работы алгоритма засекаем время
    float time1 = end - start; //Разница от начала до конца равна времени работы алгоритма
    printf("Затраченное время: %0.10f\n", time1/CLOCKS_PER_SEC); //Выводим время в консоль
    
    printf("Сортировка завершена\n");
    
    SearchSymbolInArray(InputArray, SizeOfArray); //Вызываем функцию для бинарного поиска символа в массиве
    
    WriteToFile(InputArray); //Записываем отсортированный массив в файл
}

long BinarySearchInArray(char WhatToFind, char* SortedArray, long SizeOfArray) //Функция бинарного поиска в массиве. Массив должен быть предварительно отсортирован
{
    long middle, lower = 0, upper = SizeOfArray - 1;
    printf("Бинарный поиск\n");
    clock_t start = clock(); //Аналогично засекаем время до начала работы алгоритма
    //Ниже алгоритм поиска символа методом бинарного поиска
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
    
    clock_t end = clock(); //После окончания работы поиска - засекаем текущее время
    float time = end - start; //И отнимаем от него время старта
    printf("Затраченное время на поиск символа: %0.10f\n", time/CLOCKS_PER_SEC); //Результатом будет время работы алгоритма поиска
    return -1;
}

void SearchSymbolInArray(char* SortedArray, long SizeOfArray) //Данная функция скорее для обработки результатов основной функции поиска в массиве
{
    char WhatToFind; //Переменная, которая будет хранить необходимый к поиску символ
    printf("Введите, какой символ необходимо найти в массиве: ");
    scanf("%c", &WhatToFind); //Когда пользователь введёт символ - он забивается в переменную
    
    long result = BinarySearchInArray(WhatToFind, SortedArray, SizeOfArray); //Результат храним в соответствующей переменной, которая равна результату работы функции поиска, в которую передали необходимые аргументы
    
    if(result == 0)
        printf("Символ был найден в массиве!\n");
    else
        printf("Символа в массиве найдено не было!\n");
}

void InputFileLenght(long* SizeOfArray) //Функция, которая считает кол-во символов в массиве
{
    long CharacterCount = 0; //Пременная будет хранить кол-во символов
    
    FILE *Input;
    Input = fopen(INPUT,"r"); //Открывается файл в режиме чтения
    
    if(Input == NULL){ //Если файл не открылся
        printf("Файл не был найден!");
        exit(0); //Выходим из программы
    }
    
    int c;
    while((c = fgetc(Input))) //Пока есть символы в файле
    {
      if(c == EOF) break; //Если конец файла, то выходим из while()
      CharacterCount++; //Считаем +1 к переменной, так как посчитали символ
    }
    CharacterCount--; //По непонятной причине, в результате всегда получается на 1 больше символов, чем на самом деле, возможно дело в ложно считанном энтере
    
    fclose(Input); //Файл закрываем
    *SizeOfArray = CharacterCount; //Передаём значение кол-ва символов в переменную
}

char* ReadFromFileToArray(long SizeOfArray) //Фун-ция считывания с входящего файла
{
    FILE *Input;
    Input=fopen(INPUT,"r"); //Открываем файл в режиме считывания
    
    if(Input == NULL){ //Если файл не открылся
        printf("Файл не был найден!");
        exit(0); //Выходим из программы
    }
    
    char* ReadedArray = (char*) malloc(sizeof(char)); //Выделяем память для массива
    
    for (int i = 0; i < SizeOfArray; ++i )
           ReadedArray[i] = (char) malloc(sizeof(char)); //Столько, сколько элементов в входящем файле. Значения кол-ва файлов было считанно ранее.
        
    for(int i = 0; i < SizeOfArray; i++) //Через цикл начинаем заполнять массив данными
        fscanf(Input, "%s", &ReadedArray[i]); //Считывая их с файла
    
    fclose(Input); //Файл закрываем
    
    return ReadedArray; //А массив возвращаем результатом работы функции
}

void WriteToFile (char* InputArray) //Функция записи в файл
{
    FILE  *Output;
    Output = fopen(OUTPUT,"w"); //Открываем файл в режиме записи
    
    if(Output == NULL){ //Если файл не открылся
        printf("Файл не был найден");
        exit(0); //Выходим из программы
    }
    
    fprintf(Output, "%s ",InputArray); //Записываем в файл готовый массив, который был отсортирован
    
    fclose(Output); //Файл закрываем
}
