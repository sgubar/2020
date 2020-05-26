#include <stdio.h>
#include "fun.h"

int main(int argc, const char * argv[]) {
    Node* list = NULL;

    int a = 0;
    int b = 0;

    printf("Scolko yacheek ");
    scanf("%d", &a);

    for (int i = 0; i < a; ++i) {
        printf("Znachenie yacheyki %d: ", i);
        scanf("%d/n", &b);
        FillWithData(&list, b);
    }
    for (int i = 0; i < 2; i++){
    Straight(list);
        putchar('\n');

    Reverse(list);
        putchar('\n');
    }
    return 0;
}
