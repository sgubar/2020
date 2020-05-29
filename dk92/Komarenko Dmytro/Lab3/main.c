#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    system("chcp 1251");
    system("cls");
    float timeStart, timeStop, timeStart1, timeStop1;

    int size;
    printf("Введіть розмір масиву:");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Введіть ще раз:");
        scanf("%d", &size);
    }
    char mass[size];
    randomizer(mass, size);
    FILE *file = fopen("Input.txt", "w");
    int i;
    for (i=0; i<size; i++)
    {
        fprintf(file, "%c", mass[i]);
    }
    fclose(file);
    timeStart = clock()/(float)CLOCKS_PER_SEC;
    shellSort (mass, size);
    timeStop = clock()/(float)CLOCKS_PER_SEC;
    FILE *file1 = fopen("output.txt", "w");
    for (i=0; i<size; i++)
    {
        fprintf(file1, "%c", mass[i]);
    }
    fclose(file1);
printf ("Час сортування Шелла: %.10lf\n", (double)(timeStop - timeStart)/CLOCKS_PER_SEC);

char symbol;
fflush(stdin);
printf("\n\nВведіть символ: ");
scanf("%c", &symbol);
    int position;
    timeStart1 = clock()/(float)CLOCKS_PER_SEC;
    position = BinarySearch(symbol, mass, size);
    timeStop1 = clock()/(float)CLOCKS_PER_SEC;
    printf ("Час двійкового пошуку: %.10lf\n", (double)(timeStop1 - timeStart1)/CLOCKS_PER_SEC);
    if(position != -1)
    {
        printf("Індекс шуканого елемента є: %i\n", position);
    }
    else
    {
        printf("Елемент не знайдено!\n");
    }
    return 0;
}
