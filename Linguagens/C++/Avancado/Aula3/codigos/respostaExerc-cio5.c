/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * respostaExercicio2.c - Resposta ao segundo exercício da terceira aula
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *f = fopen("notas.txt", "r");
	char **nomes;
	float *notas;
	int tamanho, i;
	char tmp[2];


	if (f != NULL) {
		fscanf(f, "%d", &tamanho);

		nomes = (char **) calloc(tamanho, sizeof(char *));
		notas = (float **) calloc(tamanho, sizeof(float *));
		
		for (i = 0; i < tamanho; i++) {
			nomes[i] = (char *) calloc(100, sizeof(char));
			fgets(nomes[i], 99, f); // desce com a linha
			fgets(nomes[i], 99, f);
			nomes[i][strlen(nomes[i])-1] = '\0'; // retira o '\n'
			
			fscanf(f, "%f", &notas[i]);
		}

		printf("NOTAS\n");
		for (i = 0; i < tamanho; i++) {
			printf("%-20s %.2f\n", nomes[i], notas[i]);
			free(nomes[i]);
		}

		free(nomes);
		free(notas);

		fclose(f);
	} else {
		printf("Impossivel abrir o arquivo contendo as notas.\n");
	}
}
