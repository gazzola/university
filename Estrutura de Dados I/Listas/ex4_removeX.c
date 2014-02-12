#include <stdio.h>
#include "bib.h"

void removeX(Lista *l, int x){

    Nodo *aux = (*l);
    Nodo *ant = NULL;

    while(aux != NULL){

        if(aux->info == x){
            if(ant == NULL){//primeiro elemento
                (*l) = aux->prox;
                free(aux);
                return;
            }
            else{
                ant->prox = aux->prox;
                free(aux);
                return;
            }
        }

        ant = aux;
        aux = aux->prox;

    }

}

