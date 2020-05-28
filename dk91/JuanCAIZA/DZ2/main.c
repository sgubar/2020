#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char const *argv[])
{
	Point* A = (Point*)malloc(sizeof(Point));
	Point* B = (Point*)malloc(sizeof(Point));
	printf("point A : x = ");
	scanf("%d", &A->x);
	printf("point A : y = ");
	scanf("%d", &A->y);
	printf("point B : x = ");
	scanf("%d", &B->x);
	printf("point B : y = ");
	scanf("%d", &B->y);
	Line* ab = (Line*)malloc(sizeof(Line));
	ab->A = A;
	ab->B = B;
	if(check( ab) == -1){
		printf("beda!!!!\n");
		Free(ab);
		return -1;
	} 
	area(ab);
	Free(ab);
	return 0;
}
