/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploConversao.c - Mostra como utiliza as fun��es de convers�o de tipo da
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
	// Se um erro tivesse ocorrido poder�amos fazer:
	// return EXIT_FAILURE;
}
