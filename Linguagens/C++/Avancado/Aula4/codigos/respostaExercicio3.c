/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExerccio3.c - Resposta ao terceiro exercício da quarta aula
 *
 */

#include <stdio.h>
#include <limits.h>

void somar(int a, int b) {
	if (INT_MAX - a - b < 0) {
		printf("ERRO!\n");
	} else {
		printf("Resultado: %d\n", a+b);
	}

}

int main() {
	somar(INT_MAX, 10);
	somar(INT_MAX, -10);
	somar(INT_MAX, INT_MAX);

	return 0;
}
