#include <stdio.h>
#include "bib.h"

void criaLista(Lista *l){
    (*l) = NULL;
}

void insereFim(Lista *l, int n){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->info = n;
    novo->prox = NULL;

    if((*l) == NULL){ // lista vazia
        (*l) = novo;
    }
    else{

        Nodo *aux = (*l);
        while(aux != NULL)
            aux = aux->prox;
        aux->prox = novo;

    }

}

void copia(Lista *l_Origem, Lista *l_Copia){
    Nodo *atual = (*l_Origem);
    criaLista(l_Copia);
    while(atual != NULL){
        insereFim(l_copia, atual->info);
        atual = atual->prox;
    }
}
