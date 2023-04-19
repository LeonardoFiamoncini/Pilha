#ifndef _lista_h
#define _lista_h

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
* \author Leonardo de Souza Fiamoncini
* \since 19/04/2023
* \brief Struct representing a data structure known as linked list 
**/
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