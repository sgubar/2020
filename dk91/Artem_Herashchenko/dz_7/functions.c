#include "functions.h"

Point *copyPointWithPoint(Point *aPoint);

Square *createSquare(Point *A, Point *B, Point *C, Point *D)    //створюємо квадрат
{
    Square *theResult = NULL;

    if (NULL != A && NULL != B && NULL != C && NULL != D)
    {
        theResult = (Square *)malloc(sizeof(Square));

        if (NULL != theResult)
        {
            theResult->A = copyPointWithPoint(A);
            theResult->B = copyPointWithPoint(B);
            theResult->C = copyPointWithPoint(C);
            theResult->D = copyPointWithPoint(D);
        }
    }
    return theResult;
}

void destroySquare(Square *aSquare)                      //звільнення пам'яті
{
	if (NULL != aSquare)
	{
		free(aSquare->A);
		free(aSquare->B);
		free(aSquare->C);
		free(aSquare->D);

		free(aSquare);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;                                 //присвоюємо вказівнику theResult->x значення вказівника aPoint -> х
		theResult->y = aPoint->y;
	}

	return theResult;
}

void EnteringCoordinates (int *X, int *Y)                        //введення кординат
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}

float ploschaSquare(Square *aSquare)                      //розрахунок площі
{
   float theResult = 0.0;

	if (NULL != aSquare)
	{
		float dX = (aSquare->A->x - aSquare->B->x);
		float dY = (aSquare->A->y - aSquare->B->y);
		theResult = sqrt(dX*dX + dY*dY);
		theResult=pow(theResult,2);
	}
	return theResult;
}
//===============================================ЗАПИС У JSON=================================================
void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeSquareToJSON(FILE *aFile, Square *aSquare)
{
	if (NULL == aSquare || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aSquare->A);
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, aSquare->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aSquare->C);
	fprintf(aFile, ",\n\"D\" : ");
	writePointToJSON(aFile, aSquare->D);
	fprintf(aFile, "\n}");
}

void writeArrayToJSON(FILE *aFile, SquareArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"Kvadrats\" : \n[\n");

	for (int i = 0; i < anArray->count; i ++)
	{
		writeSquareToJSON(aFile, anArray->Squares[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}
//=======================================МАСИВ=============================================

SquareArray *createArray(int aNumber)                    //створення
{
	SquareArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (SquareArray *)malloc(sizeof(SquareArray));

		if (NULL != theResult)
		{
			theResult->Squares = (Square **)malloc(sizeof(Square *)*aNumber);
			theResult->ploschaSquare = malloc(sizeof(float)*aNumber);

			if (NULL != theResult->Squares)
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

void freeArray(SquareArray *anArray)                      //звільнення пам'яті
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroySquare(anArray->Squares[i]);
		}

		free(anArray->Squares);
		free(anArray);
	}
}

int addElement(SquareArray *anArray, Square *aSquare, float ploscha)      //додавання елементу
{
	int theResult = -1;

	if (NULL != anArray && NULL != aSquare &&
				anArray->count < anArray->number)
	{
		anArray->Squares[anArray->count] =
					createSquare(aSquare->A, aSquare->B, aSquare->C,aSquare->D);
		anArray->ploschaSquare[anArray->count] = ploscha;

		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}
//========================================СОРТУВАННЯ===============================

void sort_vstavka(SquareArray *anArray)
{
    Square *newElement=NULL;
    int  location;

    for (int i = 1; i < anArray->count; i++)
    {
        newElement = anArray->Squares[i];
        location = i - 1;
        while(location >= 0 && anArray->ploschaSquare[location] > anArray->ploschaSquare[i])
        {
            anArray->Squares[location+1] = anArray->Squares[location];
            location = location - 1;
        }
        anArray->Squares[location+1] = newElement;
    }
}

void quickSort( SquareArray *anArray, int l, int r)
{
   int j;

   if( l < r )
   {
       j = partition( anArray, l, r);
       quickSort( anArray, l, j-1);
       quickSort( anArray, j+1, r);
   }

}

int partition(SquareArray *anArray, int l, int r)
{
   int i, j;
   Square *t;
   int pivot = ploschaSquare(anArray->Squares[l]);
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( ploschaSquare(anArray->Squares[i]) <= pivot && i <= r );
   	do --j; while( ploschaSquare(anArray->Squares[j]) > pivot );
   	if( i >= j ) break;
   	t = anArray->Squares[i]; anArray->Squares[i] = anArray->Squares[j]; anArray->Squares[j] = t;
   }
   t = anArray->Squares[l]; anArray->Squares[l] = anArray->Squares[j]; anArray->Squares[j] = t;
   return j;
}

//==================================ПОШУК============================================
int linijnyj_poshuk(SquareArray *anArray, float key)
{
    for (int i = 0; i < anArray->count; i++)
    {
        if (ploschaSquare(anArray->Squares[i]) == key)
        return i+1;

    }

    return -1;

}

