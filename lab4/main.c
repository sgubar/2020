#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "ListNode.h"

void doPrintList(const IntList *aList);
IntList *EnterList();
int ReadInt(char *str);

int main(int argc, char *argv[]) 
{
	IntList *asdf = EnterList();
	doPrintList(asdf);
	int ch = ReadInt("Vedite Chislo:\n");
	SLPer(asdf, ch);
	doPrintList(asdf);

	return 0;
}

IntList *EnterList()
{
	int Count = ReadInt("Enter count of elements\n");
	IntList *list = SLCreateList();
	for(; Count > 0; Count--)
	{
		int c = ReadInt("Enter value:\n");
		IntNode *node = SLCreateNodeWithIntValue(c);
		SLAddNode(list, node);
	}
	return list;
}


void doPrintList(const IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

int ReadInt(char *str)
{
	printf(str);
	int a = 0;
	while(scanf("%i", &a) == 0);
	return a;
}
