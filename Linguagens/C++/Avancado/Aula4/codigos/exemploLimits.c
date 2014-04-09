/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploLimits.c - Mostra como utilizar o header limits.h para descobri os 
 *                   valores máximos e mínimos dos tipos inteiros.
 */

#include <stdio.h>
#include <limits.h>

int main() {
	printf("Maior inteiro: %d\n", INT_MAX);
	printf("Menor inteiro: %d\n\n", INT_MIN);

	printf("Maior long: %d\n", LONG_MAX);
	printf("Menor long: %d\n\n", LONG_MIN);
	
	printf("Maior short: %hi\n", SHRT_MAX);
	printf("Menor short: %hi\n\n", SHRT_MIN);

	printf("Maior char: %d\n", CHAR_MAX);
	printf("Menor char: %d\n\n", CHAR_MIN);
	
	getchar();

	return 0;
}
