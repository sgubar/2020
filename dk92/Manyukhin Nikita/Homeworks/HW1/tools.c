#include "tools.h"
#include <math.h>

void OctalConvert(int OctalInput)
{
    int decimal = 0, i = 0;

    printf("Number %d converted to decimal: ", OctalInput);
       while (OctalInput != 0)
       {
           decimal =  decimal + (OctalInput % 10)* pow(8, i++);
           OctalInput = OctalInput / 10;
       }
           printf("%d", decimal);

    printf("\n");

}
