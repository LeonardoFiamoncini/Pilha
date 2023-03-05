#ifndef _pilha_h
#define _pilha_h

#include "lista.c"

typedef struct pilha {
    NoLista *topo;
} Pilha;

Pilha *pilha_cria(void);
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);

#endif