/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio6.c - Resposta ao sexto exerc�cio da quarta aula.
 */


#include <stdio.h>
#include <stdarg.h>

int maximo(int qtd, int a, ...) {
	int retorno = a, i;
	va_list lista;

	va_start(lista, a);

	for (i = 1; i < qtd; i++) {
		a = va_arg(lista, int);
		if (retorno < a) {
			retorno = a;
		}
	}

	return retorno;
}

int main() {
	printf("maximo(2, 4, 7, 0, -1, 80, 6) = %d\n", maximo(7, 2, 4, 7, 0, -1, 80, 6));
	printf("maximo(4, 3) = %d\n", maximo(2, 4, 3));
	
	return 0;
}
