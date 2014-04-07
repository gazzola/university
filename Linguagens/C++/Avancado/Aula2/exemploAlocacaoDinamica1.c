/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploAlocacaodinamica1.c - Mostra como utilizar as funções malloc e free
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int *pi = malloc(sizeof(int));

	int *array = malloc(10 * sizeof(int));
	// Outra maneira:
	// int *array = calloc(10, sizeof(int));
	int i;

	// seta o array inteiro para -1
	memset(array, 0xFF, 10 * sizeof(int));

	for (i = 0; i < 10; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}

	*pi = 3;

	for (i = 0; i < 10; i++) {
		array[i] = i;
	}

	free(array);
	free(pi);
	
	return 0;
}
