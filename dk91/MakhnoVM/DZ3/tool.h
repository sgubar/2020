#include <stdio.h>

typedef struct tagPoint							// опис структури Point
{
	int x;		
	int y;
}Point;

typedef struct tagLine						// опис структури Line
{
	Point* A;
	Point* B;
}Line;

typedef struct tagRectangle
{
	Line* line;
}Rect;

typedef struct tagArrayInfo
{
	int size_array;
	Rect** arr;
}ArrayInfo;

/////////////////////////////////////// Створення прямокутника /////////////////////////////////////////////////

Point* createPoint();

Line* createLine();

Rect* createRect();

///////////////////////////////////////////////////// Створення масиву прямокутників///////////////////////////////////////////

ArrayInfo* createArr(int size_array);

/////////////////////////////////////////// Додавання елементу до масиву ////////////////////////////////////////////

void addRect(ArrayInfo* c);

////////////////////////////////////запис в JSON /////////////////////////////////////////////////////////

void writeArrayToJSON(FILE *aFile, ArrayInfo* c);

void writeLineToJSON(FILE *aFile, Line* aline);

void writePointToJSON(FILE *aFile, Point* aPoint);

//////////////////////////////////////// функції з дз 2 ////////////////////////////////////////////////

void area(Line* line);

int check(Line* line);

void Free(ArrayInfo* c);



