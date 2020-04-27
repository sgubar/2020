#include <stdio.h>
#include <stdlib.h>
#include "Laba4.h"

int main()
{   int kol=0;
    printf("Vvedi kolvo elementov\n");
    scanf("%i", &kol);
    int rendom;
    printf("Vvedi chislo\n");
    scanf("%i", &rendom);
    el *n=(struct el*)malloc(sizeof(el)*kol);
    rendomm(n,kol,rendom);
    kol=loneinost(n,kol);
    vovod(n,kol);
    printf("Zakonchil");
    return 0;
}
