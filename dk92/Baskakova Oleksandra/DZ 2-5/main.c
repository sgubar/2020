#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "array.h"

void thirdHomeWork();
void secondHomeWork();
void fourthHomework();
void fifthHomework();
int main(int argc, char const *argv[])
{
	// secondHomeWork();
	// thirdHomeWork();
	//fourthHomework();
	fifthHomework();
	return 0;
}

void secondHomeWork()
{
	Triangle *triangle = readTriangle();
	printTriangle(triangle);
	printf("Area: %.2f \n", getTriangleArea(triangle));
	clearTriangle(triangle);
}

void thirdHomeWork()
{

	Array *array = NULL;
	while (1)
	{
		printf("________MENU_______\n");
		printf("1: create array;\n");
		printf("2: fill triangles;\n");
		printf("3: set by index;\n");
		printf("4: print array;\n");
		printf("5: serialize to json;\n");
		printf("6: exit;\n");

		int mode;
		scanf("%d", &mode);

		if (!(mode != 1 || mode != 5) && array == NULL)
		{
			printf("Array not initialized\n");
			continue;
		}
		switch (mode)
		{
		case 1:
		{
			printf("\n");
			int size = getInt("Write down the size of array: \n");
			array = createArray(size);
		}
		break;
		case 2:
		{
			for (int i = 0; i < array->size; i++)
			{
				printf("Triangle #%d\n", i + 1);
				printf("index of element: %d\n", pushToArray(&array, *readTriangle()));
				printf("================================\n");
			}
		}
		break;
		case 3:
		{
			int index = getInt("Write down index of element:\n");
			printf("index of element: %d\n", setByIndex(&array, *readTriangle(), index));
		}
		break;
		case 4:
		{
			printArray(array);
		}
		break;
		case 5:
		{
			FILE *file = fopen("Triangles.json", "w");
			serializeArrayToJson(file, array);
			fclose(file);
		}
		break;
		case 6:
		{
			if (array != NULL)
				deleteArray(array);
			return;
		}
		break;
		default:
			printf("write number from 1 to 6");
		}
	}
}

void fourthHomework()
{
	Array *array = NULL;
	while (1)
	{
		printf("________MENU_______\n");
		printf("1: create array;\n");
		printf("2: print array;\n");
		printf("3: sort by buble;\n");
		printf("4: sort by insertion;\n");
		printf("5: sort by selection;\n");
		printf("6: exit;\n");

		int mode;
		scanf("%d", &mode);

		if (!(mode != 1 || mode != 5) && array == NULL)
		{
			printf("Array not initialized\n");
			continue;
		}
		switch (mode)
		{
		case 1:
		{
			printf("\n");
			int size = getInt("Write down the size of array: \n");
			array = createArray(size);
			for (int i = 0; i < array->size; i++)
			{
				printf("Triangle #%d\n", i + 1);
				printf("index of element: %d\n", pushToArray(&array, *readTriangle()));
				printf("================================\n");
			}
		}
		break;
		case 2:
		{
			printArray(array);
		}
		break;
		case 3:
		{
			bubbleSort(array);
			printArray(array);
		}
		break;
		case 4:
		{
			insertionSort(array);
			printArray(array);
		}
		break;
		case 5:
		{
			selectionSort(array);
			printArray(array);
		}
		break;
		case 6:
		{
			if (array != NULL)
				deleteArray(array);
			return;
		}
		break;

		default:
			printf("write number from 1 to 6");
		}
	}
}

void fifthHomework()
{
	Array *array = NULL;
	while (1)
	{
		printf("________MENU_______\n");
		printf("1: create array;\n");
		printf("2: print array;\n");
		printf("3: sort by shell;\n");
		printf("4: serch by area;\n");
		printf("5: exit;\n");

		int mode;
		scanf("%d", &mode);

		if (!(mode != 1 || mode != 5) && array == NULL)
		{
			printf("Array not initialized\n");
			continue;
		}
		switch (mode)
		{
		case 1:
		{
			printf("\n");
			int size = getInt("Write down the size of array: \n");
			array = createArray(size);
			for (int i = 0; i < array->size; i++)
			{
				printf("Triangle #%d\n", i + 1);
				printf("index of element: %d\n", pushToArray(&array, *readTriangle()));
				printf("================================\n");
			}
		}
		break;
		case 2:
		{
			printArray(array);
		}
		break;
		case 3:
		{
			shellSort(array);
			printArray(array);
		}
		break;
		case 4:
		{
			float area = getFloat("Enter area of triangle you looking for: \n");
			Triangle *result = linearSearch(array, area);
			if (result)
			{
				printTriangle(result);
				clearTriangle(result);
			}
			else
			{
				printf("Can't find \n");
			}
		}
		break;
		case 5:
		{
			if (array != NULL)
				deleteArray(array);
			return;
		}
		break;

		default:
			printf("write number from 1 to 5");
		}
	}
}