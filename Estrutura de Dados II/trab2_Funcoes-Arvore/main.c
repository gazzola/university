#include <stdio.h>
#include <stdlib.h>
#include "trab2.c"


int main(){

    raiz novo; 
    cria_arvore(&novo);

    raiz novox;
    no *nox, *paix;
   
    insere(&novo, 8);
    insere(&novo, 3);
    insere(&novo, 10);
    insere(&novo, 1);
    insere(&novo, 6);
    insere(&novo, 14);
    insere(&novo, 4);
    insere(&novo, 7);
    insere(&novo, 13);

    insere_filho_dir(&novo, 13, 12);
    printf("No(12) inserido a direita do No(13)\n");

    insere_filho_esq(&novo, 12, 11);
    printf("No(11) inserido a esquerda do No(12)\n");

    nox = localiza(&novo, 11);
    if(nox)
        printf("N Ordenado: No(%d) encontrado\n", nox->dado);

    nox = localiza_ordenado(&novo, 13);
    if(nox)
        printf("Ordenado: No(%d) encontrado\n", nox->dado);

    novox = remove_no(&novo, 12);
    if(novox)
        printf("No(%d) removido\n", novox->dado);

    printf("Nivel do No(%d): %d\n", nox->dado, nivel(&novo, &nox));

    paix = pai(&novo, &nox);
    printf("Pai do No(%d): %d\n", nox->dado, paix->dado);


    printf("\n\n");
    
    printf("EM ORDEM:\n");
    em_ordem(&novo);

    printf("\n\n");
    
    printf("PRE ORDEM:\n");
    pre_ordem(&novo);

    printf("\n\n");
    
    printf("POS ORDEM:\n");
    pos_ordem(&novo);

    printf("\n\n");
    
    printf("EM NIVEL:\n");
    em_nivel(&novo);

    printf("\n");

    clear(&novo);
    clear(&novox);

    return 0;
}

