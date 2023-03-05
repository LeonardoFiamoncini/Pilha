#include "pilha.h"

Pilha *pilha_cria(void){
    NoLista *queueNode;
    criarLista(&queueNode);
    return queueNode;
} 

void pilha_push(Pilha *p, float v){
    p->topo = inserirInicio(&(p->topo), v);
} 

float pilha_pop(Pilha *p){
    if (!pilha_vazia(p)) {
        float info = removerInicio(&(p->topo));
        return info;
    } 
} 

int pilha_vazia(Pilha *p){
    return (listaVazia(p));
}

void pilha_libera(Pilha *p){
    if (!pilha_vazia(p->topo)) {
        while (!pilha_vazia(p->topo)) {
            removerInicio(&(p->topo));
        }
    } 
}

void pilha_imprime(Pilha *p){
    imprimirLista(p->topo);
}