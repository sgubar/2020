//
//  tools.c
//  Homework 2
//
//  Created by Nazar Diadiun on 25.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//
#include "tools.h"

//Создание треугольника
RightTriangle *createRightTriangle(Point *A, Point *B, Point *C)
{
    RightTriangle *theResult = NULL;

    if(A != NULL && B != NULL && C != NULL) //Если точки не пустые
    {
     if(abs(A->y) == abs(C->y) && abs(C->x) == abs(B->x)) //Проверяем по условию прямоугольности
        {
            theResult = (RightTriangle* )malloc(sizeof(RightTriangle)); //Выделяем память

            if(theResult != NULL) //Если выделили
            {//Забиваем точки
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
            }
        }
         else
        printf("The triangle is not rectangular!\n");

    }
    return theResult; //Возвращаем треугольник
}

//Функция площади
int AreaOfRightTriangle(RightTriangle *aTriangle)
{
    int theResult = 0; //переменная для результата

    if(aTriangle != NULL) //Если получили не пустой треугольник
    {
        //Находим длинну первой и второй стороны
        int FirstSide = (float)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        int SecondSide = (float)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));

        //И высчитываем площадь
        theResult = (FirstSide * SecondSide) / 2;
    }

    return theResult; //Возвращаем её
}

//Выводим точки треугольнка
void PrintRightTriangle(RightTriangle *aTriangle)
{
    if (NULL != aTriangle) //Если получили не пустой треугольник
    {
        printf ("Coordinates of vertices:\nA(%d,%d)\nB(%d,%d)\nC(%d,%d)\n\n",
                    aTriangle->A->x, aTriangle->A->y, aTriangle->B->x, aTriangle->B->y,aTriangle->C->x, aTriangle->C->y); //Просто выводим в консоль координаты
    }
}

//Разрушение
void destroyRightTriangle(RightTriangle *aTriangle)
{
    if(aTriangle != NULL) //Если получили не пустой треугольник
    {
        //Высвобождаем каждую точку, но у меня не получается, ибо выпадает в ошибку
        //free(aTriangle->A);
        //free(aTriangle->B);
        //free(aTriangle->C);
        free(aTriangle); //И высвобождаем память всего треугольника
    }
}
