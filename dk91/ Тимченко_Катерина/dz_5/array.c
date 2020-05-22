#include "array.h"
#include "rectangle.h"
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
int addElement(RectgArray *anArray, Rectg *currRectg)
{
    int theResult = -1;

    if(NULL != anArray && NULL != currRectg && anArray->count < anArray->number)
    {
        anArray->rectangles[anArray->count] = createRec(currRectg->A, currRectg->B, currRectg->C, currRectg->D);
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
    for(int i = 0; i < anArray->count; i++)
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
		printf(", rectangles: \n");

		for (int i = 0; i < anArray->count; i++)
		{
			printRec(anArray->rectangles[i]);
		}
	}
	else return;
}

unsigned int binarySearch(RectgArray *anArray, float area_pattern)
{
	if (NULL == anArray)
	{
		return (unsigned int)-1;
	}

	unsigned int theResult = -1;

	shellSort(anArray);

	theResult = anArray->count;
	unsigned theLowerBound = 0;
	unsigned theUpperBound = anArray->count - 1;
	unsigned theCurIn = 0;

	while (1)
	{
		theCurIn = (theLowerBound + theUpperBound) / 2;
		float current_area = areaOfRec(anArray->rectangles[theCurIn]);
		if (current_area == area_pattern) //<!- an element was found
		{
			theResult = theCurIn;
			break;
		}
		else if (theLowerBound > theUpperBound) //<!- all elements were viewed
		{
			break;
		}
		else
		{
			if (current_area < area_pattern)
			{
				theLowerBound = theCurIn + 1; //!<- in upper position
			}
			else
			{
				theUpperBound = theCurIn - 1; //!<- in lower position
			}
		}

	}

	printf("\nThe biggest rectangle is [%d]\n", theCurIn);
	return theResult;
}

void shellSort(RectgArray *anArray)
{
	if (NULL == anArray)
	{
		return ;
	}

	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

	//1. Calculate start value of h
	while (theH <= anArray->count/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < anArray->count; theOuter ++)
		{
			Rectg *theTmp = anArray->rectangles[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && areaOfRec(anArray->rectangles[theInner - theH]) >= areaOfRec(theTmp))
			{
				anArray->rectangles[theInner] = anArray->rectangles[theInner - theH];
				theInner -= theH;
			}

			anArray->rectangles[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
}
