#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
	int *a, b;//b-size of arr, a-array
	printf("Enter size of array:");
	scanf("%i\n", &b);
	a = (int*)malloc(b * sizeof(int));

	for (int i = 0; i < b; i++)
		scanf("%d", &a[i]);

	a = reversal(a, b);
	printf("reverse\n");
	for (int i = 0; i < b; i++)
		printf("%d\n", a[i]);

	return 0;
}
