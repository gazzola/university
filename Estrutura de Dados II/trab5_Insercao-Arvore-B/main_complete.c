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


void em_ordem(raiz *r){
	int i;
	if ((*r) != NULL){
		for (i=0; i<(*r)->num_chaves; i++){
			em_ordem(&(*r)->filhos[i]);
			printf("\n%d", (*r)->chaves[i]);
		}
		em_ordem(&(*r)->filhos[i+1]);//i+1
	}
}


void em_normal(raiz *r){
	if(*r != NULL){
	int i;
	for(i=0; i<MAX_CHAVES; i++)
		if((*r)->chaves[i] < 9999)
			printf("%d ", (*r)->chaves[i]);
	}
}


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

	if((i >= (*r)->num_chaves || (*r)->chaves[i] > x) && (*r)->ehFolha == 'n')
		return buscaFolha(&(*r)->filhos[i], x);
	else if((*r)->chaves[i] == x)
		return NULL;
	else
		return (*r);

}


no *buscaAscendente(raiz *r, TipoChave x, raiz *pai){
	if(*r == NULL)
		return NULL;

	int i;


	for(i=0; i<(*r)->num_chaves && (*r)->chaves[i]<x; i++);

	if((i >= (*r)->num_chaves || (*r)->chaves[i] > x) && (*r)->ehFolha == 'n'){
		return buscaAscendente(&(*r)->filhos[i], x, &(*r));
	}
	else
		return (*pai);
}


int ehRaiz(raiz *r){
	int i;
	for(i=0; i<ORDEM; i++)
		if((*r)->filhos[i] != NULL)
			return 1;
	return 0;
}


