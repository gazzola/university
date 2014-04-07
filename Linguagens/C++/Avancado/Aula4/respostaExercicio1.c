/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.c - Resposta ao primeiro exerc�cio da quarta aula.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int numero, chute= - 1;

	srand(time(NULL));
	numero = rand() % 10;

	while (1) {
		printf("Digite um n�mero entre 0 e 9: ");
		scanf("%d", &chute);

		if (numero == chute) {
			printf("Parabens voce acertou!\n");
			break;
		} else {
			printf("Infelizmente voce errou.\n");
		}
	}

	return EXIT_SUCCESS;
}
