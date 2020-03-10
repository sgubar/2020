#include <stdio.h>
#include "tool.h"
 
int main()
{
    printf("vvedite a\n");
    int a;
    scanf("%i", &a);
     
    printf("vvedite b\n");
    int b;
    scanf("%i", &b);

    printf("vvedite c\n");
    int c;
    scanf("%i", &c);

    int result;
    result = formula(a, b, c);
    printf ("result = %i\n", result);
    
    return 0;
}
