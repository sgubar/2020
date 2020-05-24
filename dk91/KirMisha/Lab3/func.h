
#ifndef func_h
#define func_h

#define INPUT "/LaboratoryWork3/Input.txt"
#define OUTPUT "/LaboratoryWork3/Output.txt"

#include <stdio.h>
#include <stdlib.h>

void InputFileLenght(long* SizeOfArray); 
char* ReadFromFileToArray(long ArraySize); 
void SortingFuntion(char* InputArray, long SizeOfArray); 
void SearchSymbolInArray(char* SortedArray, long SizeOfArray); 
void WriteToFile (char* InputArray); 

#endif /* func_h */
