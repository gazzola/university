/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploConversao.c - Mostra como utiliza as funções de conversão de tipo da
 *                      biblioteca stdlib.h
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char *si = "10";
	char *sf = "10.48";
	int i;
	float f;

	i = atoi(si);
	f = atof(sf);

	printf("%d\n%f\n", i, f);

	return EXIT_SUCCESS;
	// Se um erro tivesse ocorrido poderíamos fazer:
	// return EXIT_FAILURE;
}
