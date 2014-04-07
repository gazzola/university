/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploEnum.c - Mostra como utilizar enumera��es em C
 */

#include <stdio.h>

enum Linguagens {
	Java, C, Pascal, Assembly, Haskell
} minhaLinguagem;

int main() {
	enum Linguagens outraLinguagem = Java;

	minhaLinguagem = C;

	printf("Valor de Java: %d\n", outraLinguagem); // Imprime 0
	printf("Valor de C: %d\n", minhaLinguagem); // Imprime 1

    return 0;
}
