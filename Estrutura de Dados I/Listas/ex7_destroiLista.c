#include <stdio.h>
#include "bib.h"

void destroiLista(Lista *l){
    Nodo *aux = (*l);
    while(aux != NULL){
        Nodo *libera = aux;
        aux = aux->prox;
        free(libera);
    }
    (*l) = NULL;
}
