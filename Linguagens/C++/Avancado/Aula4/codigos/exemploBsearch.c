/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exenploBsearch.c - Mostra como utilizar a função bsearch() do header stdlib.h
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
        printf("%d não percente ao array.\n", chave);
    }
    
    chave = -10;
    p = (int *) bsearch(&chave, elementos, 6, sizeof(int), funcaoDeComparacao);
	
    if (p != NULL) {
        printf("%d percente ao array.\n", *p);
    } else {
        printf("%d não percente ao array.\n", chave);
    }
    
    getchar();
                
    return EXIT_SUCCESS;
}
