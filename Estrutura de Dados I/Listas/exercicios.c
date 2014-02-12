/*
* Explicar pelo menos 3: 
* criaLista() destroiLista() ehVazia() tamanho() imprime() 
* insereInicio() insereFim() insereNPosicao() removeInicio() removeFim()
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int info;
    struct _nodo *prox;
}Nodo;

typedef Nodo *Lista;
Lista ptLista;



void criaLista(Lista *l){
    (*l) = NULL; // define o ponteiro da lista como null
}


int ehVazia(Lista *l){
    return (*l == NULL) ? 1 : 0;
}


int tamanho(Lista *l){
    int count = 0;
    Nodo *aux = (*l);
    while(aux != NULL){
        aux = aux->prox;
        count++;
    }
    return count;
}


void insereInicio(Lista *l, int x){

    Nodo *novo = (Nodo*) malloc (sizeof(Nodo)); // cria um novo nodo - aloca-se memoria a ele
    novo->info = x; // atribui informacao ao nodo
    novo->prox = (*l); // faz o nodo apontar ao primeiro nodo da lista
    (*l) = novo; // faz o ponteiro da lista aponter para o novo nodo

}



void insereFim(Lista *l, int x){

    Nodo *novo = (Nodo*) malloc (sizeof(Nodo));
    novo->info = x;
    novo->prox = NULL;

    Nodo *aux = (*l);
    if(*l == NULL)
        (*l) = novo;
    else
        while(aux->prox != NULL)
            aux = aux->prox;

    aux->prox = novo;
}


void insereNPosicao(Lista *l, int x, int n){

    Nodo *novo = (Nodo*) malloc (sizeof(Nodo));
    novo->info = x;
    novo->prox = NULL;

    if(*l == NULL){
        (*l) = novo;
    }
    else{
        int count = 0;
        Nodo *aux = (*l);

        while(aux != NULL){
            
            if(count == n){
                Nodo *temp = aux->prox;
                aux->prox = novo;
                novo->prox = temp;
                break;
            }

            count++;
            aux = aux->prox;
        }

    }

}

void removeInicio(Lista *l){
    Nodo *aux = (*l);
    (*l) = aux->prox;
    free(aux);
}

void removeFim(Lista *l){
    Nodo *aux = (*l);
    if(aux->prox == NULL){
        (*l) = NULL;
        free(aux);
    }
    else{
        Nodo *ant = NULL;
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }

        ant->prox = NULL;
        free(aux);
    }
}


void imprime(Lista l){
    Lista aux = l; //ir para o primeiro da lista

    while(aux != NULL){ // enquanto nao for o fim da lista
        printf("%d", aux->info); // imprime a info do nodo
        aux = aux->prox; // passa para o proximo nodo
    }
}

void imprimeRec(Lista l){

    if(l == NULL)
        return;

    printf("%d", l->info);
    imprimeRec(l->prox);
}
