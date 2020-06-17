#include <stdio.h>
#include "fff.h"

List *init(char val)
{
	List *list = (List *)malloc(sizeof(List));
	list->field = val;
	list->next = NULL;
	list->prev = NULL;
	return list;
}
void addelem(List *list, char val)
{
  struct list *temp, *p;
  temp = (struct List*)malloc(sizeof(List));
  p = list->next;
  list->next = temp;
  temp->field = val;
  temp->next = p;
  temp->prev = list;
  if (p != NULL)
    p->prev = temp;
  //return(temp);
}

void listprintr(List *list)
{
  struct list *p;
  p = list;
  while (p->next != NULL)
    p = p->next;
  do {
    printf("%c ", p->field);
    p = p->prev;
  } while (p != NULL);
}
void listprint(List *list)
{
  List *p;
  p = list;
  do {
    printf("%c ", p->field);
    p = p->next;
  } while (p != NULL);
}

List *load_from_file(char *path)
{
    FILE *file = fopen(path, "r");

    char c = fgetc(file);

    List *list = init(c);
    while (c != EOF)
    {
        c = fgetc(file);
        if (c == EOF)
            break;
        if (isalpha(c))
            addelem(list, c);
    }
    return list;
}
void obch(List *list)
{
    char element;
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;
    List *P;
    P = list;
     while (P->next != NULL)
   P = P->next;

    do
    {
       element = P->field;
       switch (element)
       {
           case 'a': a++;break;
           case 'b': b++;break;
           case 'c': c++;break;
           case 'd': d++;break;
           case 'e': e++;break;
           case 'f': f++;break;
           case 'g': g++;break;
           case 'h': h++;break;
           case 'i': i++;break;
           case 'j': j++;break;
           case 'k': k++;break;
           case 'l': l++;break;
           case 'm': m++;break;
           case 'n': n++;break;
           case 'o': o++;break;
           case 'p': p++;break;
           case 'q': q++;break;
           case 'r': r++;break;
           case 's': s++;break;
           case 't': t++;break;
           case 'u': u++;break;
           case 'v': v++;break;
           case 'w': w++;break;
           case 'x': x++;break;
           case 'y': y++;break;
           case 'z': z++;break;
           case 'A': a++;break;
           case 'B': b++;break;
           case 'C': c++;break;
           case 'D': d++;break;
           case 'E': e++;break;
           case 'F': f++;break;
           case 'G': g++;break;
           case 'H': h++;break;
           case 'I': i++;break;
           case 'J': j++;break;
           case 'K': k++;break;
           case 'L': l++;break;
           case 'M': m++;break;
           case 'N': n++;break;
           case 'O': o++;break;
           case 'P': p++;break;
           case 'Q': q++;break;
           case 'R': r++;break;
           case 'S': s++;break;
           case 'T': t++;break;
           case 'U': u++;break;
           case 'V': v++;break;
           case 'W': w++;break;
           case 'X': x++;break;
           case 'Y': y++;break;
           case 'Z': z++;break;
       }
       //printf("a: %d\nb: %d\nc: %d\nd: %d\ne: %d\nf: %d\ng: %d\nh: %d\ni: %d\nj: %d\nk: %d\nl: %d\nm: %d\nn: %d\no: %d\np: %d\nq: %d\nr: %d\ns: %d\nt: %d\nu: %d\nv: %d\nw: %d\nx: %d\ny: %d\nz: %d\n",a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z );
       P = P->prev;
    } while(P->prev!=NULL);
printf("a: %d\nb: %d\nc: %d\nd: %d\ne: %d\nf: %d\ng: %d\nh: %d\ni: %d\nj: %d\nk: %d\nl: %d\nm: %d\nn: %d\no: %d\np: %d\nq: %d\nr: %d\ns: %d\nt: %d\nu: %d\nv: %d\nw: %d\nx: %d\ny: %d\nz: %d\n",a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z );
}
