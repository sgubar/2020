#include "array.h"

Array *createArray(int size)
{
    Array *array = NULL;

    if (size > 0)
    {
        array = (Array *)malloc(sizeof(Array));

        if (array != NULL)
        {
            array->triangles = (Triangle *)calloc(sizeof(Triangle *), size);
            array->size = size;
            array->count = 0;
        }
    }
}

Triangle getByIndex(Array *array, int index)
{
    return array->triangles[index];
}

int pushToArray(Array **array, Triangle triangle)
{
    for (int i = 0; i < (*array)->size; i++)
    {
        if (i == (*array)->count)
        {
            (*array)->triangles[i] = triangle;
            return (*array)->count++;
        }
    }
    return -1;
}

int setByIndex(Array **array, Triangle triangle, int index)
{
    if (index < (*array)->size)
    {
        (*array)->triangles[index] = triangle;
        return index;
    }
    return -1;
}

void printArray(Array *array)
{
    for (int i = 0; i < array->count; i++)
    {
        printf("Triangle #%d\n", i + 1);
        printTriangle(&array->triangles[i]);
        printf("Area: %.2f \n", getArea(array->triangles[i]));
        printf("================================\n");
    }
}

void deleteArray(Array *array)
{
   free (array);
}

void serializeArrayToJson(FILE *file, Array *array)
{

    fprintf(file, "{\n\t\"size\" : %d,\n\t\"count\" : %d,\n", array->size, array->count);
    fprintf(file, "\t\"triangles\" : \n\t[\n");

    for (int i = 0; i < array->count; i++)
    {
        Triangle triangle = array->triangles[i];
        serializeTriangleToJSON(file, triangle);

        if (i < array->count - 1)
        {
            fprintf(file, ",");
        }
    }

    fprintf(file, "\t]\n}");
}

void swap(Array *arr, int findex, int sindex)
{
    Triangle temp = getByIndex(arr, findex);
    setByIndex(&arr, getByIndex(arr, sindex), findex);
    setByIndex(&arr, temp, sindex);
}

void bubbleSort(Array *arr)
{
    for (int i = 0; i < arr->count - 1; i++)
        for (int j = 0; j < arr->count - i - 1; j++)
            if (getArea(getByIndex(arr, j)) > getArea(getByIndex(arr, j + 1)))
                swap(arr, j, j + 1);
}

void selectionSort(Array *arr)
{

    for (int i = 0; i < arr->count - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < arr->count; j++)
            if (getArea(getByIndex(arr, j)) < getArea(getByIndex(arr, min_idx)))
                min_idx = j;

        swap(arr, min_idx, i);
    }
}

void insertionSort(Array *arr)
{
    for (int i = 1; i < arr->count; i++)
    {
        Triangle key = getByIndex(arr, i);
        int j = i - 1;

        while (j >= 0 && getArea(getByIndex(arr, j)) > getArea(key))
        {
            setByIndex(&arr, getByIndex(arr, j), j + i);
            j = j - 1;
        }
        setByIndex(&arr, key, j + 1);
    }
}
void shellSort(Array *arr)
{
    for (int step = arr->count / 2; step > 0; step /= 2)
        for (int i = step; i < arr->count; i++)
        {
            Triangle Itmp = getByIndex(arr, i);
            int j;
            for (j = i; j >= step; j -= step)
            {
                Triangle Jtmp = getByIndex(arr, j - step);
                if (getArea(Itmp) < getArea(Jtmp))
                    setByIndex(&arr, Jtmp, j);
                else
                    break;
            }
            setByIndex(&arr, Itmp, j);
        }
}

Triangle *linearSearch(Array *arr, float area)
{
    Triangle tmp;
    Triangle *result = malloc(sizeof(Triangle));

    for (int i = 0; i < arr->count; i++)
    {
        tmp = getByIndex(arr, i);
        if (getArea(tmp) == area)
        {
            *result = tmp;
            return result;
        }
    }
    return NULL;
}