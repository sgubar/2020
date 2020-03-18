#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "SimpleSort.h"

#define STR_MAX_LEN 40
//#define ARRAY_DEF_SIZE 50
//#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

Word *LoadArray(FILE *aFile);
void SaveArray(Word *first, FILE *aFile);
void printArray(Word *Array);
void freeArray(Word *first);
Word *randomStrArray(int size, int strMaxSize);

int main(int argc, char *argv[]) 
{
	TestSort();
//	FILE *fp = fopen("testR.txt", "w");
//    Word *ar = randomStrArray(20000, 150);//LoadArray(fp);
//    SaveArray(ar, fp);
//    Word *end = ar;
//	while(end->next != NULL)
//		end = end->next;
//    printf("\n\n\n\n");
//    insertionSort(ar, end);
//	FILE *fs = fopen("sorted.txt", "w");
//	SaveArray(ar, fs);
//	fclose(fs);
	//fclose(fp);
//	freeArray(ar);
	return 0;
}

void TestSort()
{
	FILE *fp = fopen("testR.txt", "w");
	clock_t theStart0 = clock();
	Word *ar = randomStrArray(20000, 150);
	clock_t theEnd0 = clock();
	printf ("Time of fill 20000 array: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	theStart0 = clock();
	SaveArray(ar, fp);
	theEnd0 = clock();
	printf ("Time of save 20000 array: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	fclose(fp);
	Word *end = ar;
	while(end->next != NULL)
		end = end->next;
	theStart0 = clock();
	insertionSort(ar, end);
	theEnd0 = clock();
	printf ("Time of insertionSort 20000 array: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	freeArray(ar);
	FILE *ft = fopen("testR.txt", "r");
	theStart0 = clock();
	Word *ar2 = LoadArray(ft);
	theEnd0 = clock();
	printf ("Time of load 20000 array: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	Word *end2 = ar2;
	while(end2->next != NULL)
		end2 = end2->next;
	theStart0 = clock();
	selectionSort(ar2, end2);
	theEnd0 = clock();
	printf ("Time of selectionSort 20000 array: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	freeArray(ar2);
	fseek(ft, 0, SEEK_SET);
	Word *ar3 = LoadArray(ft);
	Word *end3 = ar3;
	while(end3->next != NULL)
		end3 = end3->next;
	theStart0 = clock();
	bubbleSort(ar3, end3);
	theEnd0 = clock();
	printf ("Time of bubbleSort 20000 array: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	freeArray(ar3);
	fclose(ft);
}

void freeArray(Word *first)
{
	free(first->str);
	if(first->next != NULL)
		freeArray(first->next);
	free(first);
}

void printArray(Word *Array)
{
	int i = 0;
	while(Array != NULL)
	{
		printf("string #%i: %s\n", i, Array->str);
		i++;
		Array = Array->next;
	}
}

void SaveArray(Word *first, FILE *aFile)
{
	while(first != NULL)
	{
		fprintf(aFile, "%s\n", first->str);
		first = first->next;
	}
}

char *randomCharArray(int maxSize, int seed)
{
	srand(seed);
	int size = (rand() % maxSize) + 1;
	if(size < 3)
		size = 3;
    char *array = (char *)malloc(sizeof(char) * size);
    

    if (array != NULL)
    {
        
        int tmp;
        for (int i = 0; i < size-1; ++i)
        {
            if (rand() % 2 == 0)
            {
                tmp = rand() % (90 - 65) + 65;
            }
            else
            {
                tmp = rand() % (122 - 97) + 97;
            }

            array[i] = (char)tmp;
        }
        array[size -1] = '\0';
    }

    return array;
}

Word *randomStrArray(int size, int strMaxSize)
{
	Word *first = (Word *)malloc(sizeof(Word));
	if(first == NULL)
		return NULL;
	Word *tmp = first;
	tmp->str = randomCharArray(strMaxSize, time(NULL));
	tmp->pr = NULL;
	tmp->next = NULL;
	for(int i = 1;i < size; i++)
	{
		Word *t = (Word *)malloc(sizeof(Word));
		if(t == NULL)
			break;
		tmp->next = t;
		t->next = NULL;
		t->pr = tmp;
		t->str = randomCharArray(strMaxSize, time(NULL) + i * 876);
		tmp = t;
	}
	return first;
}

Word *LoadArray(FILE *aFile)
{
	char *buffer = malloc(sizeof(char) * STR_MAX_LEN);
	if(buffer == NULL)
	{
		printf("Cannot allocate memory for buffer");
		return NULL;
	}
	Word *bArray = NULL;
	char c;
	int i = 0, j = 0, bSize = STR_MAX_LEN;
	while(1)
	{
		c = fgetc(aFile);
		if(c == EOF)
			break;
		if(j >= bSize)
		{
			buffer = (char *)realloc(buffer,sizeof(char) * bSize * 2);
			if(buffer == NULL)
			{
				printf("Error no memory %i", bSize * 2 * sizeof(char));
				return NULL;
			}
			bSize *= 2;
		}
		if(c == '\n')
		{
			buffer[j] = '\0';
			Word *w = malloc(sizeof(Word));
			if(w == NULL)
				return NULL;
			w->pr = bArray;
			w->next = NULL;
			if(bArray != NULL)
				bArray->next = w;
			w->str = malloc(sizeof(char) * (j +1));
			memcpy(w->str, buffer, j+1);
			bArray = w;
			#ifdef Debug
			printf("loaded word #%i: %s\n", i, bArray->str);
			#endif
			i++;
			j = 0;
			continue;
		}
		buffer[j] = c;
		j++;
	}
	free(buffer);
	printf("loaded #%i strings\n", i);
	Word *first = bArray;
	while(first->pr != NULL)
		first = first->pr;
	return first;
}

/*

char **LoadArray2(FILE *aFile)
{
	char array[ARRAY_DEF_SIZE][STR_MAX_LEN];
	char c;
	int i = 0, j = 0;
		while(1)
	{
		if(i >= ARRAY_DEF_SIZE)
		{
			break;
		}
		c = fgetc(aFile);
		if(c == EOF)
			break;
		if(c == '\n')
		{
			array[i][j] = '\0';
			
			printf("loaded string #%i: %u\n", i, array + i);
			i++;
			j = 0;
			continue;
		}
		if(j > STR_MAX_LEN)
		{
			array[i][j] = '\0';
			while(1)
			{
				c = fgetc(aFile);
				if(c == EOF)
					break;
				if(c == '\n')
					break;
			}
			printf("loaded string #%i: %s\n", i, array + i);
			i++;
			j = 0;
			continue;
		}
		array[i][j] = c;
		j++;
	}
	return array;
}*/
