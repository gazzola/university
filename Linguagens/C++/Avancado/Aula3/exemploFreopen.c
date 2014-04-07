/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploFreopen.c - Mostra como utilizar a fun��o freopen
 */


#include <stdio.h>

int main() {
	char s[40];

	freopen("exemploFreopen.txt", "w", stdout);

	printf("freopen � muito legal!!!");

	fclose(stdout);

	freopen("exemploFreopen.txt", "r", stdin);

	scanf("%s", s);

	fclose(stdin);

	freopen("exemploFreopen.txt", "a", stdout);

	printf("%s", s);

	return 0;
}
