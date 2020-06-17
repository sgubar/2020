#ifndef FFF_H_INCLUDED
#define FFF_H_INCLUDED

typedef struct list
{
    char field;
    struct list *next;
    struct list *prev;
} List;
void obch(List *list);
List *init(char val);
List *load_from_file(char *path);
void addelem(List *list, char val);
void listprint(List *list);
void listprintr(List *list);

#endif // FFF_H_INCLUDED
