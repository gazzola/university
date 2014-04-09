/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exermploStructs3.c - Demostra como criar e utilizar estruturas em C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cidade {
    char *nome;
    long populacao;
};

struct Estado {
    char *nome;
    char sigla[3];
    struct Cidade *cidades;
    int numeroCidades;
    int populacao;
} pernambuco;


// altera a populacao do estado
void calcularPopulacao(struct Estado *estado) {
    int i = 0, pop = 0;

    for (i = 0; i < estado->numeroCidades; i++) {
        pop = pop + estado->cidades[i].populacao;
    }

    estado->populacao = pop;
}

int main() {
    int i = 0;

    pernambuco.nome = (char *) calloc(15, sizeof(char));
    strcpy(pernambuco.nome, "Pernambuco");
    strcpy(pernambuco.sigla, "PE");
    pernambuco.cidades = (struct Cidade *) calloc(2, sizeof(struct Cidade));
    pernambuco.numeroCidades = 2;


    pernambuco.cidades[0].nome = (char *) calloc(15, sizeof(char));
    strcpy(pernambuco.cidades[0].nome, "Recife");
    pernambuco.cidades[0].populacao = 3000000;

    pernambuco.cidades[1].nome = (char *) calloc(15, sizeof(char));
    strcpy(pernambuco.cidades[1].nome, "Olinda");
    pernambuco.cidades[1].populacao = 500000;

    printf("Estado: %s\n", pernambuco.nome);
    printf("Cidades:\n");

    for (i = 0; i < pernambuco.numeroCidades; i++) {
        printf("%s\n", pernambuco.cidades[i].nome);
    }

    calcularPopulacao(&pernambuco);
    printf("Populacao: %d\n", pernambuco.populacao);

    free(pernambuco.cidades);

    return 0;
}
