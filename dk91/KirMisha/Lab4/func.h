#ifndef func_h
#define func_h

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
 
//Создание типа, для того, чтобы не вызывать постоянно одно и то же
typedef struct Node {
    Data data;
    struct Node* next;
}   Node;


void FillWithData(Node** list, const Data data); //Функция ввода данных в список
void Straight(const Node* list); //Вывод с головы
void Reverse(const Node* list); //Вывод с хвоста
#endif /* func_h */
