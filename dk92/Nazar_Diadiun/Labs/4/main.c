//
//  main.c
//  Laboratory Work 4
//
//  Created by Nazar Diadiun on 22.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include "Functions.h"

int main(int argc, const char * argv[]) {
    
    int i;
    Node* list = NULL; //начало списка, указатель ссылается на нуль
    
    for (i = 0; i < 10; ++i) {
        EnterData(&list, i + 1);
    }
    
    for (int i = 0; i < 2; i++){
    printFromHead(list); putchar('\n');
    printFromTail(list); putchar('\n');
    }
    return 0;
}
