#include <stdbool.h>

// узел списка
typedef struct node node;
struct node {
  char value;
  node* prev;
  node* next;
};

// функция создания и инициализации нового узла
node* newnode(char value);

// функция добавления нового значения в список
node* listadd(node* s, char value);

// функция вывода списка
void listprint(node* s);

// функция ввода списка с файла
node* read_list_from_file(const char* filename);

// функция проверки является ли этот список палиндромом
bool ispalindrome(node* leftmost);

