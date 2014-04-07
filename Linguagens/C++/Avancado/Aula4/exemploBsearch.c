/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exenploBsearch.c - Mostra como utilizar a fun��o bsearch() do header stdlib.h
 *
 */

#include <stdio.h>
#include <stdlib.h>

int funcaoDeComparacao(const void *e1, const void *e2) {
    int a = *((int *) e1);
    int b = *((int *) e2);
    
    return a - b;
}

int main() {
    int elementos[] = { -9, 0, 9, 10, 15, 45 };
    int *p, chave, indice;

    chave = 0;
    p = (int *) bsearch(&chave, elementos, 6, sizeof(int), funcaoDeComparacao);
    
    if (p != NULL) {
        indice = (p - elementos);
        printf("%d percente ao array no indice %d.\n", *p, indice);
    } else {
        printf("%d n�o percente ao array.\n", chave);
    }
    
    chave = -10;
    p = (int *) bsearch(&chave, elementos, 6, sizeof(int), funcaoDeComparacao);
	
    if (p != NULL) {
        printf("%d percente ao array.\n", *p);
    } else {
        printf("%d n�o percente ao array.\n", chave);
    }
    
    getchar();
                
    return EXIT_SUCCESS;
}
