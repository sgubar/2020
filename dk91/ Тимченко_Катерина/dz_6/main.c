#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void doTestSLList();
void PrintList(const DoubleList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{
    DoubleList *theList = createList();
    PrintList(theList);
    DoubleNode *Element2 = createNode(2.50);
	DoubleNode *Element4 = createNode(4.75);

    AddElement(theList, Element2);
    PrintList(theList);
    AddElement(theList, Element4);

    AddElement(theList, createNode(6.45));
    AddElement(theList, createNode(8.25));

    DoubleNode *Element = createNode(5.75);

    AddEelementByIndex(theList, Element, 4);
    AddEelementByIndex(theList, createNode(10.50), 2);
    PrintList(theList);

    Element = RemoveElement(theList, 4);
	AddEelementByIndex(theList, Element, 2);
	printf("\nElement was removed\n\n");
	PrintList(theList);

    quickSort(theList, 0, theList->size-1);
    printf("\nList was sorted\n\n");
    PrintList(theList);

    FreeList(theList);

    printf("\nList was deleted!\n");

	return 0;

}

void PrintList(const DoubleList *aList)
{
    printf("Size of list: %d\n", SizeList(aList));

    for (int i = 0; i < SizeList(aList); i++)
    {
        DoubleNode *Element = ElementsAtIndex(aList, i);
        if (NULL != Element)
        {
            printf("Element[%d]: %f\n", i, Element->value);
        }
    }
}

