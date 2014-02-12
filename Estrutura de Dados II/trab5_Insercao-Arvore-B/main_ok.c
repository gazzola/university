/******************************************
*
* TRABALHO 5 DE ESTRUTURAS DE DADOS II
* Arvores B - Busca e Inserção
* Marcos Vinicius Treviso - 121150107
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>

#define ORDEM 5
#define MAX_CHAVES ORDEM-1
#define MIN_CHAVES (ORDEM-1)/2


typedef int TipoChave;

typedef struct _no{
	char ehFolha;
	int num_chaves;
	TipoChave chaves[ORDEM-1];
	struct _no *filhos[ORDEM];
}no;

typedef no *raiz;



void criaArvore(raiz *r){
	(*r) = NULL;
}

no *aloca_no(TipoChave x){
	no *novo = (no*)malloc(sizeof(no));

	int i;
	for(i=0; i<ORDEM; i++)
		novo->filhos[i] = NULL;

	novo->chaves[0] = x;
	novo->num_chaves = 1;
	novo->ehFolha = 's';
	return novo;
}


no *buscaEmArvoreB(raiz *r, TipoChave x) {

	if(*r == NULL)
		return NULL;

	int i;
	for(i=0; i<(*r)->num_chaves && (*r)->chaves[i]<x; i++);


	if (i+1 > (*r)->num_chaves || (*r)->chaves[i] > x)
		return buscaEmArvoreB(&(*r)->filhos[i], x);
	else
		return (*r);
}

no *buscaFolha(raiz *r, TipoChave x){
	if(*r == NULL)
		return NULL;

	int i;
	for(i=0; i<(*r)->num_chaves && (*r)->chaves[i]<x; i++);

	if((i >= (*r)->num_chaves || (*r)->chaves[i] > x) && (*r)->ehFolha == 'n'){
		return buscaFolha(&(*r)->filhos[i], x);
	}
	else
		return (*r);

}

int ehRaiz(raiz *r){
	int i;
	for(i=0; i<ORDEM; i++)
		if((*r)->filhos[i] != NULL)
			return 1;
	return 0;
}

raiz buscaAscendente(raiz *r){
	if(*r == NULL)
		return NULL;

	int i;
	for(i=0; i<(*r)->num_chaves && (*r)->filhos[i] != (*r); i++);

	if (i+1 > (*r)->num_chaves || (*r)->filhos[i] != (*r))
		return buscaAscendente(&(*r)->filhos[i]);
	else
		return (*r);
}

void deslocaDir(raiz *r, int x, int pos){
	int i;
	for(i=MAX_CHAVES; i>pos; i--)
		(*r)->chaves[i] = (*r)->chaves[i-1];
	(*r)->chaves[pos]=x;
}

void tiraEsq(raiz *r){
	int i;
	for(i=0; i<MIN_CHAVES; i++)
		(*r)->chaves[i] = (*r)->chaves[i+1];
	(*r)->chaves[i] = 9999999;
}

int getPosChave(raiz *r, TipoChave x){
	int i;
    for(i=0; i<(*r)->num_chaves && (*r)->chaves[i]<x; i++);
    return i;
}

void distribuiChaves(raiz *r1, raiz *r2){

	int j=0;

	int i;
	for(i=0; i<ORDEM; i++)
		(*r2)->filhos[i] = NULL;

	i=MIN_CHAVES;
	while(i<MAX_CHAVES){
		(*r2)->chaves[j] = (*r1)->chaves[i];
		(*r1)->chaves[i] = 9999999;
		(*r2)->filhos[j] = (*r1)->filhos[i+1];
		(*r1)->filhos[i+1] = NULL;
		i++;
		j++;
	}

	(*r1)->num_chaves = MIN_CHAVES;
	(*r2)->num_chaves = MIN_CHAVES-1;

}

void juntaRaizes(raiz *r1, raiz *r2){

}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void arrumaNos(raiz *r){
	qsort((*r)->chaves, (*r)->num_chaves, sizeof(int), compare);
}

void insercaoEmArvoreB(raiz *r, TipoChave x){

	if(*r == NULL){
		(*r) = aloca_no(x);
	}
	else{

		no *novo = buscaFolha(&(*r), x);

        if(novo->num_chaves < MAX_CHAVES){
	        int pos = getPosChave(&novo, x);
	        deslocaDir(&novo, x, pos);
            novo->num_chaves++;
            novo->ehFolha = 's';
            return;
        }
        else{

        	int novopai = novo->chaves[MIN_CHAVES];

            no *no1 = novo;
            no *no2 = (no*)malloc(sizeof(no));
            distribuiChaves(&no1, &no2);
            
            if(x >= novopai){
            	int pos = getPosChave(&no2, x);
            	deslocaDir(&no2, x, pos);
            	no2->num_chaves++;
            	tiraEsq(&no2);
            }
            else{
            	int pos = getPosChave(&no1, x);
            	deslocaDir(&no1, x, pos);
            	no1->num_chaves++;
            }
        	
            arrumaNos(&no1);
            arrumaNos(&no2);

        	no1->ehFolha = 's';
            no2->ehFolha = 's';
    	   	

          
            no *novoraiz = (no*)malloc(sizeof(no));
            novoraiz->chaves[0] = novopai;
            novoraiz->num_chaves = 1;
            novoraiz->filhos[0] = no1;
            novoraiz->filhos[1] = no2;
            novoraiz->ehFolha = 'n';
            (*r) = novoraiz;
            
            return;
        }

	}

	return;
}

void em_ordem(raiz *r){
	int i;
	if ((*r) != NULL){
		for (i=0; i<(*r)->num_chaves; i++){
			em_ordem(&(*r)->filhos[i]);
			printf("\n%d", (*r)->chaves[i]);
		}
		em_ordem(&(*r)->filhos[i]);//i+1
	}
} 

void em_normal(raiz *r){
	int i;
	for(i=0; i<MAX_CHAVES; i++)
		if((*r)->chaves[i] < 99999)
			printf("%d\n", (*r)->chaves[i]);
}

int main(){

	raiz novo;
	criaArvore(&novo);
	insercaoEmArvoreB(&novo, 10);
	insercaoEmArvoreB(&novo, 8);
	insercaoEmArvoreB(&novo, 7);
	insercaoEmArvoreB(&novo, 9);
	insercaoEmArvoreB(&novo, 12);
	insercaoEmArvoreB(&novo, 15);
	insercaoEmArvoreB(&novo, 1);
	insercaoEmArvoreB(&novo, 3);
	insercaoEmArvoreB(&novo, 22);
	//insercaoEmArvoreB(&novo, 19);

	
	em_normal(&novo);
	printf("\n");
	em_normal(&novo->filhos[0]);
	printf("\n");
	em_normal(&novo->filhos[1]);
	printf("\n");
	//em_normal(&novo->filhos[2]);
	printf("\n");
	//em_ordem(&novo);
	
	return 0;
}

