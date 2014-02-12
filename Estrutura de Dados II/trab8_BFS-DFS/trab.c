/******************************************
*
* TRABALHO 8 DE ESTRUTURAS DE DADOS II
* Busca em Profundidade e Busca em Largura
* Marcos Vinicius Treviso - 121150107
* EXECUTAR: ./trab < arq.txt
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>

#define B 0
#define C 1
#define P 2

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


typedef struct _fila{
	Nodo *inicio;
	Nodo *fim;
}Fila;



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



// ALGORITMOS PARA VETORES

void preencheVetores(int *visitados, int *antecessores, int nv){
	int i;
	for(i=0; i<nv; i++){
		visitados[i] = B;
		antecessores[i] = -1;
	}


	visitados[0] = C;
	antecessores[0] = 0;

}

void exibeVetor(int *vetor, int n){
	int i=0;
	for (i=0; i<n; i++)
		printf("%d ", vetor[i]);
}	


// LISTA

int proximo(ListaVet *l, int u, int last){

	NodoL *aux = (*l);
	while(aux != NULL && aux->valor < u)
		aux=aux->bottom;

	Nodo *aux2 = (aux!=NULL) ? aux->right : NULL;

	while(aux2 != NULL){
		if(last < aux2->valor)
			return aux2->valor;
		aux2 = aux2->prox;
	}

	return -1;
}



// ALGORITMOS PARA PILHA

void empilha(ListaAdj *p, int x){
	Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
	novo->valor = x;
	novo->prox = (*p);
	(*p)=novo;
}

void desempilha(ListaAdj *p, int *v){
	if((*p)==NULL)
		return;
	Nodo *aux = (*p);
	(*p) = (*p)->prox;
	*v = aux->valor;
	free(aux);
}


// ALGORITMOS PARA FILA

void criaFila(Fila *f){
	f->inicio=NULL;
	f->fim=NULL;
}

int ehVaziaFila(Fila *f){
	if(f->inicio == NULL)
		return 1;
	return 0;
}

void insereFila(Fila *f, int x){
	Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
	novo->valor = x;
	novo->prox = NULL;
	
	if(ehVaziaFila(f))
		f->inicio = novo;
	else
		f->fim->prox = novo;

	f->fim = novo;
}

int removeFila(Fila *f){
	int primeiro = -1;
	Nodo* aux;

	if(!ehVaziaFila(f)){

		primeiro = f->inicio->valor;
		aux = f->inicio;
		f->inicio = f->inicio->prox;

		if(f->inicio == NULL) 
			f->fim = NULL;

		free(aux);
	}

	return primeiro;
}

void destroiFila(Fila *f){
	while(!ehVaziaFila(f))
		removeFila(f);
}

void exibeFila(Fila *f){
	Nodo *aux = f->inicio;
	while(aux!=NULL){
		printf("%d ", aux->valor);
		aux = aux->prox;
	}

	free(aux);
}





// BUSCA EM PROFUNDIDADE

void buscaProfundiade(ListaVet *l, int *visitados, int *antecessores, int x, Fila *marks){

	ListaAdj pilha;
	criaListaAdj(&pilha);
	empilha(&pilha, x);

	int u, v, last=-1;

	while(pilha != NULL){
		desempilha(&pilha, &u);
		insereFila(&(*marks), u);

		while(1){

			v = proximo(&(*l), u, last);
			if(v == -1)
				break;

			if(visitados[v] == B){
				visitados[v] = C;
				empilha(&pilha, v);
			}

			if(visitados[u] != B && antecessores[v] == -1)
				antecessores[v] = u;

			visitados[u] = P;
			last = v;

		}
		
		last = -1;
		
	}

	destroiListaAdj(&pilha);
}


// BUSCA EM LARGURA

void buscaLargura(ListaVet *l, int *visitados, int *antecessores, int x, Fila *marks){
	visitados[x] = C;

	Fila fila;
	criaFila(&fila);
	insereFila(&fila, x);

	int u, v, last=-1;

	while(!ehVaziaFila(&fila)){

		u = removeFila(&fila);
		insereFila(&(*marks), u);

		while(1){
			v = proximo(&(*l), u, last);

			if(v == -1)
				break;

			if(visitados[v] == B){
				visitados[v] = C;
				antecessores[v] = u;
				insereFila(&fila, v);
			}

			//if(visitados[u] == C && antecessores[v] == -1)
			//	antecessores[v] = u;

			visitados[u] = P;
			last = v;
		}
		
		
		last = -1;

	}

	destroiFila(&fila);
}


int main(){

	ListaVet nl;
	criaListaVet(&nl);

	int nv, na, n, a;
	scanf("%d %d", &nv, &na);

	int *visitados = (int*) malloc (nv*sizeof(int));
	int *antecessores = (int*) malloc (nv*sizeof(int));
	preencheVetores(visitados, antecessores, nv);

	while(na--){
		scanf("%d %d", &n, &a);
		insereVet(&nl, n);
		ligar(n, a, &nl);
	}

	Fila marks;
	criaFila(&marks);


	printf("\nGRAFO - LISTA DE ADJACENCIA:\n");
	printf("--------------------------------------\n");
	exibeLista(&nl);
	printf("\n");



	printf("\nBUSCA EM PROFUNDIDADE:\n");
	printf("--------------------------------------\n");
	buscaProfundiade(&nl, visitados, antecessores, 0, &marks);

	printf("VISITADOS:     ");
	exibeVetor(visitados, nv);
	printf("\n");
	printf("ANTECESSORES:  ");
	exibeVetor(antecessores, nv);
	printf("\n");
	printf("PERCORRIMENTO: ");
	exibeFila(&marks);

	preencheVetores(visitados, antecessores, nv);
	destroiFila(&marks);
	criaFila(&marks);


	printf("\n\n");


	printf("\nBUSCA EM LARGURA:\n");
	printf("--------------------------------------\n");
	buscaLargura(&nl, visitados, antecessores, 0, &marks);

	printf("VISITADOS:     ");
	exibeVetor(visitados, nv);
	printf("\n");
	printf("ANTECESSORES:  ");
	exibeVetor(antecessores, nv);
	printf("\n");
	printf("PERCORRIMENTO: ");
	exibeFila(&marks);

	printf("\n");

	free(visitados);
	free(antecessores);
	destroiFila(&marks);
	destroiListaVet(&nl);

	return 0;
}
