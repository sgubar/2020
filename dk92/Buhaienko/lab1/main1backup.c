#include <stdio.h>
#include <stdlib.h>


int factor(int x)
{
int fact = 1;

        for(int i=1; i<=x; i++)
        {
            fact *= i;

        }
 return fact;
}


int sigma(int c, int in)
{
    int out = NULL;

    for(int d = 0; d<c; d++)
    {
        out = out + in;

    }

return out;
}

float root(int v)
{
    float start = 0;
    float endv = ((float)v)/2;
    float ans = 0;
    if (v == 0 || v == 1)
    {
        ans = v;
    }
else{

while(start <= endv)
{
float mid = (start + endv)/2;
int kune =(int)(mid*mid);
    if(kune == v)
    {
        ans = mid;
    }
        else if(kune < v)
        {
            start = mid + 0.1;
        }
            else
            {
                endv = mid - 0.1;
            }

}
}
return ans;
}



int main()
{
    int b;
    int d;
    float g;
    g = root(25);
    d = factor(6);
    b = sigma(4, 2);

    printf("result: %i, %i, %f", b, d, g);
    return 0;
}
