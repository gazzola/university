/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exenploRand.c - Mostra como utilizar as para gera��o de n�meros
 *                 pseudo-aleat�rios do header stdlib.h
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
        
    srand(time(NULL));

    printf("Numero pseudo-aleatorio entre 0 e %d: %d\n", RAND_MAX, rand());
    printf("Numero pseudo-aleatorio entre 0 e 99: %d\n", rand() % 100);
    printf("Numero pseudo-aleatorio entre 5 e 19: %d\n", (rand()%15)+5);
    
    getchar();
    
    return 0;    
}
