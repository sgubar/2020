#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "tool.h"
////////////////////////////////////////////// Створення списку   /////////////////////////////////////////////////////////
List *init(char val)
{
	List *p_begin = (List *)malloc(sizeof(List));                // Створення першого елемента списку
	p_begin->field = val;
	p_begin->next = NULL;
	p_begin->prev = NULL;
	return p_begin;
}
List* addElement(List *list, char val)                              // Додавання елементів до списку
{
  List *temp, *p;
  temp = (List*)malloc(sizeof(List));
  p = list->next;
  list->next = temp;
  temp->field = val;
  temp->next = p;
  temp->prev = list;
  return temp;
}

List* scanElem()                          // Створення списку
{
  char val;
  scanf("%c", &val);
  List* p_begin = init(val);
  List* temp = p_begin;
  while(val != '\n')
  {
    scanf("%c", &val);
    if(val == '\n')break;
    temp = addElement(temp, val);
  }
  return p_begin;
}

////////////////////////////////// Вивід списку на єкран //////////////////////////

void listPrint(List* p_begin)                     // Вивід списку на єкран
{
  List* p = p_begin;                        
  while(p != NULL){
    printf("%c\t", p->field);
    p = p->next;

  }
}

//////////////////////////////// Зміна позицій елементів списку  ///////////////////////////////////

void check(List* p, char element)
{
  int i = 0;
  List* left;
  List* right;                        
  while(p->next != NULL){
     
    if(p->field == element){
      i++;
      if(i == 1) left = p->next;
      } 
    p = p->next; 
  }
  if(p->field == element)i++;
  if(i < 2)error();
  else {

    while(p->field != element){
      p = p->prev;
    } 
    right = p->prev;
    swapElements(right, left);
  }
}


void swapElements(List* right, List* left)
{
    char c = right->field;
    right->field = left->field;
    left->field = c;
    left = left->next;
    right = right->prev;
    if(left->prev == right || left == right)return ;
    swapElements(right, left);
}

/////////////////////////// помилка "Ти дурень" ////////////////////////////////

void error()
{
  printf("\n Are you a fool?\n");
}