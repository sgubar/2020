#include <stdio.h>
#include "LinkedNode.h"
#include "SingleLinked_List.h"
#include "sort.h"


    int main()
{
	IntList *thelist = CreateList();
	int value;
	int i;
	printf("\n\nAdd elements :\n\n");
			for(i = 0; i < 9; i++)
		 	{
               printf("Node [ %d ] - ", i);
			   scanf("%d", &value);
               IntNode *theNode = CreateNode(value);
               AddNode(thelist, theNode);
			}
		doPrintList(thelist);

		printf("\n MIN = Node [ %d ]\n\n", Minimal(thelist));

        Sort(thelist, Minimal(thelist),thelist->acount-1 );


		doPrintList(thelist);

		return 0;
}

