//
//  main.c
//  Homework 2
//
//  Created by Nazar Diadiun on 25.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include "tools.h"

int main()
{

    //объявляем точки треугольника
    Point A = {4,9};
    Point B = {3,5};
    Point C = {3,9};

    //Вызываем функцию создания треуголька с указанными точками
    RightTriangle *ABC = createRightTriangle(&A, &B, &C);

    //Если треугольник не создался
    if (ABC == NULL)
        printf("Ошибка!\n");
    else //Если всё ок
    {
        PrintRightTriangle(ABC); //Принт точек треугольника функцией
        printf("S(ABC) = %.2f\n", (float)AreaOfRightTriangle(ABC)); //И площадь треугольника
    }

    destroyRightTriangle(ABC); //В конце разрушаем треугольник
}
