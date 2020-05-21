#ifndef DEREVO_H_INCLUDED
#define DEREVO_H_INCLUDED

typedef struct derevo{

    int nomer;
    float inform;
    struct derevo* son1;
    struct derevo* son2;
}derevo, *Dderevo;

derevo* sosdat(int nomer);

int vstavka(struct derevo *father, struct derevo *sun);

int obhod(struct derevo *father, int namber);

int obhod2(struct derevo *father, int namber);

#endif // DEREVO_H_INCLUDED
