#include "triangles.h"

int validate(Point **points)
{
    int x = points[0]->x == points[1]->x && points[0]->x == points[2]->x && points[1]->x == points[2]->x;
    int y = points[0]->y == points[1]->y && points[0]->y == points[2]->y && points[1]->y == points[2]->y;
    Triangle *testTriangle = createTriangle(points);

    if (x && y)
    {
        printf("three points are equals \n");
        return 1;
    }
    if (x || y || getTriangleArea(testTriangle) == 0)
    {
        printf("line can`t be a triangle \n");
        return 1;
    }
    return 0;
}

Triangle *createTriangle(Point **points)
{
    Triangle *triangle = (Triangle *)malloc(sizeof(triangle));

    for (int i = 0; i < 3; i++)
    {
        triangle->points[i] = points[i];
    }
    return triangle;
}

void clearTriangle(Triangle *triangle)
{
   // free(triangle->points);
    free(triangle);
}

void printTriangle(Triangle *triangle)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Point %d: \n", i + 1);
        printf("x:%d y:%d \n\n", triangle->points[i]->x, triangle->points[i]->y);
    }
}

Triangle *readTriangle()
{
    Point **points = calloc(3, sizeof(Point));
    do
    {
        for (int i = 0; i < 3; i++)
        {
            points[i] = malloc(sizeof(Point));
            printf("Write x coordinate for %d point: \n", i + 1);
            points[i]->x = getInt("");
            printf("Write y coordinate for %d point: \n", i + 1);
            points[i]->y = getInt("");
        }
    } while (validate(points));
    return createTriangle(points);
}

float getTriangleArea(Triangle *triangle)
{
    Point *a = triangle->points[0];
    Point *b = triangle->points[1];
    Point *c = triangle->points[2];
    return fabs(((a->x - c->x) * (b->y - c->y)) - ((b->x - c->x) * (a->y - c->y))) / 2;
}

float getArea(Triangle triangle)
{
    Point *a = triangle.points[0];
    Point *b = triangle.points[1];
    Point *c = triangle.points[2];
    return fabs(((a->x - c->x) * (b->y - c->y)) - ((b->x - c->x) * (a->y - c->y))) / 2;
}

void serializeTriangleToJSON(FILE *file, Triangle triangle)
{
    Point **points = triangle.points;
    fprintf(file, "\t\t{\n");
    fprintf(file, "\t\t\"points\": [\n");
    for (int i = 0; i < 3; i++)
    {
        serializePointToJSON(file, points[i]);
        if (i != 2)
            fprintf(file, ",");
        fprintf(file, "\n");
    }
    fprintf(file, "\t\t\t]\n\t\t\t}\n");
}

void serializePointToJSON(FILE *file, Point *point)
{
    fprintf(file, "\t\t\t\t\{\n");
    fprintf(file, "\t\t\t\t\"x\":\"%d\",\n\t\t\t\t\"y\":\"%d\"\n", point->x, point->y);
    fprintf(file, "\t\t\t\t}");
}