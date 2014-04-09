/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exenploQsort.c - Mostra como utilizar a função qsort() do header stdlib.h
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcaoDeComparacao(const void *e1, const void *e2) {
    int a = *((int *) e1);
    int b = *((int *) e2);

    return a - b;
}

int main() {
    int elementos1[] = { 10, 15, 0, -9, 45, 9 };
    char elementos2[4][10] = { "Lima", "Diego", "Silva", "Allan" };
    int i;

    printf("Antes do quick sort: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", elementos1[i]);
    }
    printf("\n");

    qsort(elementos1, 6, sizeof(int), funcaoDeComparacao);
    
    printf("Depois do quick sort: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", elementos1[i]);        
    }
    printf("\n");
    
    printf("Antes do quick sort: ");
    for (i = 0; i < 4; i++) {
        printf("%s ", elementos2[i]);
    }
    printf("\n");

    qsort(elementos2, 4, 10 * sizeof(char), strcmp);
    
    printf("Depois do quick sort: ");
    for (i = 0; i < 4; i++) {
        printf("%s ", elementos2[i]);        
    }
    printf("\n");
    
    getchar();
                    
    return EXIT_SUCCESS;
}
