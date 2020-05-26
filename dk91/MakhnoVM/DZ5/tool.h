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
	int Area;
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

void addRect(ArrayInfo* anArray);

////////////////////////////////////запис в JSON /////////////////////////////////////////////////////////

void writeArrayToJSON(FILE *aFile, ArrayInfo* anArray);

void writeLineToJSON(FILE *eFile, Rect* arr);

void writePointToJSON(FILE *eFile, Point* aPoint);

//////////////////////////////////////// функції з дз 2 ////////////////////////////////////////////////

int area(Line* line);

int check(Line* line);

void Free(ArrayInfo* theArray);

/////////////////////////////////// бульбашкою /////////////////////////////////////

void arraySort(ArrayInfo* theArray);

//////////////////////////////////// швидке сортування /////////////////////////////

void quickSort(Rect** arr, int first, int last);

///////////////////////////////////// бінарний пошук /////////////////////////////////////////

void binarySearch(int key, Rect** arr, int left, int right);


