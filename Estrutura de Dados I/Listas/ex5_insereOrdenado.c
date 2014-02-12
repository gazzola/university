#include <stdio.h>
#include <stdlib.h>
#include "bib.h"


void insereOrdenado(Lista *l, int x){

    Nodo *novo = (Nodo*) malloc (sizeof(Nodo));
    novo->info = x;
    novo->prox = NULL;

    if((*l) == NULL){ // lista vazia
        (*l) = novo;
    }
    else{

        Nodo *aux = (*l);
        Nodo *ant = NULL;
        int inserir = 0;

        while(!inserir){

            if(aux->info > x){ // a informação do nodo atual é maior que n -> insere n antes do nodo atual
                novo->prox = aux;

                if(ant == NULL)// primeiro da lista
                    (*l) = novo;
                else
                    ant->prox = novo;

                inserir = 1;

            }
            else{ // se nao for maior que n avanca para o proximo nodo

                if(aux->prox == NULL){ // fim da lista, insere no fim da lista
                    novo->prox = NULL;
                    aux->prox = novo;
                    inserir = 1;
                }
                else{ // avanca pro proximo nodo
                    ant = aux;
                    aux = aux->prox;
                }

            }

        }

    }
}


void insereOrdenadoSimple(Lista *l, int x){

    Nodo *novo = (Nodo*) malloc (sizeof(Nodo));
    novo->info = x;
    novo->prox = NULL;

    if(*l == NULL){
        (*l) = novo;
    }
    else{

        Nodo *aux = (*l);
        Nodo *ant = NULL;

        while(1){
            if(aux->info > x){
                novo->prox = aux;
                if(ant == NULL)
                    (*l) = novo;
                else
                    ant->prox = novo;

                break;
            }
            else if(aux->prox == NULL){
                aux->prox = novo;
                break;
            }
            else{
                ant = aux;
                aux = aux->prox;
            }
        }

    }

}