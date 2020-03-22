#include <stdio.h>
#include <stdlib.h>

int Validate(float A, float B, float C)
{
if(A<=0)
{
    return -1;
}
    else
    {

        if(B == 0)
        {
        return -2;
        }
            else
            {

                if(C <= 0 || (B+C)<= 0 || C > 3)
                {
                return -3;
                }
                else
                    {
                return 0;
                    }
            }
    }

}

