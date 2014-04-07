/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploFreopen.c - Mostra como utilizar a função freopen
 */


#include <stdio.h>

int main() {
	char s[40];

	freopen("exemploFreopen.txt", "w", stdout);

	printf("freopen é muito legal!!!");

	fclose(stdout);

	freopen("exemploFreopen.txt", "r", stdin);

	scanf("%s", s);

	fclose(stdin);

	freopen("exemploFreopen.txt", "a", stdout);

	printf("%s", s);

	return 0;
}
