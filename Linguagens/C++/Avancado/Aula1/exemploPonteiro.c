/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploPonteiro.c - Mostra como utilizar ponteiros em C.
 */

#include <stdio.h>

int main() {
    int a = 10, b = 0, *p, *q;

    p = &a;
    a = 12; // *p = 12
    b = *p; // b = 12
    *p = 15; // a = 15
    q = p; // q e p apontam para o mesmo endereço
    *q = 7; // a = 7
    q = &b;
    *q = *p; // b = a = 7
    (*p)++; // a = 8

    printf("a=%d\nb=%d\n*p=%d\n*q=%d\n", a, b, *p, *q);

    return 0;
}
