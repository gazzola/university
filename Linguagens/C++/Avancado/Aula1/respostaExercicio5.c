/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExerccio5.c - Resposta ao quinto exerc�cio da primeira aula.
 */

#include <stdio.h>


int main() {
	int mat[2][2];

	printf("Entre com o elemento 0,0: ");
	scanf("%d", &mat[0][0]);
	printf("Entre com o elemento 0,1: ");
	scanf("%d", &mat[0][1]);
	printf("Entre com o elemento 1,0: ");
	scanf("%d", &mat[1][0]);
	printf("Entre com o elemento 1, 1: ");
	scanf("%d", &mat[1][1]);

	printf("O determinante e: %d\n", mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);

	return 0;
}
