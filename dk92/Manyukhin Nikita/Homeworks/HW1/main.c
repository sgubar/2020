#include <stdio.h>
#include "tools.h"

int main() {

    int OctalNumber = 0;

       printf("The minimum number is -9999, the maximum is 9999\nEnter the number to convert: ");

    do
    {
        scanf("%d", &OctalNumber);
        if (OctalNumber < -9999 || OctalNumber > 9999) printf("\n####ERROR####\n\nThe number does not meet the condition.\nEnter another: ");
    }while(OctalNumber < -9999 || OctalNumber > 9999);


    OctalConvert(OctalNumber);

    return 0;
}
