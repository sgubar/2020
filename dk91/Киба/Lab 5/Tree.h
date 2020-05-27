#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "Tree.c"
typedef struct tree{

    int nomer;
    float inform;
    struct tree* son;
    struct tree* Spiert;
}tree, *Dderevo;

tree* creat();

int vstavka(struct tree *perent, struct tree *sun);

int NLR(struct tree *perent);

//int delete_el(struct tree *perent,int n);

int delete_ALL(struct tree *perent);
#endif // DEREVO_H_INCLUDED
