
#include <stdio.h>
#include "func.h"

int main(int argc, const char * argv[])
{
    long LenghtOfArray = 0; //Переменная хранит кол-во символов в входящем файле
    char* ReadedArray; //Переменная хранит данные, считанные из файла
    InputFileLenght(&LenghtOfArray); //Узнаем кол-ва символов
    
    ReadedArray = ReadFromFileToArray(LenghtOfArray); //А считанный массив получаем из функции, указав кол-во символов (чтобы правильно выделить память)
    
    SortingFuntion(ReadedArray, LenghtOfArray); //В конце сортируем массив
    
    return 0; //Конец
}

