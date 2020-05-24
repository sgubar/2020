
#ifndef func_h
#define func_h

#define INPUT "/LaboratoryWork3/Input.txt"
#define OUTPUT "/LaboratoryWork3/Output.txt"

#include <stdio.h>
#include <stdlib.h>

void InputFileLenght(long* SizeOfArray); //Функция считывания кол-ва символов в файле
char* ReadFromFileToArray(long ArraySize); //Функция считывания данных в массив
void SortingFuntion(char* InputArray, long SizeOfArray); //Сортировка методом Шелла
void SearchSymbolInArray(char* SortedArray, long SizeOfArray); //Функция бинарного поиска
void WriteToFile (char* InputArray); //Запись в файл

#endif /* func_h */
