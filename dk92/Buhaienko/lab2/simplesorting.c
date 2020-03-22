#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simplesorting.h"
void bubbule(char Array[], int Size)
{
	for (int Out = Size - 1; Out > 1; Out --)
	{
		for (int In = 0; In < Out; In ++)
		{
			if (Array[In] < Array[In + 1])
			{
				char Tmp = Array[In];
				Array[In] = Array[In + 1];
				Array[In + 1] = Tmp;
			}
		}
	}
}

void selection(char Array[], int Size)
{
	for (int Out = 0; Out < Size - 1; Out ++)
	{
		int MinI = Out;

		for (int In = Out + 1; In < Size; In ++)
		{
			if (Array[In] > Array[MinI])
			{
				MinI = In;
			}
		}

		char Tmp = Array[Out];
		Array[Out] = Array[MinI];
		Array[MinI] = Tmp;
	}
}

void insertion(char Array[], int Size)
{
	for (int Out = 1; Out < Size; Out ++)
	{
		char Tmp = Array[Out];
		int In = Out;

		while (In > 0 && Array[In - 1] <= Tmp)
		{
			Array[In] = Array[In - 1];
			-- In;
		}

		Array[In] = Tmp;
	}
}
