#include "header_array.h"
#include <stdio.h>
#include <stdlib.h>

TriangleArray *createArray(int aNumber)
{
    TriangleArray *theResult = NULL;
    if (aNumber>0)
    {  // выделение памяти под корень списка
        theResult=(TriangleArray *)malloc(sizeof(TriangleArray));
        if(NULL != theResult)
        {
            theResult->triangles = (Triangle **)malloc(sizeof(Triangle *)*aNumber);
				memset(theResult->triangles, 0, sizeof(Triangle *)*aNumber);
            if(NULL != theResult->triangles)
            {
                // Присваивание значения узлу
                theResult->number = aNumber;
                theResult->count = 0;
            }
            else
            {   //осводождаем память
                free(theResult);
                theResult=NULL;
            }
        }
    }
    return theResult;
}

void freeArray(TriangleArray *anArray)  //освобождаем массив
{
    if(NULL != anArray)
    {
        for( int i=0; i<anArray->count; i++)
        {
            destroyTriangle(anArray->triangles[i]);  //разрушаем треугольники
        }
            free(anArray->triangles); //освобождаем память от массива треугольников
            free(anArray);  //освобождаем память от массива
    }
}
//interface
//возвращает индекс добавленного элемента или -1 в случае неудачи
int addElement(TriangleArray *anArray, Triangle *aTriangle)
{
    int theResult = -1;   //придаем значение -1
    if(NULL != anArray && NULL != aTriangle && anArray->count < anArray->number)
    {
        anArray->triangles[anArray->count]=aTriangle;
        theResult = anArray->count;
        anArray->count++;
    }
    return theResult;
}
//функція вставки елементу за індексом
//якщо за даними індексом існує елемент, то він заміщується елементом, що вставляється
int addElementInIndex(TriangleArray *anArray, Triangle *aTriangle, int index)
//посилання на масив
//посилання на елемент що вставляється в масив
//індекс, за яким потрібно вставити елемент
{
    int theResult =-1;
    if(NULL != anArray && NULL != aTriangle && index>=0 && index<anArray->count)
    {
        if(NULL == anArray->triangles[index])
        {
            anArray->triangles[index]=aTriangle;
        }
        else
        {
            destroyTriangle(anArray->triangles[index]);   //разрушаем массив треугольников
            anArray->triangles[index]=aTriangle; //присвоюємо індекс елементу, що вставляється в масив
            theResult=index; //результат це індекс
        }
    }
    return theResult;
}

void writeArrayToJSON(FILE *aFile, TriangleArray *anArray)
{
    if(NULL == anArray || NULL == aFile)
    {
        return;
    }
    fprintf(aFile, "{\n\"number\" : %d, \n\"count\" : %d, \n", anArray->number, anArray->count);
    fprintf(aFile, "\"triangles\" : %d\n[\n");
    for(int i=0; i<anArray->count; i++)
    {
        writeTriangleToJSON(aFile, anArray->triangles[i]);
        if(i<anArray->count-1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }
    fprintf(aFile, "]\n}");
}

void printArray(TriangleArray* anArray)
{
	if (anArray != NULL)
	{
		printf("[TA]: number(%d), count(%d)", anArray->number, anArray->count);
		printf(", triangles:  \n");

		for (int i = 0; i < anArray->count; i++)
		{
			printTriangle(anArray->triangles[i]);
		}
	}
	else return;
}
