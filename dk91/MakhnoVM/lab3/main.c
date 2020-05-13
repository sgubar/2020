#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <time.h>



int main(int argc, char const *argv[])
{
	int size_f = size_file() - 1;
	char *n = (char*)malloc(size_f * sizeof(char));					//виділення пам'яті під масив та структуру
	arrayinfo* cp = fillingArr(n, size_f);

 

	clock_t start = clock();															//сортування та знаходження часу сортування
	quickSort(cp->array_s, 0, cp->length - 1);
	clock_t end = clock();
    printf ("quickSort = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);

	filePrintf(cp);				//виведення інформації у файл

	char* key = (char*)malloc(50 * sizeof(char));
	int i;
	for(i = 0; i < 50; i++)
	{
		scanf("%c", &key[i]);
		if((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'));
			else break;
	}
	char* new_key = (char*)malloc(i * sizeof(char));
	for(int j = 0; j < i; j++) new_key[j] = key[j];

	binarySearch(new_key, cp->array_s, 0, cp->length - 1);

	free(cp);
	free(n);			//звільнення пам'яті

	return 0;
}