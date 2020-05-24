#include "func.h"

void FillWithData(Node** list, const Data data) {
    Node* node = malloc(sizeof(Node)); //Выделение памяти
    node->data = data; //Заносим данные в ячейку
    node->next = *list; //Этой ячейке даём предыдущий адрес
    *list = node; //А новая ячейка потом получит следующий адрес
}
void Straight(const Node* list) { //Функция вывода в прямом порядке
    if (list) {
        printf("%d ", list->data);
        Straight(list->next);
    }
}
void Reverse(const Node* list) { //Функция вывода в обратном порядке
    if (list) {
        Reverse(list->next);
        printf("%d ", list->data);
    }
}
