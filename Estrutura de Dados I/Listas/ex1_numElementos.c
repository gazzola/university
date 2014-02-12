#include <stdio.h>
#include "bib.h"

int numElementos(Lista l){
    int n=0;
    Nodo *aux = l;

    while(aux != NULL){
        n++;
        aux = aux->prox;
    }
    return n;
}
