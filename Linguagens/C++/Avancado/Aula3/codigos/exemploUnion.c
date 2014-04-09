/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exmeploUnion.c - Mostra como utilizar uni�es em C
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
