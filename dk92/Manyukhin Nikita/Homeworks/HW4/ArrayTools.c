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

void SelectSort(RightTriangleArray *Sel_mass, int size)
{
    for (int i = 0; i < size; i++) {
        int key = i;
        int j;
        for (j = i+1; j < size; j++)
        {
            RightTriangle *fone = Sel_mass->Triangles[j];
            RightTriangle *sone = Sel_mass->Triangles[key];
            if (AreaOfRightTriangle(fone) < AreaOfRightTriangle(sone))
                key = j;
        }
        swap(Sel_mass->Triangles[key], Sel_mass->Triangles[i]);
    }
}

void swap (RightTriangle *Trii, RightTriangle *temp1)
{
   RightTriangle temp = *Trii;
    *Trii = *temp1;
    *temp1 = temp;
}


