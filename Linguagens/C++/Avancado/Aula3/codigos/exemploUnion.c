/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exmeploUnion.c - Mostra como utilizar uniões em C
 */

#include <stdio.h>

union MinhaUniao {
    long i;
    float l;
};

int main() {
    union MinhaUniao uniao;

    uniao.i = 10;
    printf("%d\n", uniao.i);
    uniao.l = 45.4f;
    printf("%f\n", uniao.l);
    return 0;
}
