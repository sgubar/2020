#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tool.h"
void area(Line* line)
{
	printf("%d",abs((line->A->x - line->B->x) * (line->A->y - line->B->y)));
}

int check(Line* line)
{
	if(line->A->x == line->B->x || line->A->y == line->B->y)return -1;
	return 0;
}

void Free(Line* line)
{
	free(line->A);
	free(line->B);
	free(line);
}