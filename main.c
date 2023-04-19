#include <stdio.h>
#include "pilha.c"

/**
*\author Leonardo Fiamoncini
**/
int main(void){
    setlocale(LC_ALL, "English");

    Pilha *pilha = pilha_cria();
    pilha_push(&pilha, 10.0f);
    pilha_push(&pilha, 20.0f);
    pilha_push(&pilha, 30.0f);
    pilha_pop(&pilha);
    pilha_push(&pilha, 60.0f);
    pilha_push(&pilha, 90.0f);
    pilha_pop(&pilha);
    pilha_pop(&pilha);
    pilha_push(&pilha, 100.0f);
    pilha_pop(&pilha);
    pilha_imprime(&pilha);
    pilha_push(&pilha, 100.0f);
    pilha_imprime(&pilha);
    pilha_libera(&pilha);
    pilha_imprime(&pilha);
    pilha_libera(&pilha);
    pilha_imprime(&pilha);
}