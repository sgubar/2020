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
	priam->Area = area(priam->line);
	return priam;
}

///////////////////////////////////////////////////// Створення масиву прямокутників///////////////////////////////////////////

ArrayInfo* createArr(int size_array)
{
	ArrayInfo* anArray = (ArrayInfo*)malloc(sizeof(ArrayInfo));
	anArray->arr = (Rect**)malloc(size_array * sizeof(Rect*));
	for(int i = 0; i < size_array; i++){
		anArray->arr[i] = createRect();
	}
	anArray->size_array = size_array;
	return anArray;
}

/////////////////////////////////////////// Додавання елементу до масиву ////////////////////////////////////////////

void addRect(ArrayInfo* anArray)
{
	Rect** array_n = (Rect**)malloc(anArray->size_array * sizeof(Rect*));
	for(int i = 0; i < (anArray->size_array - 1); i++){
		array_n[i] = anArray->arr[i];
	}
	array_n[anArray->size_array - 1] = createRect();
	for(int i = 0; i < anArray->size_array; i++){
		anArray->arr[i] = array_n[i];
	}
	free(array_n);
}

////////////////////////////////////запис в JSON /////////////////////////////////////////////////////////

void writeArrayToJSON(FILE *aFile, ArrayInfo* anArray)
{
	if (NULL == anArray->arr || NULL == aFile)return ;

    
    for (int i = 0; i < anArray->size_array; i++)
    {
    	fprintf(aFile, "Rectangle : \n\n");
    	fprintf(aFile, "{\nnumber : %d,\n", i);
        writeLineToJSON(aFile, anArray->arr[i]);
        fprintf(aFile, "\n}\n}\n\n");
    }

    fprintf(aFile, "\n");
	
}

void writeLineToJSON(FILE *eFile, Rect* arr)
{
	if (NULL == arr->line|| NULL == eFile) return ;


    fprintf(eFile, "{\n\t\"A\" : ");
    writePointToJSON(eFile, arr->line->A);
    fprintf(eFile, ", \n\t\"B\" : ");
    writePointToJSON(eFile, arr->line->B);
    fprintf(eFile, ", \n\t\"Area\" : %d,", arr->Area);
}

void writePointToJSON(FILE *eFile, Point* aPoint)
{
	if (NULL == aPoint || NULL == eFile)
            return ;


    fprintf(eFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

//////////////////////////////////////// функції з дз 2 ////////////////////////////////////////////////

int area(Line* line)
{
	return abs((line->A->x - line->B->x) * (line->A->y - line->B->y));
}

int check(Line* line)
{
	if(line->A->x == line->B->x || line->A->y == line->B->y)return -1;
	return 0;
}

void Free(ArrayInfo* theArray)
{
	for(int i = 0; i < theArray->size_array; i++){
		free(theArray->arr[i]->line->A);
		free(theArray->arr[i]->line->B);
		free(theArray->arr[i]->line);
		free(theArray->arr[i]);
	}
	free(theArray->arr);
	free(theArray);
}

/////////////////////////////////// бульбашкою /////////////////////////////////////


void arraySort(ArrayInfo* theArray)
{
	for(int i = 0; i < theArray->size_array; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(theArray->arr[j - 1]->Area > theArray->arr[j]->Area)
			{
				Rect* c;
				c = theArray->arr[j];
				theArray->arr[j] = theArray->arr[j + 1];
				theArray->arr[j + 1] = c;
			}else break;
		}
	}
}

//////////////////////////////////// швидке сортування /////////////////////////////

void quickSort(Rect** arr, int first, int last)
{
	
    if (first < last)
    {
        int left = first, right = last;
        int middle = arr[(left + right) / 2]->Area;
        do
        {
            while (arr[left]->Area < middle) left++;
            while (arr[right]->Area > middle) right--;
            if (left <= right)
            {

                Rect* tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(arr, first, right);
        quickSort(arr, left, last);
    }
}

///////////////////////////////////// бінарний пошук /////////////////////////////////////////

void binarySearch(int key, Rect** arr, int left, int right)
{
	int search = -1;
	while (left <= right) 
	{
    	int mid = (left + right) / 2; 
    		if (key == arr[mid]->Area) {  
     	 	search = mid;     
     		 break;            
    	}
    	if (key < arr[mid]->Area)     
      		right = mid - 1;  
    	else                  
      		left = mid + 1;   
 	}
  	if (search == -1) printf("Элемент не найден!\n");    
   	else   printf("Номер элемента в массиве %d", search);       
    
}