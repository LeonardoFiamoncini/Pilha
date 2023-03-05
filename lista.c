#include "lista.h"

int listaVazia (NoLista *l) {
    return (l == NULL);
}

void criarLista (NoLista **l) {
    *l = NULL;
}

NoLista *inserirInicio (NoLista **l, float d) {
    NoLista *bloco = (NoLista *)malloc(sizeof(NoLista));
    bloco->info = d;
    bloco->prox = *l;
    *l = bloco;
    return (*l);
}

float removerInicio (NoLista **l) {
    if (!listaVazia(*l)) {
       float info = (*l)->info;
       NoLista *atual = *l;
       *l = (*l)->prox;
       free(atual);
       return info;
    }
}

void imprimirLista (NoLista *l) {
    if (!listaVazia(l)) {
        NoLista *atual = l;
        while (atual != NULL) {
            printf ("\t%.2f", atual->info);
            atual = atual->prox;
        }
    } else printf("\t\t\t(Nenhum dado)\n");
}
