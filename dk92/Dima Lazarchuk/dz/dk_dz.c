#include "dk_tool.h"
#include "dk_geo.h"
#include "dk_geo_array.h"

void dz1()
{
	char *str = "test 1 tes 2 test 3 tst 4";
	char *a = "tes";
	char *b = "t";
	printf("result: %d\n",str_find(str,a));
	printf("result: %d\n",str_find(str,b));
}

void dz2()
{
	Point A = {2,3};
	Point B = {4,3};
	Point C = {4,6};
	Point D = {2,6};
	
	Rectangle *ABCD = createRectangle(&A, &B, &C, &D);
	Rectangle *TEST = createRectangleWithCoordinate(0, 1, 5, 1, 5, 2, 0, 2);

	printRectangle(ABCD);
	printRectangle(TEST);
	
	float test = areaRectangle(ABCD);
	printf("The area of Rectangle ABCD = %f\n", test);
	
	destroyRectangle(ABCD);
	destroyRectangle(TEST);
}

void dz3()
{
	RectangleArray *theArray = createArray(10);
	
	Point A = {2,3};
	Point B = {4,3};
	Point C = {4,5};
	Point D = {2,5};
	Rectangle ABCD = {&A, &B, &C, &D};
	
	addElement(theArray, &ABCD);
	
	printArray(theArray);
	
	A.y = 1;
	B.y = 1;

	addElement(theArray, &ABCD);
	printArray(theArray);

	B.x = 28;
	C.x = 28;

	addElement(theArray, &ABCD);
	printArray(theArray);
	
	B.x = 17;
	C.x = 17;

	addElement(theArray, &ABCD);
	printArray(theArray);

	B.x = 19;
	C.x = 19;

	addElement(theArray, &ABCD);
	printArray(theArray);

	B.x = 15;
	C.x = 15;

	addElement(theArray, &ABCD);
	printArray(theArray);
	
	sort_simple(theArray);
//	sort_select(theArray);
//	insertionSort(theArray);
	printArray(theArray);
	
	FILE *theFile = fopen("../test.json", "a+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArray(theArray);

}
