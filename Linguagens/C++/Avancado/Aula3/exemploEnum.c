/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploEnum.c - Mostra como utilizar enumerações em C
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
