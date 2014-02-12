/*
* Execucao: ./trab entrada.pgm saida.pgm
* Manipulacao de imagens .pgm usando listas encadeadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "bib.h"


void criaLista(Lista *l){
    (*l) = NULL;
}

void insereOrdenado(Lista *l, int x, int posi, int posj, int num_colunas){
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->info = x;
    novo->i = posi;
    novo->j = posj;
    novo->prox = NULL;

    if(*l == NULL)
        *l = novo;
    else{
        Nodo* atual = *l;
        Nodo* anterior = NULL;
        int inseri = 0;
        while(!inseri){
            if((atual->i*num_colunas + atual->j) > (posi*num_colunas + posj)){
                novo->prox = atual;
                if(anterior == NULL)
                    *l = novo;
                else
                    anterior->prox = novo;
                inseri = 1;
            }
            else{
                if(atual->prox == NULL){
                    atual->prox = novo;
                    inseri = 1;
                }
                else{
                    anterior = atual;
                    atual = atual->prox;
                }
            }

        }
    }
}

void imprimeLista(Lista *l, int num_linhas, int num_colunas){
    int i, j;
    Nodo *aux = (*l);

    for(i=0; i<num_linhas; i++){
        for(j=0; j<num_colunas; j++){

            if(aux->i == i && aux->j == j){
                printf("%d ", aux->info);
                if(aux->prox != NULL)
                    aux = aux->prox;
            }
            else
                printf("0 ");
        }
        printf("\n");

    }
}


void destroiLista(Lista *l){
    Nodo *aux = (*l);
    while(aux != NULL){
        Nodo *libera = aux;
        aux = aux->prox;
        free(libera);
    }
}

void insereBorda(Lista *l, int num_linhas, int num_colunas){
    Nodo *aux = (*l);
    int i, j, cor = 255;

    for(i=0; i<num_linhas; i++){
        for(j=0; j<num_colunas; j++){

            if(aux->i == i && aux->j == j){
                if(i<3 || j<3 || i>num_linhas-4 || j>num_colunas-4)
                    aux->info = cor;
                if(aux->prox != NULL)
                    aux = aux->prox;
            }
            else{
                if(i<3 || j<3 || i>num_linhas-4 || j>num_colunas-4)
                    insereOrdenado(l, cor, i, j, num_colunas);
            }

        }
    }

}

void inverteImagem(Lista *l, int num_max, int num_linhas, int num_colunas){
    Nodo *aux = (*l);
    int i, j, cor_nova;

    for(i=0; i<num_linhas; i++){
        for(j=0; j<num_colunas; j++){

            if(aux->i == i && aux->j == j){
                cor_nova = num_max-aux->info;
                aux->info = cor_nova;

                if(aux->prox != NULL)
                    aux = aux->prox;
            }
            else
                insereOrdenado(l, num_max, i, j, num_colunas);

        }
    }

}


double crono(){
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1e6;
}

int main(int argc, char **argv){

    double tempo = crono();

    if(argc < 3){
        printf("\nErro! Informe o nome de arquivo que deseja ler como parametro do programa.\n");
        return 1;
    }


    char str_entrada[50], str_saida[50];
    strcpy(str_entrada, "images/");
    strcpy(str_saida, "images/");
    strcat(str_entrada, argv[1]);
    strcat(str_saida, argv[2]);

    FILE *entrada;
    entrada = fopen(str_entrada, "r");

    if(entrada == NULL){
        printf("\nErro! Arquivo de entrada nao encontrado.\n");
        exit(0);
    }

    unsigned short int num_linhas, num_colunas, num_max;
    char txt[3];
    while(!feof(entrada)){
    fscanf(entrada, "%2s", txt);
        if(strcmp(txt, "P2") == 0){
            fscanf(entrada, "%hu %hu %hu", &num_colunas, &num_linhas, &num_max);
            break;
        }
        else{
            printf("\nErro! Arquivo nao eh do tipo PGM.\n");
            return 1;
        }
    }

    printf("NUM_LINHAS:%d NUM_COLUNAS:%d NUM_MAX:%d\n\n", num_linhas, num_colunas, num_max);
    int i, j, val;

    Lista *ptLista = (Lista*) malloc(sizeof(Lista));
    criaLista(ptLista);

    for(i=0; i<num_linhas; i++){
        for(j=0; j<num_colunas; j++){
            fscanf(entrada, "%d", &val);
            if(val != 0)
                insereOrdenado(ptLista, val, i, j, num_colunas);
        }

    }

    printf("\nNORMAL:\n");
    imprimeLista(ptLista, num_linhas, num_colunas);

    insereBorda(ptLista, num_linhas, num_colunas);
    printf("\nINSERE BORDA:\n");
    imprimeLista(ptLista, num_linhas, num_colunas);

    inverteImagem(ptLista, num_max, num_linhas, num_colunas);
    printf("\nINVERTE IMAGEM:\n");
    imprimeLista(ptLista, num_linhas, num_colunas);

    FILE *saida;
    saida = fopen(str_saida, "w+");
    fprintf(saida, "P2\n%d %d\n%d\n", num_colunas, num_linhas, num_max);
    Nodo *aux = (*ptLista);

    for(i=0; i<num_linhas; i++){
        for(j=0; j<num_colunas; j++){

            if(aux->i == i && aux->j == j){
                fprintf(saida, "%d ", aux->info);
                if(aux->prox != NULL)
                    aux = aux->prox;
            }
            else
                fprintf(saida, "0 ");
        }
        fprintf(saida, "\n");

    }

    tempo = crono() - tempo;
    printf("\n\nTEMPO DE EXECUCAO: %lf", tempo);

    fclose(saida);
    fclose(entrada);
    destroiLista(ptLista);
    free(ptLista);

    return 0;
}
