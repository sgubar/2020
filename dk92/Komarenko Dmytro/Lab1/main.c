#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    int a,b;
    start:
    printf("Hello!\nThis is laboratory work #1 fulfilling the condition of option 7:\n\n\tQ=A!/|2*A+B|\n\nWarning!\nActions are performed with integers.\n");
    a = valid (0,'A',10);
    b = valid (-100000000,'B',100000000);
    if(0==sum(multiplication(2,a),b))
    {
        printf("Invalid value - division by zero 0.\nGo to the beginning of the program ...\n\n");
        goto start;
    }
    printf("A=%d, B=%d\nQ=%f\n", a, b, q(a,b));
    return 0;
}
