/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exenploProcessos.c - Mostra como utilizar as funções para manipulação de
 *                      processos do header stdlib.h
 *
 */

#include <stdio.h>
#include <stdlib.h>

void f1() {
    printf("Funcao 1 chamada na saida do programa.\n");
}

void f2() {
    printf("Funcao 2 chamada na saida do programa.\n");
}

int main() {
    // as funções são chamadas na ordem inversa
    atexit(f1);
    atexit(f2);

    if (system("explorer") == -1) {
        printf("O comando nao foi executado com sucesso.\n");
        exit(EXIT_FAILURE);            
    }
    
    printf("Comando executado com sucesso.\n");

    return EXIT_SUCCESS;    
}
