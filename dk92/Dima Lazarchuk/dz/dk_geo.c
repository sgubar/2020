#include "dk_geo.h"

Point *copyPointWithPoint(Point *aPoint);
Point *creatPointWithCoordinate(int x, int y);


Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D)
{
	Rectangle *theResult = NULL;
	
	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		if((A->x - D->x) != 0 || (B->x - C->x) != 0 || (A->y - B->y) != 0 || (C->y - D->y) != 0)
		{
			printf("Not Rectanglen\n");
			return NULL;
		}
		theResult = (Rectangle *)malloc(sizeof(Rectangle));
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

Rectangle *createRectangleWithPoints(Point *Ps[])
{
	Rectangle *theResult = NULL;
	
	if (NULL != Ps)
	{
		if((Ps[0]->x - Ps[3]->x) != 0 || (Ps[1]->x - Ps[2]->x) != 0 || (Ps[0]->y - Ps[1]->y) != 0 || (Ps[2]->y - Ps[3]->y) != 0)
			return theResult;
		theResult = (Rectangle *)malloc(sizeof(Rectangle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(Ps[0]);
			theResult->B = copyPointWithPoint(Ps[1]);
			theResult->C = copyPointWithPoint(Ps[2]);
			theResult->D = copyPointWithPoint(Ps[3]);
		}
	}
	
	return theResult;
}
Rectangle *createRectangleWithCoordinate(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD)
{
	
	if((xA - xD) != 0 || (xB - xC) != 0 || (yA - yB) != 0 || (yC - yD) != 0)
	{
		printf("Not Rectanglen\n");
		return NULL;
	}
	Rectangle *theResult = (Rectangle *)malloc(sizeof(Rectangle));
	
	if (NULL != theResult)
	{
		
		theResult->A = creatPointWithCoordinate(xA, yA);
		theResult->B = creatPointWithCoordinate(xB, yB);
		theResult->C = creatPointWithCoordinate(xC, yC);
		theResult->D = creatPointWithCoordinate(xD, yD);
		
	}
	return theResult;
}


void destroyRectangle(Rectangle *aRectangle)
{
	if (NULL != aRectangle)
	{
		free(aRectangle->A);
		free(aRectangle->B);
		free(aRectangle->C);
		free(aRectangle->D);
	
		free(aRectangle);
	}
}


float areaRectangle(Rectangle *aRectangle)
{
	float theResult = 0.0;
	
	if (NULL != aRectangle)
	{
		float dX = (aRectangle->A->x - aRectangle->B->x);
		float dY = (aRectangle->A->y - aRectangle->B->y);
		float Widht = sqrt(dX*dX + dY*dY);
		dX = (aRectangle->A->x - aRectangle->D->x);
		dY = (aRectangle->A->y - aRectangle->D->y);
		float Height = sqrt(dX*dX + dY*dY);
		theResult = Widht * Height;
	}
	else
	{
		printf("Rectanglen == NULL\n");
	}
	
	return theResult;
}



void printRectangle(Rectangle *aRectangle)
{
	if (NULL != aRectangle)
	{
		printf ("[Rectangle]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d) Area: %f\n",
					aRectangle->A->x, aRectangle->A->y,
					aRectangle->B->x, aRectangle->B->y,
					aRectangle->C->x, aRectangle->C->y,
					aRectangle->D->x, aRectangle->D->y,
					areaRectangle(aRectangle));
	}
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}


void writeeRectangleToJSON(FILE *aFile, Rectangle *aRectangle)
{
	if (NULL == aRectangle || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aRectangle->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aRectangle->B);
	fprintf(aFile, ", \n\"C\" : ");
	writePointToJSON(aFile, aRectangle->C);
	fprintf(aFile, ", \n\"D\" : ");
	writePointToJSON(aFile, aRectangle->D);
	fprintf(aFile, "\n}");
}



Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	
	return theResult;
}

Point *creatPointWithCoordinate(int x, int y)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}
	
	return theResult;
}

