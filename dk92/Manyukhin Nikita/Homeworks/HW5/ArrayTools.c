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
    if (NULL == anArray || NULL == file) return ;
    fprintf(file, "Number : %d,\nCount : %d,\n",anArray->number, anArray->count);
    fprintf(file, "Triangles : \n\n");
    for (int i = 0; i < anArray->count; i ++)
    {
        writetriangleToJSON(file, anArray->Triangles[i]);

        fprintf(file, "\n");
    }

    fprintf(file, "\n");
}

int partitionIt(RightTriangleArray *anArray, int aLeftIndex, int aRightIndex, float aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex;

    while (1)
    {
        // search the bigest element
        while (AreaOfRightTriangle(anArray->Triangles[++theLeft]) < aPivot);

        // search the lowest element
        while (theRight > 0 && AreaOfRightTriangle(anArray->Triangles[--theRight]) > aPivot);

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            swap(&anArray->Triangles[theLeft], anArray->Triangles[theRight]);
        }
    }

    //lets to swap elements
    swap(&anArray->Triangles[theLeft], &anArray->Triangles[aRightIndex]);

    return theLeft; // return break position

}


void quickSort(RightTriangleArray *anArray, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0) {
        return; // the array size equals to 1 - the array is fully sorted
    }

    float thePivot = AreaOfRightTriangle(anArray->Triangles[aRightIndex]);
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);

}

int line_search(RightTriangleArray *anArray, float search)
{
	int i;
	int pos;

    for(i = 0; i < anArray->count; i++)
    {
        if (AreaOfRightTriangle(anArray->Triangles[i]) == search)
        {
			printf("\nIt's right,you find it.\n");
			pos=i;

		return pos+1;
		}
    }
    return pos+1;
}


void swap (int *tmp1, int *tmp2)
{
   int temp = *tmp1;
    *tmp1 = *tmp2;
    *tmp2 = temp;
}


