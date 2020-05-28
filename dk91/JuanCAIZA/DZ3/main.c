#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char const *argv[])
{
	int size_array;
	int k;
	printf("vvedi k-vo elementov : ");
	scanf("%d", &size_array);

	ArrayInfo* c =  createArr(size_array);

	printf("skol`ko elementov ti hochesh dobavit`?\n");
	scanf("%d", &k);
	while(k != 0){
		addRect(c);
		k--;
	}
	
	FILE *aFile = fopen("test.json", "w");

	writeArrayToJSON(aFile, c);
	//Free(c);
	
	return 0;
}	
