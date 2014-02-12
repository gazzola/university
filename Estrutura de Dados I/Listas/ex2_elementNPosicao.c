#include <stdio.h>
#include "bib.h"

int elementoNPosicao(Lista l, int n){
    int count = 1;
    Nodo *aux = l;

    while(aux != NULL){
        if(n == count)
            return aux->info;
        aux = aux->prox;
        count++;
    }

    return -1;
}
