#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char const *argv[])
{
	int size_array;
	int k;
	printf("vvedi k-vo elementov : ");
	scanf("%d", &size_array);

	ArrayInfo* anArray=  createArr(size_array);

	printf("skol`ko elementov ti hochesh dobavit`?\n");
	scanf("%d", &k);
	while(k != 0){
		anArray->size_array += 1;
		addRect(anArray);
		k--;
	}

	//arraySort(anArray);

	quickSort(anArray->arr, 0, anArray->size_array - 1);

	printf("vvedi key po area : ");
	int key;
	scanf("%d", &k);

	binarySearch(key, anArray->arr, 0, anArray->size_array - 1);
	
	FILE *aFile = fopen("test.json", "w");

	writeArrayToJSON(aFile, anArray);
	Free(anArray);
	
	return 0;
}	