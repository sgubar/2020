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
         // âûäåëÿåì ïàìÿòü äëÿ êîðíÿ ñïèñêà
        theResult=(RectgArray *)malloc(sizeof(RectgArray));

        if(NULL != theResult)
        {
            theResult->rectangles = (Rectg **)malloc(sizeof(Rectg *)*aNumber);

            if(NULL != theResult->rectangles)
            {
                // Ïðèñâàèâàíèå çíà÷åíèÿ óçëó
                theResult->number = aNumber;
                theResult->count = 0;
            }
            else
            {   //îñâîäîæäàåì ïàìÿòü
                free(theResult);
                theResult = NULL;
            }
        }
    }
    return theResult;
}

void freeArray(RectgArray *anArray)  //îñâîáîæäàåì ìàññèâ
{
    if(NULL != anArray)
    {
        for( int i = 0; i < anArray->count; i++)
        {
            deleteRectg(anArray->rectangles[i]);  //ðàçðóøàåì ýëèïñû
        }
            free(anArray->rectangles); //îñâîáîæäàåì ïàìÿòü îò ìàññèâà ýëèïñîâ
            free(anArray);  //îñâîáîæäàåì ïàìÿòü îò ìàññèâà
    }
}

//âîçâðàùàåò èíäåêñ äîáàâëåííîãî ýëåìåíòà èëè -1 â ñëó÷àå íåóäà÷è
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

void bubbleSort(RectgArray *anArray)
{
    if (NULL == anArray || anArray->count == 0)
	{
		return ;
	}

	for (int theOut = anArray->count - 1; theOut >= 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (areaOfRec(anArray->rectangles[theIn]) > areaOfRec(anArray->rectangles[theIn + 1]))
			{
				Rectg *theTmp = anArray->rectangles[theIn];
	            anArray->rectangles[theIn] = anArray->rectangles[theIn+1];
	            anArray->rectangles[theIn+1] = theTmp;
			}
		}
	}
}

void selectionSort(RectgArray *anArray)
{
	if (NULL == anArray || 0 == anArray->count)
	{
		return ;
	}

	for (int theOut = 0; theOut < anArray->count - 1; theOut ++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < anArray->count; theIn ++)
		{
			if (areaOfRec(anArray->rectangles[theIn]) < areaOfRec(anArray->rectangles[theMinIndex]))
			{
				theMinIndex = theIn;
			}
		}
		Rectg *theTmp = anArray->rectangles[theOut];
		anArray->rectangles[theOut] = anArray->rectangles[theMinIndex];
		anArray->rectangles[theMinIndex] = theTmp;
	}
}

void insertionSort(RectgArray *anArray)
{
	if (NULL == anArray || 0 == anArray->count)
	{
		return;
	}
	for (int theOut = 1; theOut < anArray->count; theOut ++)
	{
		Rectg *theTmp = anArray->rectangles[theOut];
		int theIn = theOut;

		while (theIn > 0 && areaOfRec(anArray->rectangles[theIn - 1]) >= areaOfRec(theTmp))
		{
			anArray->rectangles[theIn] = anArray->rectangles[theIn - 1];
			--theIn;
		}

		anArray->rectangles[theIn] = theTmp;
	}
}
