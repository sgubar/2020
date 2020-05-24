
#include <stdio.h>
#include "func.h"

int main(int argc, const char * argv[])
{
    long LenghtOfArray = 0; 
    char* ReadedArray; 
    InputFileLenght(&LenghtOfArray); 
    
    ReadedArray = ReadFromFileToArray(LenghtOfArray); 
    
    SortingFuntion(ReadedArray, LenghtOfArray); 
    
    return 0; 
}

