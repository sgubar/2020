#include <stdlib.h>
#include "tools.h"
#include "ArrayTools.h"
#include <malloc.h>


void freeArr(RightTriangleArray *anArray)
{
    if (NULL != anArray)
    {
        for (int i = 0; i < anArray->count; i ++)
                destroyRightTriangle(anArray->Triangles[i]);


        free(anArray->Triangles);
        free(anArray);
    }
}


RightTriangleArray *createArray(int aNumber)
{
	RightTriangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (RightTriangleArray *)malloc(sizeof(RightTriangleArray));

		if (NULL != theResult)
		{
			theResult->Triangles = (RightTriangle **)malloc(sizeof(RightTriangle *)*aNumber);

			if (NULL != theResult->Triangles)
			{
				theResult->number = aNumber;
				theResult->count = 0;
			}
			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}

	return theResult;
}

void DestroyArray(RightTriangleArray *anArray)
{
	int i;
	if (NULL != anArray)
	{
		for (i = 0; i < anArray->count; i ++)
		{
			destroyRightTriangle(anArray->Triangles[i]);
		}

		free(anArray->Triangles);
		free(anArray);
	}
}

int addElement(RightTriangleArray *anArray, RightTriangle *aTriangle)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aTriangle &&	anArray->count < anArray->number)
	{
		anArray->Triangles[anArray->count] = createRightTriangle(aTriangle->A, aTriangle->B, aTriangle->C);
		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *file, RightTriangleArray *anArray)
{
	{
    if (NULL == anArray || NULL == file)
            return ;


    fprintf(file, "{\nNumber : %d,\nCount : %d,\n",anArray->number, anArray->count);
    fprintf(file, "Triangles : \n\n");
    for (int i = 0; i < anArray->count; i ++)
    {
        writetriangleToJSON(file, anArray->Triangles[i]);

        if (i < anArray->count - 1)
                    fprintf(file, ",");

        fprintf(file, "\n");
    }

    fprintf(file, "\n");
}
}
