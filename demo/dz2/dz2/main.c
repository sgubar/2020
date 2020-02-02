//
//  main.c
//  dz2
//
//  Created by Slava Gubar on 2/15/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "dk_line.h"

int main(int argc, const char * argv[])
{
	Point A = {2,3};
	Point B = {4,6};
	
	Line *AB = createLine(&A, &B);
	Line *CD = createLineWithCoordinate(0, 1, 2, 3);

	printLine(AB);
	printLine(CD);
	
	CD->A->y = 34;
	printLine(CD);

	A.x = 10;
	printLine(AB);
	
	AB->A->x = 11;
	printLine(AB);

	printf("The length of Line AB = %f\n", lenghLine(AB));
	
	// insert code here...
	printf("Hello, World!\n");

	destroyLine(AB);
	return 0;
}
