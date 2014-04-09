/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio5.c - Resposta ao quinto exerc�cio da quarta aula.
 */


#include <stdio.h>
#include <time.h>

int main() {
	time_t t1, t2 = time(NULL);
	struct tm *hoje = localtime(&t2);
    struct tm data;

	printf("Entre com o dia: ");
	scanf("%d", &data.tm_mday);
	printf("Entre com o mes: ");
	scanf("%d", &data.tm_mon);
	printf("Entre com o ano: ");
	scanf("%d", &data.tm_year);

	data.tm_year = data.tm_year - 1900;
	data.tm_hour = 0;
	data.tm_isdst = 0;
	data.tm_min = 0;
	data.tm_sec = 0;
	data.tm_wday = 0;
	// o m�s come�a do 0
	data.tm_mon--;
	// 
	data.tm_mday++;
	

	t1 = mktime(&data);
	// 86400 = um dia
	printf("Falta(m) %d dia(s) para a data digitada.\n", ((t1-t2) / 86400) );
	
	return 0;
}
