#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tool.h"

/////////////////////////////////////// Створення прямокутника /////////////////////////////////////////////////
Point* createPoint()
{
	Point* A = (Point*)malloc(sizeof(Point));
	printf("point A : x = ");
	scanf("%d", &A->x);
	printf("point A : y = ");
	scanf("%d", &A->y);
	return A;
}

Line* createLine()
{
	Point* a = createPoint();
	Point* b = createPoint();
	Line* ab = (Line*)malloc(sizeof(Line));
	ab->A = a;
	ab->B = b;
	return ab;
}

Rect* createRect()
{
	Rect* priam = (Rect*)malloc(sizeof(Rect));
	priam->line = createLine();
	return priam;
}

///////////////////////////////////////////////////// Створення масиву прямокутників///////////////////////////////////////////

ArrayInfo* createArr(int size_array)
{
	ArrayInfo* c = (ArrayInfo*)malloc(sizeof(ArrayInfo));
	c->arr = (Rect**)malloc(size_array * sizeof(Rect*));
	c->size_array = size_array;
	for(int i = 0; i < size_array; i++){
		c->arr[i] = createRect();
	}
	return c;
}

/////////////////////////////////////////// Додавання елементу до масиву ////////////////////////////////////////////

void addRect(ArrayInfo* c)
{
	c->size_array += 1;
	Rect** array_n = (Rect**)malloc(c->size_array * sizeof(Rect*));
	memcpy(array_n, c->arr, c->size_array - 1);
	array_n[c->size_array - 1] = createRect();
	c->arr = array_n;
	free(array_n);
}

////////////////////////////////////запис в JSON /////////////////////////////////////////////////////////

void writeArrayToJSON(FILE *aFile, ArrayInfo* c)
{
	if (NULL == c || NULL == aFile)
	{
		return ;
	}
	for(int i = 0; i < c->size_array; i++){
		fprintf(aFile, "the number of the rectangle in the array : %d \t line 1 \t", i);
		writeLineToJSON(aFile, c->arr[i]->line);
	}
	
}

void writeLineToJSON(FILE *aFile, Line* aline)
{
	if (NULL == aline || NULL == aFile)
	{
		return ;
	}
	fprintf(aFile, "Point A : ");
	writePointToJSON(aFile, aline->A);
	fprintf(aFile, "Point B : ");
	writePointToJSON(aFile, aline->B);
}

void writePointToJSON(FILE *aFile, Point* aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}
	fprintf(aFile, "{x = %d \t y = %d}\n", aPoint->x, aPoint->y);
}

//////////////////////////////////////// функції з дз 2 ////////////////////////////////////////////////

void area(Line* line)
{
	printf("%d",abs((line->A->x - line->B->x) * (line->A->y - line->B->y)));
}

int check(Line* line)
{
	if(line->A->x == line->B->x || line->A->y == line->B->y)return -1;
	return 0;
}

void Free(ArrayInfo* c)
{
	for(int i = 0; i < c->size_array; i++){
		free(c->arr[i]->line->A);
		free(c->arr[i]->line->B);
	}
	for(int i = 0; i < c->size_array; i++){
		free(c->arr[i]->line);
	}
	for(int i = 0; i < c->size_array; i++){
		free(c->arr[i]);
	}
	free(c->arr);
	free(c);
}
