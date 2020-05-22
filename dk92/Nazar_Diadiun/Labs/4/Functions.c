//
//  Functions.c
//  Laboratory Work 4
//
//  Created by Nazar Diadiun on 22.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include "Functions.h"

void EnterData(Node** list, const Data data) {
    Node* node = malloc(sizeof(Node)); //выделяем память
    node->data = data; //присваиваем значение
    node->next = *list; //присваиваем указателю адрес предыдущего узла
    *list = node; //ну и присваиваем указателю головы следующий узел
}
void printFromHead(const Node* list) {
    if (list) {
        printf("%d ", list->data);
        printFromHead(list->next);
    }
}
void printFromTail(const Node* list) {
    if (list) {
        printFromTail(list->next);
        printf("%d ", list->data);
    }
}
