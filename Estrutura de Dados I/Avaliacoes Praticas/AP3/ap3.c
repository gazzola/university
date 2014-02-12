#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    char info;
    struct _nodo *prox;
}Nodo;

typedef Nodo *Lista;


void insereFim(Lista *l, int x){

    Nodo *novo = (Nodo*) malloc (sizeof(Nodo));
    novo->info = x;
    novo->prox = NULL;

    if((*l) == NULL){
        (*l) = novo;
    }
    else{
        Nodo *aux = (*l);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void criaLista(Lista *l){
    (*l)=NULL;
}

void funcao(Lista *l){

    Nodo *aux = (*l);
    Nodo *temp = (*l);

    while(temp!=NULL){
        Nodo *novo = (Nodo*) malloc (sizeof(Nodo));
        novo->prox=temp->prox;
        novo->info=temp->info;
        temp=temp->prox;
        aux->prox=novo;
        aux = temp;
    }

}


void imprime(Lista *l){

    Nodo *aux = (*l);
    while(aux != NULL){
        printf("%c ", aux->info);
        aux = aux->prox;
    }
    printf("\n\n");

}

int main(){


    Lista ptLista;
    criaLista(&ptLista);
    insereFim(&ptLista, 'a');
    insereFim(&ptLista, 'b');
    insereFim(&ptLista, 'c');
    funcao(&ptLista);
    imprime(&ptLista);

    return 0;
}
