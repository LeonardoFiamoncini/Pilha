#ifndef _lista_h
#define _lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct noLista {
    float info;
    struct noLista *prox;
} NoLista;

int listaVazia (NoLista *l);
void criarLista (NoLista **l);
NoLista *inserirInicio (NoLista **l, float d);
float removerInicio (NoLista **l);
void imprimirLista (NoLista *l);

#endif