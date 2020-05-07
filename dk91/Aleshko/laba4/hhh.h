#ifndef HHH_H_INCLUDED
#define HHH_H_INCLUDED

typedef struct list
{
    char field;
    struct list *next;
    struct list *prev;
} List;

List *init(char val);
List *load_from_file(char *path);
void addelem(List *list, char val);
void listprint(List *list);
void listprintr(List *list);

#endif  //HHH_H_INCLUDED
