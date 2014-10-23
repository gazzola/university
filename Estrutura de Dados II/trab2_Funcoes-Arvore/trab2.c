#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trab2.h"

// 1
void cria_arvore(raiz *r){
    (*r)=NULL;
}
 

//2
no *aloca_no(int x){
    no *novo = (no*)malloc(sizeof(no));
    novo->esq=novo->dir=NULL;
    novo->dado = x;
    return novo;
}


// 3
void insere(raiz *r, int x){
 
    if(arvore_vazia(&(*r))){
        no *novo = aloca_no(x);
        (*r) = novo;
    }else if(x >= (*r)->dado)
        insere(&(*r)->dir, x);
    else
        insere(&(*r)->esq, x);
}
 

// 4
void insere_filho_esq(raiz *r, int pai, int x){

    if(pai == (*r)->dado && (*r)->esq == NULL){
        no *novo = aloca_no(x);
        (*r)->esq = novo;
        return;
    }
    
    if((*r)->esq != NULL)
        insere_filho_esq(&(*r)->esq, pai, x);

    if((*r)->dir != NULL)
        insere_filho_esq(&(*r)->dir, pai, x);
}
 

// 5
void insere_filho_dir(raiz *r, int pai, int x){

    if(pai == (*r)->dado && (*r)->dir == NULL){
        no *novo = aloca_no(x);
        (*r)->dir = novo;
        return;
    }
    
    if((*r)->esq != NULL)
        insere_filho_dir(&(*r)->esq, pai, x);

    if((*r)->dir != NULL)
        insere_filho_dir(&(*r)->dir, pai, x);

}


// 6
no *localiza(raiz *r, int x){
    if(*r == NULL)
        return NULL;
    else if((*r)->dado == x)
        return (*r);

    no *e = localiza(&(*r)->esq, x);
    if(e != NULL)
        return e;
    no *d = localiza(&(*r)->dir, x);
    if(d != NULL)
        return d;
    
    return NULL;
}


// 7
no *localiza_ordenado(raiz *r, int x){

    if(*r == NULL)
        return NULL;
    else if((*r)->dado == x)
        return (*r);
    else if((*r)->dado > x)
        return localiza(&(*r)->esq, x);
    else
        return localiza(&(*r)->dir, x);

    return NULL;
}


//8
no *remove_no(raiz *r, int x){
    if(*r == NULL)
        return NULL;
    else if((*r)->dado == x){
        no *aux = (*r);
        (*r) = NULL;
        return aux;
    }

    no *e = remove_no(&(*r)->esq, x);
    if(e != NULL)
        return e;
    
    no *d = remove_no(&(*r)->dir, x);
    if(d != NULL)
        return d;

    return NULL;
}


// 9
int arvore_vazia(raiz *r){
    if((*r) == NULL)
        return 1;
    return 0;
}


// 10
int nivel(raiz *r, no **x){
    if(*r == NULL)
        return 0;
    else if(*r == *x)
        return 1;
    else{
        
        int count=0;
        no *aux = (*r);

        while(1){
             if(aux == (*x))
                return count;
           
            if ((*x)->dado < aux->dado){
                aux = aux->esq;
                count++;
            }
            else{
                aux = aux->dir;
                count++;
            }  
        }

        free(aux);

    }
    return -1;
}


// 11 pai
no *pai(raiz *r, no **x){

    if(*r == NULL || *x == NULL)
        return NULL;
    else if((*r)->esq == (*x) || (*r)->dir == (*x))
            return (*r);
    
    no *e = pai(&(*r)->esq, &(*x));
    no *d = pai(&(*r)->dir, &(*x));
    if(e == NULL)
        return d;
    else 
        return e;
    return NULL;

}


// 12
void em_ordem(raiz *r){
    if(arvore_vazia(&(*r)))
        return;

    if((*r)->esq != NULL)
        em_ordem(&(*r)->esq);

    printf("%d ", (*r)->dado);

    if((*r)->dir != NULL)
        em_ordem(&(*r)->dir);
}

void pre_ordem(raiz *r){
    if((*r)==NULL)
        return;

    printf("%d ", (*r)->dado);

    if((*r)->esq != NULL)
        pre_ordem(&(*r)->esq);

    if((*r)->dir != NULL)
        pre_ordem(&(*r)->dir);
}

void pos_ordem(raiz *r){
    if((*r)==NULL)
        return;

    if((*r)->esq != NULL)
        pos_ordem(&(*r)->esq);

    if((*r)->dir != NULL)
        pos_ordem(&(*r)->dir);

    printf("%d ", (*r)->dado);

}

void em_nivel(raiz *r){
    int h = altura(&(*r));
    int i;
    for(i=1; i<=h; i++)
        imprime_dado_nivel(&(*r), i);
}

// extra
void clear(raiz *r){
    if(*r == NULL)
        return;
    if((*r)->esq != NULL)
        clear(&(*r)->esq);
    
    if((*r)->dir != NULL)
        clear(&(*r)->dir);

    free(*r);
    *r = NULL;
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