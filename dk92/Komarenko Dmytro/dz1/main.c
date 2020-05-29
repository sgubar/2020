//Функція виконує перестановку 0 з n-1, 1 з n-2 …. елементів масиву

#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    system("chcp 1251");
    system("cls");
	int *a, b;//b-size of arr, a-array
	printf("Введіть розмір масиву:");
	scanf("%i\n", &b);
	a = (int*)malloc(b * sizeof(int));
//вставлення елементів у оголошений масив
    int i;
	for (i = 0; i < b; i++)
		scanf("%d", &a[i]);

	a = reversal(a, b);    //присвоюємо масиву значення реверсу
	printf("Зворотній порядок:\n");
	for (i = 0; i < b; i++) //друк зворотного масиву на консольний вихід
		printf("%d\n", a[i]);

	return 0;
}
