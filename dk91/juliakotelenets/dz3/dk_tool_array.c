#include "dk_tool_array.h"
#include <stdio.h>
#include <stdlib.h>
//init/dealloc
EllipseArray *createArray(int aNumber)
{
    EllipseArray *theResult = NULL;
    if (aNumber>0)
    {  // выделение памяти под корень списка
        theResult=(EllipseArray *)malloc(sizeof(EllipseArray));
        if(NULL != theResult)
        {
            theResult->ellipses = (Ellipse **)malloc(sizeof(Ellipse *)*aNumber);
            if(NULL != theResult->ellipses)
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

void freeArray(EllipseArray *anArray)  //освобождаем массив
{
    if(NULL != anArray)
    {
        for( int i=0; i<anArray->count; i++)
        {
            destroyEllipse(anArray->ellipses[i]);  //разрушаем элипсы
        }
            free(anArray->ellipses); //освобождаем память от массива элипсов
            free(anArray);  //освобождаем память от массива
    }
}
//interface
//возвращает индекс добавленного элемента или -1 в случае неудачи
int addElement(EllipseArray *anArray, Ellipse *aEllipse)
{
    int theResult = -1;   //придаем значение -1
    if(NULL != anArray && NULL != aEllipse && anArray->count < anArray->number)
    {
        anArray->ellipses[anArray->count]=aEllipse;
        theResult = anArray->count;
        anArray->count++;
    }
    return theResult;
}
//функція вставки елементу за індексом
//якщо за даними індексом існує елемент, то він заміщується елементом, що вставляється
int addElementInIndex(EllipseArray *anArray, Ellipse *aEllipse, int index)
//посилання на масив
//посилання на елемент що вставляється в масив
//індекс, за яким потрібно вставити елемент
{
    int theResult =-1;
    if(NULL != anArray && NULL != aEllipse && index>=0 && index<anArray->count)
    {
        if(NULL == anArray->ellipses[index])
        {
            anArray->ellipses[index]=aEllipse;
        }
        else
        {
            destroyEllipse(anArray->ellipses[index]);   //разрушаем массив элипсов
            anArray->ellipses[index]=aEllipse; //присвоюємо індекс елементу, що вставляється в масив
            theResult=index; //результат це індекс
        }
    }
    return theResult;
}

void writeArrayToJSON(FILE *aFile, EllipseArray *anArray)
{
    if(NULL == anArray || NULL == aFile)
    {
        return;
    }
    fprintf(aFile, "{\n\"number\" : %d, \n\"count\" : %d, \n", anArray->number, anArray->count);
    fprintf(aFile, "\"ellipses\" : %d\n[\n");
    for(int i=0; i<anArray->count; i++)
    {
        writeEllipseToJSON(aFile, anArray->ellipses[i]);
        if(i<anArray->count-1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }
    fprintf(aFile, "]\n}");
}

void printArray(EllipseArray* anArray)
{
	if (anArray != NULL)
	{
		printf("[EA]: number(%d), count(%d)", anArray->number, anArray->count);
		printf(", ellipses: (%d) \n");

		for (int i = 0; i < anArray->count; i++)
		{
			printEllipse(anArray->ellipses[i]);
		}
	}
	else return;
}
