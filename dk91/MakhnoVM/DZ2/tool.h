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
void area(Line* line);
int check(Line* line);
void Free(Line* line);