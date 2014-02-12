#include <stdio.h>
#include <stdlib.h>
#include "trab4.h"


void cria_arvore(raiz *r){
    (*r)=NULL;
}


no *aloca_no(int x){
    no *novo = (no*)malloc(sizeof(no));
    novo->esq=novo->dir=NULL;
    novo->dado = x;
    return novo;
}


void rotaciona_direita(raiz *r){
    no *aux = (*r)->esq;
    (*r)->esq = aux->dir;
    aux->dir = (*r);
    (*r) = aux;
}

void rotaciona_esquerda(raiz *r){
    no *aux = (*r)->dir;
    (*r)->dir = aux->esq;
    aux->esq = (*r);
    (*r) = aux;
}


void rotaciona_dupla_direita(raiz *r){
    rotaciona_esquerda(&(*r)->esq);
    rotaciona_direita(&(*r));
}


void rotaciona_dupla_esquerda(raiz *r){
    rotaciona_direita(&(*r)->dir);
    rotaciona_esquerda(&(*r));
}

void rebalancear(raiz *r){

    int hdir=0, hesq=0;
    hdir = altura(&(*r)->dir);
    hesq = altura(&(*r)->esq);

    if(modulo(hdir-hesq)  >= 2){

        int he = altura(&(*r)->esq);
        int hd = altura(&(*r)->dir);
        if(he > hd){
            no *aux = (*r)->esq;
            if(altura(&(aux->esq)) > altura(&(aux->dir)))
                rotaciona_direita(&(*r));
            else
                rotaciona_dupla_direita(&(*r));
        }else{
            no *aux = (*r)->dir;
            if(altura(&(aux->esq)) < altura(&(aux->dir)))
                rotaciona_esquerda(&(*r));
            else
                rotaciona_dupla_esquerda(&(*r));
        }

    }

    return;

}

int modulo(int x){
    if(x<0)
        x = x*(-1);
    return x;
}

void insere(raiz *r, int x, raiz *t){
    
    if(*r == NULL){
        no *novo = aloca_no(x);
        (*r) = novo;
        rebalancear(&(*t));
    }else if(x >= (*r)->dado)
        insere(&(*r)->dir, x, &(*t));
    else
        insere(&(*r)->esq, x, &(*t));
}

void remove_no(raiz *r, int x, raiz *t){

    if(*r == NULL)
        return;
    else if((*r)->dado == x){

        if((*r)->esq == NULL && (*r)->dir != NULL){//tem so um filho na dir
            (*r)=(*r)->dir;
        }
        else if((*r)->esq != NULL && (*r)->dir == NULL){//tem so um filho na esq
            (*r)=(*r)->esq;
        }
        else if((*r)->esq != NULL && (*r)->dir != NULL){//tem dois filhos

            int tamesq = 0, tamdir = 0;

            no *auxpai = (*r);
            no *auxres = (*r)->dir;
            no *aux = (*r)->esq;

            if(aux!=NULL)
                tamesq++;

            while(aux->dir != NULL){
                auxpai=aux;
                aux=aux->dir;
                tamesq++;
            }
            
            no *aux2pai = (*r);
            no *aux2res = (*r)->esq;
            no *aux2 = (*r)->dir;

            if(aux2!=NULL)
                tamdir++;

            while(aux2->esq != NULL){
                aux2pai=aux2;
                aux2=aux2->esq;
                tamdir++;
            }

            if(tamesq >= tamdir){//preferencia para a subarvore a esquerda do no

                if(aux->esq != NULL){//pai
                    auxpai->dir = aux->esq;
                    aux->esq = (*r)->esq;
                    (*r) = aux;
                    (*r)->dir = auxres;
                    rebalancear(&(*r));
                }else{
                    if(tamesq == 1)
                        auxpai->esq = NULL;
                    else
                        auxpai->dir = NULL;
                    aux->esq = (*r)->esq;
                    aux->dir = (*r)->dir;
                    (*r) = aux;
                    rebalancear(&(*r));
                }
            }
            else{

                if(aux2->dir != NULL){//pai
                    aux2pai->esq = aux2->dir;
                    aux->dir = (*r)->dir;
                    (*r) = aux2;
                    (*r)->esq = aux2res;
                    rebalancear(&(*r));
                }
                else{

                    aux2pai->esq = NULL;
                    aux2->esq = (*r)->esq;
                    aux2->dir = (*r)->dir;
                    (*r)=aux2;
                    rebalancear(&(*r));
                }
            }

        }
        else{//folha
            (*r) = NULL;
        }

        
        rebalancear(&(*t));

        return;
    }

    remove_no(&(*r)->esq, x, &(*t));
    remove_no(&(*r)->dir, x, &(*t));

    return;
}


void em_nivel(raiz *r){
    int h = altura(&(*r));
    int i;
    for(i=1; i<=h; i++){
        imprime_dado_nivel(&(*r), i);
        printf("\n");
    }
}

void imprime_dado_nivel(raiz *r, int nivel){
    if((*r) == NULL)
        return;
    if(nivel == 1)
        printf("%d ", (*r)->dado);
    else if (nivel > 1){
        imprime_dado_nivel(&(*r)->esq, nivel-1);
        imprime_dado_nivel(&(*r)->dir, nivel-1);
    }
}

 
int altura(raiz *r){
   if((*r)==NULL)
       return 0;
   else{
     int l_altura = altura(&(*r)->esq);
     int r_altura = altura(&(*r)->dir);
 
     if (l_altura > r_altura)
         return(l_altura+1);
     else 
        return(r_altura+1);
   }
}

void destroi_arvore(raiz *r){
    if(*r == NULL)
        return;

    if((*r)->esq != NULL)
        destroi_arvore(&(*r)->esq);
    
    if((*r)->dir != NULL)
        destroi_arvore(&(*r)->dir);

    free(*r);
    *r = NULL;
}