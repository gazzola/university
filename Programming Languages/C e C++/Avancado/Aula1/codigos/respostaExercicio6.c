/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercício6.c - Resposta ao sexto exercício da primeira aula.
 */

#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
	*a ^= *b ^= *a ^= *b; 
}

int main() {
	int a = 10, b = 15;

	printf("Antes:\na = %d\nb = %d\n", a, b);
	swap(&a, &b);
	printf("Depois:\na = %d\nb = %d\n", a, b);

	return 0;
}
