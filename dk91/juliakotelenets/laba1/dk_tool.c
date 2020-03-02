//  lab1
//
//  Created by Kotelenets Julia on 02/03/20.
#include "dk_tool.h"
#include "stdio.h"

void Factorial(int A, int *factorial) //занесення факторіалу в змінну А
{
    *factorial = 1;

    for(int i = 2; i <= A; i++)
    {
        *factorial *= i;
    }
    printf("factorial: %i\n", *factorial);

}

void Modul(int A, int B, int *ModuledZnamenatel, int *Znamenatel)  //ф-ції знаменник та модуль знаменника
{

    *Znamenatel = 2 * A + B; 

    if(*Znamenatel == 0)       
    {
        printf("Error:Znamenatel=0\n");
    }
    else                      
    {
        printf("Znamenatel:%i\n", *Znamenatel);
    }

    if(0>*Znamenatel)   
    {
        *ModuledZnamenatel = *Znamenatel * (-1);
    }
    else if(0 <*Znamenatel)   
    {
        *ModuledZnamenatel = *Znamenatel;
    }

    if(*Znamenatel == 0)     
    {
        printf("restart and enter another values\n");
    }
    else          
    {
        printf("Modul Znamenatel:%i\n", *ModuledZnamenatel);
    }
}

void Result(int factorial, int *Znamenatel, int *ModuledZnamenatel, float *result) //функція результату
{

    if(*Znamenatel != 0)  //якщо не дорівнює нулю, то вираховуємо за заданою математичною формулою
    {
        *result = (float)factorial / *ModuledZnamenatel;
        printf("your result is %.3f\n", *result);
    }
    else    //інакше помилка
        printf("Znamenatel = 0, error");
}
