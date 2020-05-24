//
//  main.c
//  Laboratory Work 4
//
//  Created by Nazar Diadiun on 22.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include "func.h"

int main(int argc, const char * argv[]) {
    Node* list = NULL; //Создали список
    
    int amount = 0;
    int DatatoWrite = 0;
    
    printf("Сколько ячеек будет введено: ");
    scanf("%d", &amount);
    
    for (int i = 0; i < amount; ++i) {
        printf("Введите значение для %d ячейки: ", i);
        scanf("%d/n", &DatatoWrite);
        FillWithData(&list, DatatoWrite);
    }
    
    for (int i = 0; i < 2; i++){
    Straight(list);
        putchar('\n');
        
    Reverse(list);
        putchar('\n');
    }
    return 0;
}
