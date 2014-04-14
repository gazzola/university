/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploAlocacaoDinamica2.c - Mostra como utilizar a fun��o calloc
 */

#include <stdio.h>
#include <stdlib.h>

char **nomes;
int proximo = 0;
int tamanho = 0;

void inserir(char *novoNome) {
	if (proximo == tamanho) {
		tamanho = tamanho * 2;
		printf("End - A: %p\n", nomes);
		nomes = realloc(nomes, tamanho * sizeof(char *));
		printf("End - D: %p\n", nomes);
	}

	nomes[proximo] = novoNome;
	proximo++;
}

void alocar(int t) {
	nomes = calloc(t, sizeof(char *));
	tamanho = t;
}

void liberar() {
	free(nomes);
}

int main() {
	int i = 0;

	alocar(3);
	
	malloc(7 * sizeof(int));

	inserir("Eu");
	inserir("Tu");
	inserir("Eles");
	inserir("Nos");
	inserir("Vos");
	inserir("Eles");

	for (i = 0; i < proximo; i++) {
		printf("%s\n", nomes[i]);
	}

	liberar();

	return 0;
}
