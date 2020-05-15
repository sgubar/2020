#ifndef HHH_H_INCLUDED
#define HHH_H_INCLUDED

typedef struct list              //саздаём структуру
{
    int field;
    struct list *next;
} List;

List *init(int val);            //создаём первый элемент
List *load_from_file(char *path);   //берём данные с файла
List* addelem(List *list, int val);  //добавляем элемент
void printList(List* list, int a, int b);    //вывод списка

#endif // HHH_H_INCLUDED

