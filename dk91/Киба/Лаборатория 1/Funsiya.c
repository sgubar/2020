#include <stdio.h>
#include <stdlib.h>
//A*2+B*2*B+5^C+B!


int sum_1( int A, int B )// это просто сложение двух чисел
{

	return 2*A + B*2*B;
}

int factorial (int n)//тут высчитываеться факториал через тернарный опиратор
{

  return (n < 2) ? 1 : n * factorial (n - 1);
}

int pew(int C, int x ) {

	if(C == 0) return 1;
   else if(C < 0) return pew ( 1.0 / x, C);
    return x * pew(x, C - 1);
 }

 int sum_2(int pew, int factorial)// тут происходит сложение числа и факториала
{

	return pew + factorial;
}

int sum_f(int sum_1, int sum_2)
{

    return sum_1 + sum_2;
}

int sum (int A,int B, int C){

    return ((A*2+B*2)/(B+pew(5,C)))+factorial(B)-4;
}




