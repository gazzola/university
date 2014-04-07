/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploTime.c - Mostra com utilizar o header time.h de C
 *
 */

#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
	clock_t clockInicial = clock();
	time_t inicio = time(NULL);
	struct tm *hoje = localtime(&inicio);
	int i;

	printf("Horario local\n");
	printf("Hoje: %02d/%02d/%02d\n", hoje->tm_mday, hoje->tm_mon + 1, hoje->tm_year + 1900);
	printf("Hora: %02d:%02d:%02d\n", hoje->tm_hour, hoje->tm_min + 1, hoje->tm_sec);
	printf("Horario de verao: %d\n", hoje->tm_isdst);

	hoje = gmtime(&inicio);
	printf("GMT\n");
	printf("Hoje: %02d/%02d/%02d\n", hoje->tm_mday, hoje->tm_mon + 1, hoje->tm_year + 1900);
	printf("Hora: %02d:%02d:%02d\n", hoje->tm_hour, hoje->tm_min + 1, hoje->tm_sec);
	printf("Horario de verao: %d\n", hoje->tm_isdst);

	for (i = 0; i < INT_MAX; i++);

	printf("Segundos decorridos desde o inicio do programa: %d\n", time(NULL)-inicio);
	printf("Ciclos decorridos no processador desde o inicio do programa: %d\n", clock() - clockInicial);

	getchar();

	return 0;
}
