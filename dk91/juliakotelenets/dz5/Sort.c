#include <stdio.h>
#include <stdlib.h>
#include "dk_tool_array.h"
#include "dk_tool.h"
#include "Sort.h"

void sort_shell(EllipseArray *anArray)
{
	if (NULL == anArray)
	{
		return ;
	}

	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

	//1. Calculate start value of h
	while (theH <= anArray->count/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < anArray->count; theOuter ++)
		{
			Ellipse *theTmp = anArray->ellipses[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && SquareEllipse(anArray->ellipses[theInner - theH]) >= SquareEllipse(theTmp))
			{
				anArray->ellipses[theInner] = anArray->ellipses[theInner - theH];
				theInner -= theH;
			}

			anArray->ellipses[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
}

void lineSearch(EllipseArray* anArray,int square)
{
	int a = 0;
	int coordinata = 0;
	for(int i=0;i<anArray->count;i++)
		if ((int)(SquareEllipse(anArray->ellipses[i])) == square)
		{
			coordinata = i;
			a = 1;
		}
	if (a)
		printf("\n element is exist [%d]\n", coordinata);

}
