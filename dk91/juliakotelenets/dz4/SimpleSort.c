#include "dk_tool_array.h"
#include "SimpleSort.h"


void bubbleSort(EllipseArray *anArray)
{
	for (int theOut = anArray->count - 1; theOut >= 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (SquareEllipse(anArray->ellipses[theIn]) > SquareEllipse(anArray->ellipses[theIn + 1]))
			{
			    Ellipse *theTmp = anArray->ellipses[theIn];
				anArray->ellipses[theIn] = anArray->ellipses[theIn + 1];
				anArray->ellipses[theIn + 1] = theTmp;
			}
		}
	}
}