int getPosFilho(raiz *r, TipoChave x){
	if(*r == NULL)
		return -1;

	int i;
	for(i=0; i<(*r)->num_chaves && (*r)->chaves[i]<x; i++);

	if((i >= (*r)->num_chaves || (*r)->chaves[i] > x) && (*r)->ehFolha == 'n')
		buscaFolha(&(*r)->filhos[i], x);
	
	return i;

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

void tiraDir(raiz *r){
	(*r)->chaves[MIN_CHAVES] = 9999999;
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

void distribuiChavesInv(raiz *r1, raiz *r2){

	int j=0;
	int i;

	i=MIN_CHAVES;
	while(i<MAX_CHAVES){
		(*r1)->chaves[j] = (*r2)->chaves[j];
		(*r2)->chaves[j] = (*r2)->chaves[i];
		(*r2)->chaves[i] = 9999999;
		(*r2)->filhos[j] = (*r2)->filhos[i];
		i++;
		j++;
	}
	(*r2)->filhos[j] = (*r2)->filhos[i];

	(*r1)->num_chaves = MIN_CHAVES;
	(*r2)->num_chaves = MIN_CHAVES-1;

}

void arrumaFilhos(raiz *r){
	int i;
	for(i=0; i<ORDEM; i++)
		(*r)->filhos[i] = NULL;
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

		if(novo == NULL){
			printf("Elemento ja existe! fujam para as colinas u.u\n");
			exit(0);
		}

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
            arrumaFilhos(&no2);
            distribuiChaves(&no1, &no2);

            if(x >= novopai){
            	int pos = getPosChave(&no2, x);
            	deslocaDir(&no2, x, pos);
            	tiraEsq(&no2);
            }
            else{
            	if(novo->chaves[MIN_CHAVES-1] < x)
                	novopai = x;
                else
                	novopai = novo->chaves[MIN_CHAVES-1];
            	int pos = getPosChave(&no1, x);
            	deslocaDir(&no1, x, pos);
            	tiraDir(&no1);
            }

            no1->num_chaves = MIN_CHAVES;
            no2->num_chaves = MIN_CHAVES;

            no1->ehFolha = 's';
            no2->ehFolha = 's';

            arrumaNos(&no1);
            arrumaNos(&no2);

            no *paiaux = NULL;
            no *paino = buscaAscendente(&(*r), novo->chaves[0], &paiaux);

            
            if(paino == NULL)
            	paino = (*r);

            if(paino->ehFolha == 'n'){

                paino->num_chaves++;
            	int i;
            	for(i=0; i<MAX_CHAVES && paino->chaves[i]<novopai; i++);

            	if(paino->num_chaves <= MAX_CHAVES){
            		if(paino->chaves[i] < 99999){//ja tem alocado
            			//desloca chaves
            			int j;
            			for(j=MAX_CHAVES-1; j>i; j--)
            				paino->chaves[j] = paino->chaves[j-1];
            			paino->chaves[i] = novopai;

            			//desloca ponteiros
            			int k;
            			for(k=ORDEM; k>i; k--)
            				paino->filhos[k] = paino->filhos[k-1];
            			paino->filhos[i+1] = no2;
            		}
                    else{
                    	paino->filhos[paino->num_chaves] = no2;
                    	paino->chaves[i] = novopai;
                    }
            	}
                else{//estorou a raiz
                    

                	int novox = novopai;
                	int paigeral;
                	
                	int possel = getPosFilho(&(*r), x);

					if(possel < MIN_CHAVES){//possel<2 = esq | possel>2 = dir | possel=2 = divide
						no *noesq = (no*)malloc(sizeof(no));
						arrumaFilhos(&noesq);
                		no *nodir = paino;


                		no *nomeio = paino->filhos[MIN_CHAVES-1];
						paigeral = paino->chaves[MIN_CHAVES-1];

						distribuiChavesInv(&noesq, &nodir);

		            	int pos = getPosChave(&noesq, novox);
		            	deslocaDir(&noesq, novox, pos);
		            	tiraDir(&noesq);
		            	
		            	noesq->num_chaves = MIN_CHAVES;
			            noesq->ehFolha = 'n';

		            	arrumaNos(&noesq);

		            	//desloca ponteiros
		            	noesq->filhos[0] = no1;
		            	noesq->filhos[1] = no2;
            			noesq->filhos[2] = nomeio;

            			no *raizgeral = (no*)malloc(sizeof(no));
            			arrumaFilhos(&raizgeral);
            			raizgeral->num_chaves = 1;
            			raizgeral->chaves[0] = paigeral;
            			raizgeral->filhos[0] = noesq;
            			raizgeral->filhos[1] = nodir;
            			raizgeral->ehFolha = 'n';
            			(*r) = raizgeral;

					}
					else if(possel > MIN_CHAVES){

						no *noesq = paino;
                		no *nodir = (no*)malloc(sizeof(no));
                		arrumaFilhos(&nodir);

						no *nomeio = paino->filhos[MIN_CHAVES+1];
						paigeral = paino->chaves[MIN_CHAVES];

						distribuiChaves(&noesq, &nodir);

						int pos = getPosChave(&nodir, novox);
		            	deslocaDir(&nodir, novox, pos);
		            	tiraEsq(&nodir);

		            	nodir->num_chaves = MIN_CHAVES;
			            nodir->ehFolha = 'n';

		            	arrumaNos(&nodir);

            			nodir->filhos[0] = nomeio;
		            	nodir->filhos[1] = no1;
            			nodir->filhos[2] = no2;

            			no *raizgeral = (no*)malloc(sizeof(no));
            			arrumaFilhos(&raizgeral);
            			raizgeral->num_chaves = 1;
            			raizgeral->chaves[0] = paigeral;
            			raizgeral->filhos[0] = noesq;
            			raizgeral->filhos[1] = nodir;
            			raizgeral->ehFolha = 'n';
            			(*r) = raizgeral;
		            	
					}
					else{//divide
						
						no *noesq = paino;
						no *temp1 = paino->filhos[MIN_CHAVES+1];
						no *temp2 = paino->filhos[MIN_CHAVES+2];
                		no *nodir = (no*)malloc(sizeof(no));
                		arrumaFilhos(&nodir);
						paigeral = novox;

						distribuiChaves(&noesq, &nodir);

						int pos = getPosChave(&nodir, novox);
		            	deslocaDir(&nodir, novox, pos);
		            	tiraEsq(&nodir);

		            	nodir->num_chaves = MIN_CHAVES;
			            nodir->ehFolha = 'n';

		            	arrumaNos(&nodir);

		            	//desloca ponteiros
		            	nodir->filhos[0] = no2;
		            	nodir->filhos[1] = temp1;
            			nodir->filhos[2] = temp2;
            			noesq->filhos[2] = no1;

            			no *raizgeral = (no*)malloc(sizeof(no));
            			arrumaFilhos(&raizgeral);
            			raizgeral->num_chaves = 1;
            			raizgeral->chaves[0] = paigeral;
            			raizgeral->filhos[0] = noesq;
            			raizgeral->filhos[1] = nodir;
            			raizgeral->ehFolha = 'n';
            			(*r) = raizgeral;
					}

                }

            }
            else{
                no *novoraiz = (no*)malloc(sizeof(no));
                arrumaFilhos(&novoraiz);
                novoraiz->num_chaves = 1;
                novoraiz->chaves[0] = novopai;
                novoraiz->filhos[0] = no1;
                novoraiz->filhos[1] = no2;
                (*r) = novoraiz;
            }

            (*r)->ehFolha='n';
            return;
        }

	}

	return;
}

