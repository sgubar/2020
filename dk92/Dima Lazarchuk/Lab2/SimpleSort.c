
#include "SimpleSort.h"

void bubbleSort(Word *Start, Word *End)
{
	for (Word *theOut = End; theOut != Start->next; theOut = theOut->pr)
	{
		for (Word *theIn = Start; theIn != theOut; theIn = theIn->next)
		{
			if (Compare(theIn->str, theIn->next->str) > 0)
			{ 
				swap(theIn, theIn->next);				
			}
		}
	}
}

void selectionSort(Word *Start, Word *End)
{
	for (Word *theOut = Start; theOut != End; theOut = theOut->next)
	{
		Word *theMinIndex = theOut;
	
		for (Word *theIn = theOut->next; theIn != End->next; theIn = theIn->next)
		{
			if (Compare(theIn->str, theMinIndex->str) < 0)
			{
				theMinIndex = theIn;
			}
		}
		swap(theOut, theMinIndex);
	}
}

void insertionSort(Word *Start, Word *End)
{
	for (Word *theOut = Start->next; theOut != End->next; theOut = theOut->next)
	{
		char *theTmp = theOut->str;
		Word *theIn = theOut;
	
		while (theIn != Start && Compare(theIn->pr->str, theTmp) >= 0)
		{
			theIn->str = theIn->pr->str;
			theIn = theIn->pr;
		}
	
		theIn->str = theTmp;
	}
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

void swap(Word *a, Word *b)
{
	char *tmp = a->str;
	a->str = b->str;
	b->str = tmp;
//	swappoints(a, b);
//	if(a->pr != NULL)
//		if(a->pr != a)
//			a->pr->next = a;
//		else
//			a->pr = b;
//	if(a->next != NULL)
//		if(a->next != a)
//			a->next->pr = a;
//		else
//			a->next = b;
//	if(b->pr != NULL)
//		if(b->pr != b)
//			b->pr->next = b;
//		else
//			b->pr = a;
//	if(b->next != NULL)
//		if(b->next != b)
//			b->next->pr = b;
//		else
//			b->next = a;
}

void swappoints(Word *a, Word *b)
{
	Word *temppr = a->pr;
	Word *tempnext = a->next;
	a->pr = b->pr;
	a->next = b->next;
	b->pr = temppr;
	b->next = tempnext;
}
