#include "pilha.h"

Pilha *pilha_cria(void){
    NoLista *queueNode;
    criarLista(&queueNode);
    printf("\n\nA pilha foi criada com sucesso!");
    return queueNode;
} 

void pilha_push(Pilha *p, float v){
    p->topo = inserirInicio(&(p->topo), v);
    printf("\n\nO valor %.2f foi inserido na pilha.", v);
} 

float pilha_pop(Pilha *p){
    if (!pilha_vazia(p)) {
        float info = removerInicio(&(p->topo));
        printf("\n\nO valor %.2f foi removido da pilha.", info);
        return info;
    } else printf("\n\nA pilha se encontra vazia.");
} 

int pilha_vazia(Pilha *p){
    return (listaVazia(p));
}

void pilha_libera(Pilha *p){
    if (!pilha_vazia(p->topo)) {
        while (!pilha_vazia(p->topo)) {
            removerInicio(&(p->topo));
        }
        printf("\n\nA pilha foi liberada.");
    } else printf("\n\nA pilha já se encontra vazia.");
}

void pilha_imprime(Pilha *p){
    printf("\n\n\t\t\tPilha - dados\n");
    imprimirLista(p->topo);
}