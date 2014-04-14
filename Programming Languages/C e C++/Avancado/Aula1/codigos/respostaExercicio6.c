/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExerc�cio6.c - Resposta ao sexto exerc�cio da primeira aula.
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
