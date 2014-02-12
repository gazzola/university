#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA NO - ARVORE
typedef struct _no{
	int tipo;
	char operador;
	double valor;
	struct _no *esq;
	struct _no *dir;
}no;

typedef no *raiz;


//ESTRUTURA NODO - LISTA
typedef struct _nodo{
	int tipo;
	char operador;
	double valor;
	struct _nodo *prox;
} Nodo;

typedef Nodo *Lista;



// FUNCOES PARA LISTA

void cria_lista(Lista *l){
	*l = NULL;
}

void destroi_lista(Lista *l){
	Nodo *aux, *libera;
	aux = *l;
	while(aux!=NULL){
		libera = aux;
		aux = aux->prox;
		free(libera);
	}
}

void insere_lista(Lista *l, int tipo, char operador, double valor){
	Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
	novo->tipo = tipo;
	novo->operador = operador;
	novo->valor = valor;
	novo->prox = NULL;
	if(*l == NULL)
		*l = novo;
	else{
		novo->prox = *l;
		*l = novo;
	}
}


// FUNCOES PARA ARVORE

no* cria_no(int tipo, char operador, double valor, no *esq, no *dir){
	no *novo = (no *) malloc(sizeof(no));
	novo->tipo = tipo;
	novo->operador = operador;
	novo->valor = valor;
	novo->esq = esq;
	novo->dir = dir;
	return novo;
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


// FUNCOES REQUISITADAS

double calcula(raiz *r) {
	if(*r == NULL)
		return 0.0;
	else if((*r)->tipo == 1)//operando=tipo=1
		return (*r)->valor;
	else{
		if((*r)->operador == '+')
			return calcula(&(*r)->esq) + calcula(&(*r)->dir);
		else if((*r)->operador == '-')
			return calcula(&(*r)->esq) - calcula(&(*r)->dir);
		else if((*r)->operador == '*')
			return calcula(&(*r)->esq) * calcula(&(*r)->dir);
		else if((*r)->operador == '/')
			return calcula(&(*r)->esq) / calcula(&(*r)->dir);
	}

	return 0.0;
}


void gera_lista(raiz *r, Lista *l){
	if(*r == NULL)
		return;

	gera_lista(&(*r)->esq, l);
	gera_lista(&(*r)->dir, l);
	insere_lista(l, (*r)->tipo, (*r)->operador, (*r)->valor);
}


//FUNCOES DE IMPRIMIR

void em_ordem(raiz *r){
    if((*r)==NULL)
        return;

    if((*r)->esq != NULL)
        em_ordem(&(*r)->esq);

    if((*r)->tipo == 0)
    	printf("%c ", (*r)->operador);
    else
    	printf("%f ", (*r)->valor);

    if((*r)->dir != NULL)
        em_ordem(&(*r)->dir);
}

void pre_ordem(raiz *r){
    if((*r)==NULL)
        return;

    if((*r)->tipo == 0)
    	printf("%c ", (*r)->operador);
    else
    	printf("%f ", (*r)->valor);

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

    if((*r)->tipo == 0)
    	printf("%c ", (*r)->operador);
    else
    	printf("%f ", (*r)->valor);

}

void imprimir(Lista *l){
	Nodo *aux;
	aux = *l;
	while(aux!=NULL){
		if(aux->tipo == 0) //operador=tipo=0
			printf("%c ", aux->operador);
		else
			printf("%f ", aux->valor);
		aux = aux->prox;
	}
}




int main(){

	/* ARVORE BINARIA

			  *
		    /   \
		   +    5.0
		 /   \
	   2.0   1.0

	*/

	no *esq12 = cria_no(1, ' ', 2.0, NULL, NULL);
	no *dir12 = cria_no(1, ' ', 1.0, NULL, NULL);
	no *esq1 = cria_no(0, '+', 0.0, esq12, dir12);
	no *dir1 = cria_no(1, ' ', 5.0, NULL, NULL);
	no *topo = cria_no(0, '*', 0.0, esq1, dir1);

	raiz novo =  topo;
	Lista l;

	cria_lista(&l);

	double result = calcula(&novo);
	printf("RESULTADO: %f\n", result);
	
	printf("\n\n");

	printf("EM LISTA\n");
	gera_lista(&novo, &l);
	imprimir(&l);
	printf(" = %f", result);

	printf("\n\n");

	printf("EM ORDEM:\n");
    em_ordem(&novo);
    printf(" = %f", result);

    printf("\n\n");
    
    printf("PRE ORDEM:\n");
    pre_ordem(&novo);
    printf(" = %f", result);

    printf("\n\n");
    
    printf("POS ORDEM:\n");
    pos_ordem(&novo);
    printf(" = %f", result);

    printf("\n");

	destroi_arvore(&novo);
	destroi_lista(&l);

	return 0;
}