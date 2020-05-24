#include <String.h>
#include "Array.h"
char *randomCharArray(char *point, int maxSize, int seed);

int partitionIt(ArrayInfo *info, int aLeftIndex, int aRightIndex, char *aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;
	
	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && Compare(info->Array[++theLeft], aPivot) < 0);
	
		// search the lowest element
		while (theRight > aLeftIndex && Compare(info->Array[--theRight], aPivot) > 0);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(info, theLeft, theRight);
		}
	}
	
	return theLeft; // return break position
}

void sort(ArrayInfo *info)
{
	quickSort(info, 0, info->len-1);
}

void quickSort(ArrayInfo *info, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}
	
	char *thePivot = info->Array[aRightIndex];
	int thePartitionIndex = partitionIt(info, aLeftIndex, aRightIndex, thePivot);
	
	//left part sorting
	quickSort(info, aLeftIndex, thePartitionIndex - 1);
	
	//right part sorting
	quickSort(info, thePartitionIndex + 1, aRightIndex);
}


int Compare(char *a, char *b)
{
	if(NULL == a || NULL == b)
		return ERROR;
	int out = 0;
	for(;tolower(a[out]) == tolower(b[out]); out++)
	{
		if(a[out] == '\0')
			return 0;
	}
	if('\0' == a[out] || '\0' == b[out])
	{
		return '\0' == b[out] ? 1 : -1;
	}
	return (tolower(a[out]) > tolower(b[out])) ? 1 : -1;
}

void swap(ArrayInfo *info,int a, int b)
{
	printf("swap(%i, %i)\n", a, b);
	//lets to swap elements
	char *theTmp = info->Array[a];
	info->Array[a] = info->Array[b];
	info->Array[b] = theTmp;
}

void freeArray(ArrayInfo *info)
{
	free(info->Array);
	free(info->data);
	free(info);
}
void printArray(ArrayInfo *info)
{
	for(int i = 0;i < info->len;i++)
	{
		printf("(%i) %s\n", i, info->Array[i]);
	}
}
void SaveArray(ArrayInfo *info, FILE *aFile)
{
	for(int i = 0;i < info->len;i++)
	{
		fprintf(aFile, "%s\n", info->Array[i]);
	}
}

ArrayInfo *LoadArray(FILE *aFile){
	ArrayInfo *info = (ArrayInfo *)malloc(sizeof(ArrayInfo));
	fseek(aFile, 0, SEEK_END);
	long size = ftello(aFile);
	fseek(aFile, 0, SEEK_SET);
	info->data = (char *)malloc((size + 1) * sizeof(char));
	int s = size/20, j = 0;
	info->Array = (char **)malloc(s * sizeof(char *));
	int p = 0;								//зчитування з файлу
	while(!feof(aFile))
	{
		fscanf(aFile, "%c", &info->data[p]);	
		p++;
	}

	if(size != 0)
	{
		info->Array[j] = &info->data[0];
		j++;
	}
	else
		return NULL;
	for(int i = 0; i < size; i++)
	{
		if((info->data[i] == ' ' || info->data[i] == '\n') && (i + 1 < size))
		{
			info->Array[j] = &info->data[i + 1];
			info->data[i] = '\0';
			j++;
		}
		if(j == s)
		{
			s *= 2;
			info->Array = (char **)realloc(info->Array, s * sizeof(char *));
		}
	}
	info->len = j;
	return info;
}
char *randomCharArray(char *point, int maxSize, int seed)
{
	srand(seed);
	int size = (rand() % maxSize) + 1;
	if(size < 3)
		size = 3;
    char *array = point;
    

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

ArrayInfo *randomStrArray(int size, int strMaxSize)
{
	ArrayInfo *info = (ArrayInfo *)malloc(sizeof(ArrayInfo));
	if(info == NULL)
		return NULL;
	info->data = (char *)malloc(size*(strMaxSize + 1)*sizeof(char));
	info->Array = (char **)malloc(size*sizeof(char *));
	info->len = size;
	for(int i = 0;i < size; i++)
	{
		info->Array[i] = info->data + (strMaxSize + 1)*i;
		randomCharArray(info->Array[i], strMaxSize, time(NULL) + i * 876);
	}
	return info;
}

int Search(ArrayInfo *info,char *key){
	return BinarySearch(info, 0, info->len-1, key);
}
int BinarySearch(ArrayInfo *info,int left, int right, char *key)
{
	unsigned theResult = info->len;
	unsigned theLowerBound = 0;
	unsigned theUpperBound = info->len - 1;
	unsigned theCurIn = 0;
	
	while (1)
	{
		theCurIn = (theLowerBound + theUpperBound) / 2;
		if (strcmp(key, info->Array[theCurIn]) == 0) //<!- an element was found
		{
			theResult = theCurIn;
			break;
		}
		else if (theLowerBound > theUpperBound) //<!- all elements were viewed
		{
			break;
		}
		else
		{
			if (strcmp(key, info->Array[theCurIn]) > 0)
			{
				theLowerBound = theCurIn + 1; //!<- in upper position
			}
			else
			{
				theUpperBound = theCurIn - 1; //!<- in lower position
			}
		}
	
	}
	
	return (int)theResult;
}

/*void bubbleSort(int anArray[], int aSize)
{
	for (int theOut = aSize - 1; theOut > 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}

void selectionSort(int anArray[], int aSize)
{
	for (int theOut = 0; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (int theIn = theOut + 1; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
	
		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}

void insertionSort(int anArray[], int aSize)
{
	for (int theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}
	
		anArray[theIn] = theTmp;
	}
}*/
