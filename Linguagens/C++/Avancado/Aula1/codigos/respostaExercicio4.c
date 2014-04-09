/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercício4.c - Resposta ao quarto exercício da primeira aula.
 */

#include <stdio.h>
#include <string.h>

int main() {
	char atual[30];
	char anterior[30] = "";
	char concat[1000] = "";
	int tMax, tMin, tmp;


    scanf("%s", atual);
	strcat(concat, atual);
	tMax = strlen(atual);
	tMin = tMax;
	
	while (strcmp(atual, anterior)) {
		strcpy(anterior, atual);
		scanf("%s", atual);

		strcat(concat, atual);

		tmp = strlen(atual);
	
		if (tMax < tmp) {
			tMax = tmp;
		} else if (tMin > tmp) {
			tMin = tmp;
		}
	}

	printf("------------------RELATORIO------------------\n");
	printf("Tamanho da maior: %d\n", tMax);
	printf("Tamanho da menor: %d\n", tMin);
	printf("Concatenacao: %s\n", concat);


	return 0;
}
