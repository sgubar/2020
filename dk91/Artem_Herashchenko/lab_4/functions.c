#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "hhh.h"

List *init(int val)                               //первый элемент
{
  List *list = (List *)malloc(sizeof(List));
  list->field = val;
  list->next = NULL;
  return list;
}
List* addelem(List *list, int val)               //добавляем следующие элементы
{
  struct list *temp, *p;
  temp = (List*)malloc(sizeof(List));
  p = list->next;
  list->next = temp;
  temp->field = val;
  temp->next = p;
  return temp;
}


List *load_from_file(char *path)               //сканируем и записуем данные с файла
{
  int c;
  FILE *fi;
  fi = fopen("input.txt", "rt");

  fscanf(fi, "%d", &c);
  List *list = init(c);
  List* temp = list;
  while(!feof(fi))
  {
    fscanf(fi, "%d", &c);
    if (c == EOF)break;
    temp = addelem(temp, c);
  }
    fclose(fi);
    return list;
}

void printList(List* list, int a, int b)           //выводим список
{
  List* p = list;
  printf("men`she a : ");
  while(p != NULL ){
    if(p->field < a){
      printf("%d\t", p->field);
    }
      p = p->next;
  }
  p = list;
  printf("\n");
  printf("v predelah a i b : ");
  while(p != NULL ){
    if(p->field >= a && p->field <= b){
      printf("%d\t", p->field);
    }
      p = p->next;
  }
  p = list;
  printf("\n");
  printf("bol`she b : ");
  while(p != NULL ){
    if(p->field > b){
      printf("%d\t", p->field);
    }
      p = p->next;
  }
}

