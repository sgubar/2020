//
// Created by anton on 10.02.2020.
//

#include "dk_tool.h"

int dk_factorial(int num)
{
    if (num < 1)
    {
        return -1;
    }
    else
    {
        int rezult = 1;
        int current_num = 1;
        while (current_num <=  num)
        {
            rezult *= current_num;
            current_num++;
        }

        return rezult;
    }
}

double dk_pow(double num, double num_pow)
{
    if (num_pow == 0)
    {
        return 1;
    }
    else if (num_pow < 0)
    {
        num_pow *= -1;
        int const_num = num;
        for (int i = 1; i < num_pow; i++)
        {
            num *= const_num;
        }

        return 1 / num;
    }
    else if (num_pow > 0)
    {
        int const_num = num;
        for (int i = 1; i < num_pow; i++)
        {
            num *= const_num;
        }

        return num;
    }
}

double dk_sum(double num1, double num2)
{
    return num1 + num2;
}

double dk_div(double num1, double num2)
{
    if (num2 == 0)
    {
        printf("ERROR in dk_div()! YOUR double num2 = 0");
        return -1;
    }
    else
    {
        return num1 / num2;
    }
}

