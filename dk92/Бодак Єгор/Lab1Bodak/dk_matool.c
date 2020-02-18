#include "dk_matool.h"

double modNum(float num)
{
    if (num < 0)
    {
        return -1*num;
    }
    else
    {
        return num;
    }
}

double powNum(float num, float pow_num)
{
    if (pow_num == 0)
    {
        return 1;
    }
    else
    {
        float multiply_num = num;
        for (int i = 1; i < modNum(pow_num); i++)
        {
            num *= multiply_num;
        }
        if (pow_num < 0)
        {
            return 1 / num;
        }
        else
        {
            return num;
        }
    }
}

double algSum(int border)
{
    long int sum_rezult = 0;

    for (int D = 0; D <= modNum(border); D++)
    {
        sum_rezult += powNum(2, D);
    }

    return sum_rezult;
}
