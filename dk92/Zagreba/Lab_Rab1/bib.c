#include "bib.h"






float stp  (float D)
{
return D*D;
}


float stp5 (float C)
{ float S=1;
    float ZZ=0;
    if(C<0){ ZZ=-C;
    }else{ZZ=C;}
    for(int i=0; i<ZZ; i++)
    {
        S=S*5;
    }

    if(C<0)S=1/S;


return S;
}

float integral (float B)
{

        float a=1;
        float z=1;

        for(int i=1; i<=B; i++)
            {
                a=z*i;
                z=a;
            }
        return a;

}