void em_nivel(raiz *r, int nivel){
  int i;
 
  if ((*r) == NULL) 
  	return;
    
  for (i=ORDEM; i<=nivel; i++)
    printf("  ");
	
  for (i=0; i<(*r)->num_chaves; i++)
    printf("%d  ", (*r)->chaves[i]);

  printf("\n");

  for (i=0; i<=(*r)->num_chaves; i++)
   	 em_nivel(&(*r)->filhos[i], nivel + 1);

}


int main(){

	raiz novo;
	criaArvore(&novo);
	


	insercaoEmArvoreB(&novo, 5);
	insercaoEmArvoreB(&novo, 10);
	insercaoEmArvoreB(&novo, 15);
	insercaoEmArvoreB(&novo, 20);
	insercaoEmArvoreB(&novo, 25);
	insercaoEmArvoreB(&novo, 30);
	insercaoEmArvoreB(&novo, 35);
	insercaoEmArvoreB(&novo, 40);
	insercaoEmArvoreB(&novo, 45);
	insercaoEmArvoreB(&novo, 50);
	insercaoEmArvoreB(&novo, 55);
	insercaoEmArvoreB(&novo, 60);
	insercaoEmArvoreB(&novo, 65);
	insercaoEmArvoreB(&novo, 70);
	insercaoEmArvoreB(&novo, 75);
	insercaoEmArvoreB(&novo, 80);
	insercaoEmArvoreB(&novo, 85);
	insercaoEmArvoreB(&novo, 90);
	insercaoEmArvoreB(&novo, 95);


	/*raiz aux1 = novo->filhos[0];
	raiz aux2 = novo->filhos[1];
	raiz aux3 = novo->filhos[2];
	em_normal(&novo);
	printf("\n\n");
	em_normal(&aux1);
	printf("\n\n");
	em_normal(&aux2);
	printf("\n\n");
	em_normal(&aux3);
	printf("\n\n");
	em_normal(&aux1->filhos[0]);
	printf("\n\n");
	em_normal(&aux1->filhos[1]);
	printf("\n\n");
	em_normal(&aux1->filhos[2]);
	printf("\n\n");
	em_normal(&aux2->filhos[0]);
	printf("\n\n");
	em_normal(&aux2->filhos[1]);
	printf("\n\n");
	em_normal(&aux2->filhos[2]);
	printf("\n\n");
	em_normal(&aux3->filhos[0]);
	printf("\n\n");
	em_normal(&aux3->filhos[1]);
	printf("\n\n");
	em_normal(&aux3->filhos[2]);

	printf("\n");


	em_nivel(&novo, MAX_CHAVES);

	em_normal(&novo);
	printf("\n\n");
	em_normal(&novo->filhos[0]);
	printf("\n\n");
	em_normal(&novo->filhos[1]);
	printf("\n\n");
	em_normal(&novo->filhos[2]);
	printf("\n\n");
	em_normal(&novo->filhos[3]);
	printf("\n\n");
	em_normal(&novo->filhos[4]);
	printf("\n\n");*/

	return 0;
}