#include <stdlib.h>
#include "tools.h"
#include "ArrayTools.h"
#include <malloc.h>



void freeArr(RightTriangleArray *anArray)
{
    if (NULL != anArray)
    {
        for (int i = 0; i < anArray->count; i++)
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
    if (NULL == anArray || NULL == file) return ;
    fprintf(file, "Number : %d,\nCount : %d,\n",anArray->number, anArray->count);
    fprintf(file, "\"Triangles\" : \n[\n");
    for (int i = 0; i < anArray->count; i ++)
    {
        writetriangleToJSON(file, anArray->Triangles[i]);

        if (i < anArray->count - 1)
		{
			fprintf(file, ",");
		}
		fprintf(file, "\n");
    }

    fprintf(file, "]\n");
}

int partitionIt(RightTriangleArray *anArray, int aLeftIndex, int aRightIndex, float aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex;

    while (1)
    {
        while (AreaOfRightTriangle(anArray->Triangles[++theLeft]) < aPivot);

        while (theRight > 0 && AreaOfRightTriangle(anArray->Triangles[--theRight]) > aPivot);

        if (theLeft >= theRight)
        {
            break;
        }
        else
        {
            swap(&anArray->Triangles[theLeft], anArray->Triangles[theRight]);
        }
    }

    swap(&anArray->Triangles[theLeft], &anArray->Triangles[aRightIndex]);

    return theLeft;

}


void quickSort(RightTriangleArray *anArray, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0) {
        return;
    }

    float thePivot = AreaOfRightTriangle(anArray->Triangles[aRightIndex]);
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);


    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);

}

void LinearSearch(RightTriangleArray *anArray, float aKey)
{
    for(int i = 0; i < anArray->count; i++)
    {
        if (AreaOfRightTriangle(anArray->Triangles[i]) == aKey)
        {
      printf("\nIt's right,we found it.\n");
      printf("Position of a triangle: %d\n\n", i+1);
      return;
        }
    }
    printf("A triangle with this area was not found!");

}


void swap (int *tmp1, int *tmp2)
{
   int temp = *tmp1;
    *tmp1 = *tmp2;
    *tmp2 = temp;
}
