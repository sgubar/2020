#include <stdio.h>
#include <stdlib.h>

#include "Silka.h"// я ссылаюсь на файл

int main(int argc, char * argv[]) { //начало програмы
  int A, B, C, Q;
  printf("((A*2+B*2)/(B+5^C))+B!\nEnter the numbers in the following order: A, B, C\nOnly numbers greater than zero are entered\n");
  goback: // это обозначеный момент к которому функция goto будет возвращаться

    while (scanf("%d %d %d", & A, & B, & C) == 0) { // эта цикл проверяет не буква ли введеное число и прописую значение всех интовых значений
      printf("Only numbers greater than zero are entered\n");
      fflush(stdin); // функция сбрасывает значение прописаные нами и переводит нас на прошлый шаг
    }
  if (A <= 0 || B <= 0 || C <= 0) { // прописываю проверку при которой все значения должны быть больше 0
    goto goback; // функция что обрывает цикл и кидвет нас в момент goback
  } else {


    Q = sum (A, B , C);

    printf("((%d*2+%d*2)/(%d+5^%d))+%d!=%d", A, B, B, C, B, Q);
  }
  return 1;
}


