#include <stdio.h>
#include "bib.h"

void removeNPosicao(Lista *l, int n){

    int count = 1;
    Nodo *aux = (*l);
    Nodo *ant = NULL;

    while(aux != NULL){

        if(n == count){
            if(ant == NULL){ // n eh o primeiro elemento
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
        count++;

    }

}
