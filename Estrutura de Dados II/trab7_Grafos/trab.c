/******************************************
*
* TRABALHO 7 DE ESTRUTURAS DE DADOS II
* Funções básicas de grafo
* Marcos Vinicius Treviso - 121150107
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct _nodo{
	int valor;
	int peso;
	struct _nodo *prox;
}Nodo;
typedef Nodo *ListaAdj;


typedef struct _nodol{
	int valor;
	Nodo *right;
	struct _nodol *bottom;
}NodoL;
typedef NodoL *ListaVet; 



void criaListaAdj(ListaAdj *l){
	(*l) = NULL;
}

void criaListaVet(ListaVet *l){
	(*l) = NULL;
}

void destroiListaAdj(ListaAdj *l){
	Nodo *aux = (*l), *lib;
	while(aux != NULL){
		lib = aux;
		aux = aux->prox;
		free(lib);
	}
	(*l) = NULL;
}

int procuraLista(ListaAdj *l, int val){

	Nodo *aux = (*l);

	while(aux != NULL){
		if(aux->valor == val)
			return 1;
		aux = aux->prox;
	}	
	return 0;
}

void insereVet(ListaVet *l, int x){
    NodoL *novo = (NodoL *) malloc(sizeof(NodoL));

    ListaAdj l2;
    criaListaAdj(&l2);

    novo->valor = x;
    novo->right = l2;
    novo->bottom = NULL;

    if(*l == NULL || (*l)->valor > novo->valor){
        novo->bottom = *l;
        *l = novo;
    }
    else{
        NodoL *aux = *l;
        while(aux->bottom != NULL){
            NodoL *a = aux->bottom;
            if(a->valor > novo->valor)
                break;
            aux = aux->bottom;
        }
        novo->bottom = aux->bottom;
        aux->bottom = novo;
    }
}



void insereAdj(ListaAdj *l, int x, int peso){
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));

    novo->valor = x;
    novo->peso = peso;
    novo->prox = NULL;

    if(*l == NULL || (*l)->valor > novo->valor){
        novo->prox = *l;
        *l = novo;
    }
    else{
        Nodo *aux = *l;
        while(aux->prox != NULL){
            Nodo *a = aux->prox;
            if(a->valor > novo->valor)
                break;
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}


void removeAdj(ListaAdj *l, int x){ 
	Nodo* atual = (*l); 
	Nodo* anterior = NULL; 
	while(atual != NULL){ 
		if(atual->valor == x){ 
			if(anterior == NULL){
				(*l) = atual->prox; 
				free(atual); 
				return; 
			} 
			else{ 
				anterior->prox = atual->prox; 
				free(atual); 
				return; 
			} 
		} 
		anterior = atual; 
		atual = atual->prox; 
	} 
} 

void removeVet(ListaVet *l, int x){

	NodoL* atual = (*l); 
	NodoL* anterior = NULL; 
	while(atual != NULL){ 

		if(procuraLista(&atual->right, x)){
			removeAdj(&atual->right, x);
		}

		if(atual->valor == x){ 
			if(anterior == NULL){
				(*l) = atual->bottom; 
				destroiListaAdj(&atual->right);
				free(atual);
			} 
			else{ 
				anterior->bottom = atual->bottom; 
				destroiListaAdj(&atual->right);
				free(atual);
			}
		} 

		anterior = atual; 
		atual = atual->bottom; 
	} 
} 

void destroiListaVet(ListaVet *l){
	NodoL *aux = (*l), *lib;
	while(aux != NULL){
		if(aux->right != NULL)
			destroiListaAdj(&(aux)->right);
		lib = aux;
		aux = aux->bottom;
		free(lib);
	}
	(*l) = NULL;
}


void ligarcompeso(int x, int y, int p, ListaVet *l){
	NodoL *aux = (*l);
	while(aux != NULL){
		if(aux->valor == x){
			if(!procuraLista(&aux->right, y))
				insereAdj(&aux->right, y, p);
			return;
		}
		aux = aux->bottom;
	}
}


void desligar(int x, int y, ListaVet *l){
	NodoL *aux = (*l);
	while(aux != NULL){
		if(aux->valor == x){
			removeAdj(&aux->right, y);
		}
		else if(aux->valor == y){
			removeAdj(&aux->right, x);
		}
		aux = aux->bottom;
	}
}


void ligar(int x, int y, ListaVet *l){
	NodoL *aux = (*l);
	while(aux != NULL){
		if(aux->valor == x){
			if(!procuraLista(&aux->right, y))
				insereAdj(&aux->right, y, 0);
			return;
		}
		aux = aux->bottom;
	}
}



int adjacente(int x, int y, ListaVet *l){
	NodoL *aux = (*l);
	while(aux != NULL){

		if(aux->valor == x){
			if(procuraLista(&(aux)->right, y))
				return 1;
		}
		else if(aux->valor == y){
			if(procuraLista(&(aux)->right, x))
				return 1;
		}
		aux = aux->bottom;
	}

	return 0;
}


void exibeListaAdj(ListaAdj *l){
	Nodo *aux = (*l);
	while(aux != NULL){
		printf("%d(%d) ", aux->valor, aux->peso);
		aux = aux->prox;
	}
	free(aux);
}


void exibeLista(ListaVet *l){
	NodoL *aux = (*l);
	while(aux != NULL){
		printf("%d: ", aux->valor);
		exibeListaAdj(&aux->right);
		printf("\n");
		aux = aux->bottom;
	}
	free(aux);
}


int main(){
	
	ListaVet nl;
	criaListaVet(&nl);

	insereVet(&nl, 7);
	insereVet(&nl, 6);
	insereVet(&nl, 5);
	insereVet(&nl, 4);
	insereVet(&nl, 3);

	exibeLista(&nl);
	removeVet(&nl, 3);
	
	printf("\n");

	ligarcompeso(4, 6, 25, &nl);
	ligarcompeso(4, 6, 25, &nl);
	ligar(6, 4, &nl);

	exibeLista(&nl);

	printf("\n");
	removeVet(&nl, 6);
	exibeLista(&nl);

	destroiListaVet(&nl);
	return 0;	
}