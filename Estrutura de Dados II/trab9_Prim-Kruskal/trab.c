/******************************************
*
* TRABALHO 9 DE ESTRUTURAS DE DADOS II
* Algoritmo de Prim e de Kruskal
* Marcos Vinicius Treviso - 121150107
* EXECUTAR: ./trab < arq.txt
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>

#define INF 9999

typedef struct _nodo{
	int valor;
	int peso;
	struct _nodo *prox;
}Nodo;
typedef Nodo *ListaAdj;

typedef struct _nodoA{
	int u;
	int v;
	int peso;
	struct _nodoA *prox;
}NodoA;
typedef NodoA *ListaAdjA;


typedef struct _nodol{
	int valor;
	Nodo *right;
	struct _nodol *bottom;
}NodoL;
typedef NodoL *ListaVet; 




void criaListaAdj(ListaAdj *l){
	(*l) = NULL;
}

void criaListaAdjA(ListaAdjA *l){
	(*l) = NULL;
}

void criaListaVet(ListaVet *l){
	(*l) = NULL;
}



void destroiListaAdjA(ListaAdjA *l){
	NodoA *aux = (*l), *lib;
	while(aux != NULL){
		lib = aux;
		aux = aux->prox;
		free(lib);
	}
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

int procuraListaVet(ListaVet *l, int val){
	NodoL *aux = (*l);
	while(aux != NULL){
		if(aux->valor == val)
			return 1;
		aux = aux->bottom;
	}	
	return 0;
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

int buscaLista(ListaAdj *l, int val){

	Nodo *aux = (*l);
	while(aux != NULL){
		if(aux->valor == val)
			return aux->peso;
		aux = aux->prox;
	}	
	return INF+1;
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

        if(aux->valor != x){
        	novo->bottom = aux->bottom;
        	aux->bottom = novo;
        }

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

        if(aux->valor != x){
        	novo->prox = aux->prox;
        	aux->prox = novo;
    	}
    }
}

void insereAdjAPeso(ListaAdjA *l, int u, int v, int peso){
    NodoA *novo = (NodoA *) malloc(sizeof(NodoA));

    novo->u = u;
    novo->v = v;
    novo->peso = peso;
    novo->prox = NULL;

    if(*l == NULL || (*l)->peso > novo->peso){
        novo->prox = *l;
        *l = novo;
    }
    else{
        NodoA *aux = *l;
        while(aux->prox != NULL){
            NodoA *a = aux->prox;
            if(a->peso > novo->peso)
                break;
            aux = aux->prox;
        }

    	novo->prox = aux->prox;
    	aux->prox = novo;
    }
}


void insereAdjFim(ListaAdj *l, int x, int peso){ 

	Nodo* novo = (Nodo*) malloc (sizeof(Nodo)); 
	novo->valor = x; 
	novo->peso = peso;
	novo->prox = NULL; 

	if((*l) == NULL){
		(*l) = novo; 
	} 
	else{ 
		Nodo* aux = (*l); 
		while(aux->prox != NULL){ 
			aux = aux->prox; 
		} 
		aux->prox = novo; 
	} 
} 


void insereAdjInicio(ListaAdj *l, int x, int peso){
	Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
	novo->valor = x;
	novo->peso = peso;
	novo->prox = (*l);
	(*l)=novo;
}


void removeAdjA(ListaAdjA *l, int *u, int *v, int *p){
	if((*l) != NULL){
		NodoA *atual = (*l);
		*u = atual->u;
		*v = atual->v;
		*p = atual->peso;
		(*l) = atual->prox;
		free(atual);
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


int adjacenteRegular(int x, int y, ListaVet *l){
	NodoL *aux = (*l);
	while(aux != NULL){

		if(aux->valor == x){
			if(procuraLista(&(aux)->right, y))
				return 1;
		}
		aux = aux->bottom;
	}

	return 0;
}

int pesoAresta(int x, int y, ListaVet *l){

	NodoL *aux = (*l);
	while(aux != NULL){

		if(aux->valor == x)
			return buscaLista(&(aux)->right, y);

		aux = aux->bottom;
	}

	return INF+1;
}


void exibeListaAdj(ListaAdj *l){
	Nodo *aux = (*l);
	while(aux != NULL){
		if(aux->peso == -1)
			printf("%d( ) ", aux->valor);
		else
			printf("%d(%d) ", aux->valor, aux->peso);
		aux = aux->prox;
	}
	free(aux);
}

void exibeListaAdjA(ListaAdjA *l){
	NodoA *aux = (*l);
	while(aux != NULL){
		if(aux->peso == -1)
			printf("(%d, %d,  ) ", aux->u, aux->v);
		else
			printf("(%d, %d, %d) ", aux->u, aux->v, aux->peso);
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



int extractMin(ListaAdj *q, int *chave){
	Nodo *aux = (*q);
	int menor = INF;

	while(aux != NULL){
		if(chave[aux->valor] <= menor)
			menor = aux->valor;
		aux = aux->prox;
	}


	removeAdj(&(*q), menor);
	return menor;
}

void insereAdjRes(ListaAdj *l, int x, int peso){ 

	if(procuraLista(&(*l), x)){
		removeAdj(&(*l), x);
		Nodo* novo = (Nodo*) malloc (sizeof(Nodo)); 
		novo->valor = x; 
		novo->peso = peso;
		novo->prox = NULL; 

		if((*l) == NULL){
			(*l) = novo; 
		} 
		else{ 

			Nodo* aux = (*l); 
			while(aux->prox != NULL){
				aux = aux->prox; 
			} 
			aux->prox = novo; 
		} 
	}
	else{
		
		Nodo* aux = (*l); 
		while(aux->prox != NULL){
			if(aux->valor == x){
				aux->peso = peso;
				break;
			}
			aux = aux->prox; 
		} 
	}
} 

void Prim(ListaVet *l, int n, ListaAdj *Elem){
	int i, init = 0;
	int *pi = (int*) malloc (n*sizeof(int));
	int *chave = (int*) malloc (n*sizeof(int));

	ListaAdj Queue;
	criaListaAdj(&Queue);

	for(i=0; i<n; i++){
		pi[i] = -1;
		chave[i] = INF;
		insereAdj(&Queue, i, 0);
	}

	chave[init] = 0;

	int u, pa;
	while(Queue != NULL){

		u = extractMin(&Queue, chave);
		insereAdjFim(&(*Elem), u, pi[u]);

		int v;
		for(v=0; v<n; v++){
			if(adjacente(u, v, &(*l))){

				if(adjacenteRegular(u, v, &(*l))){
					pa = pesoAresta(u, v, &(*l));
					if(procuraLista(&Queue, v) && pa < chave[v]){
						chave[v] = pa;
						pi[v] = u;
					}
				}
				else{
					pa = pesoAresta(v, u, &(*l));
					if(pa < chave[u]){
						chave[u] = pa;
						pi[u] = v;
						insereAdjRes(&(*Elem), u, v);
					}
				}

			}
		}

	}

	free(chave);
	free(pi);
	destroiListaAdj(&Queue);

}




void copiaArestas(ListaVet *l, ListaAdjA *ar){
	NodoL *aux = (*l);
	Nodo *aux2 = NULL;
	while(aux != NULL){
		aux2 = aux->right;
		while(aux2 != NULL){
			insereAdjAPeso(&(*ar), aux->valor, aux2->valor, aux2->peso);
			aux2 = aux2->prox;
		}
		aux = aux->bottom;
	}
}


void Kruskal(ListaVet *l, int n, ListaAdj *Floresta){

	ListaAdjA Arestas;
	criaListaAdjA(&Arestas);
	copiaArestas(&(*l), &Arestas);
	
	int u, v, p;

	while(Arestas != NULL){
		removeAdjA(&Arestas, &u, &v, &p);
		if(u != v){
			insereAdj(&(*Floresta), v, u);
		}
	}

	int i;
	for(i=0; i<n; i++)
		insereAdj(&(*Floresta), i, -1);

	destroiListaAdjA(&Arestas);
}



int main(){

	ListaVet nl;
	criaListaVet(&nl);

	int nv, na, n, a, p;
	scanf("%d %d", &nv, &na);

	while(na--){
		scanf("%d %d %d", &n, &a, &p);
		insereVet(&nl, n);
		ligarcompeso(n, a, p, &nl);
	}


	printf("\nGRAFO - LISTA DE ADJACENCIA:\n");
	printf("--------------------------------------\n");
	exibeLista(&nl);

	printf("\n\n");

	printf("\nALGORITMO DE PRIM:\n");
	printf("--------------------------------------\n");

	ListaAdj prim;
	criaListaAdj(&prim);
	Prim(&nl, nv, &prim);
	exibeListaAdj(&prim);

	printf("\n\n");

	printf("\nALGORITMO DE KRUSKAL:\n");
	printf("--------------------------------------\n");

	ListaAdj krusk;
	criaListaAdj(&krusk);
	Kruskal(&nl, nv, &krusk);
	exibeListaAdj(&krusk);


	printf("\n");
	destroiListaAdj(&prim);
	destroiListaAdj(&krusk);
	destroiListaVet(&nl);

	return 0;
}
