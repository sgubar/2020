#include "array.h"
#include <stdio.h>
#include <stdlib.h>
//init/dealloc
RectgArray *createArray(int aNumber)
{
    RectgArray *theResult = NULL;
    if (aNumber>0)
    {
         // выделяем память для корня списка
        theResult=(RectgArray *)malloc(sizeof(RectgArray));

        if(NULL != theResult)
        {
            theResult->rectangles = (Rectg **)malloc(sizeof(Rectg *)*aNumber);

            if(NULL != theResult->rectangles)
            {
                // Присваивание значения узлу
                theResult->number = aNumber;
                theResult->count = 0;
            }
            else
            {   //осводождаем память
                free(theResult);
                theResult = NULL;
            }
        }
    }
    return theResult;
}

void freeArray(RectgArray *anArray)  //освобождаем массив
{
    if(NULL != anArray)
    {
        for( int i = 0; i < anArray->count; i++)
        {
            deleteRectg(anArray->rectangles[i]);  //разрушаем элипсы
        }
            free(anArray->rectangles); //освобождаем память от массива элипсов
            free(anArray);  //освобождаем память от массива
    }
}

//возвращает индекс добавленного элемента или -1 в случае неудачи
int addElement(RectgArray *anArray, Rectg *currentRec)
{
    int theResult = -1;

    if(NULL != anArray && NULL != currentRec && anArray->count < anArray->number)
    {
        anArray->rectangles[anArray->count] = createRec(currentRec->A, currentRec->B, currentRec->C, currentRec->D);
        theResult = anArray->count;
        anArray->count++;
    }
    return theResult;
}

void writeArrayToJSON(FILE *aFile, RectgArray *anArray)
{
    if(NULL == anArray || NULL == aFile)
    {
        return;
    }
    fprintf(aFile, "{\n\"number\" : %d, \n\"count\" : %d, \n", anArray->number, anArray->count);
    fprintf(aFile, "\"rectangles\" :\n[\n");
    for(int i=0; i<anArray->count; i++)
    {
        writeRecToJSON(aFile, anArray->rectangles[i]);
        if(i < anArray->count-1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }
    fprintf(aFile, "]\n}");
}

void printArray(RectgArray* anArray)
{
	if (anArray != NULL)
	{
		printf("[RA]: number(%d), count(%d)", anArray->number, anArray->count);
		printf(", rectangles: (%d) \n");

		for (int i = 0; i < anArray->count; i++)
		{
			printRec(anArray->rectangles[i]);
		}
	}
	else return;
}
