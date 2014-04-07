/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploSizeof.c - Demostra como utilizar o operador sizeof em C
 */

#include <stdio.h>

struct Cidade {
	char *nome;
	int populacao;
};

int main () {
	int a = 10;
	int b = sizeof(a);
	float *pf;
	int *pi;
	int array[] = {7, 8, 10, -4};
	int tamanho;

	b = sizeof a; // os parênteses não são obrigatórios


	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(char) = %d\n", sizeof(char));
	printf("sizeof(a) = %d\n", b);

	// soma os atibutos
	printf("sizeof(struct Cidade) = %d\n", sizeof(struct Cidade));
	// sizeof(struct Cidade) = sizeof(nome) + sizeof(populacao);
	// sizeof(struct Cidade) = sizeof(char *) + sizeof(int);

	// ponteiros sempre possuem o mesmo tamanho
	printf("sizeof(pi) = %d\n", sizeof(pi));
	printf("sizeof(pf) = %d\n", sizeof(pf));
	printf("sizeof(pf) = %d\n", sizeof(struct Cidade *));
	
	
	// também podemos utilizar o sizeof para descobrir o tamanho de um array
	tamanho = sizeof(array) / sizeof(int);
	printf("Tamanho do array = %d\n", tamanho);
}
