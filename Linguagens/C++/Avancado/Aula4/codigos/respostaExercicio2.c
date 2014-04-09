/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio2.c - Resposta ao segundo exercício da quarta aula.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char strings[5][50];
	char chave[50];
	int i;

	for (i = 0; i < 5; i++) {
		scanf("%s", strings[i]);
	}

	qsort(strings, 5, 50 * sizeof(char), strcmp);

	for (i = 0; i < 5; i++) {
		printf("%s ", strings[i]);
	}
	printf("\n");

	scanf("%s", chave);
	while (strcmp(chave, "sair")) {
		if (bsearch(chave, strings, 5, 50 * sizeof(char), strcmp) != NULL) {
			printf("%s pertence ao array.\n", chave);
		} else {
			printf("%s nao pertence ao array.\n", chave);
		}
		scanf("%s", chave);
	}

}
