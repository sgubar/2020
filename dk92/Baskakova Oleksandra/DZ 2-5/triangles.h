#ifndef TRIANGLES_H
#define TRIANGLRS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;
typedef struct Triangle
{
    Point *points[3];

} Triangle;
int validate(Point **points);
Triangle *createTriangle(Point **points);
float getTriangleArea(Triangle *triangle);
float getArea(Triangle triangle);
void clearTriangle(Triangle *triangle);
void printTriangle(Triangle *triangle);
void serializePointToJSON(FILE *file, Point* point);
void serializeTriangleToJSON(FILE *file, Triangle triangle);
Triangle* readTriangle();
#endif