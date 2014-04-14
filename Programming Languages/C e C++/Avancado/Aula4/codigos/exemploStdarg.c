/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStdarg.c - Mostra como criar fun��es que recebem um n�mero
 *                   indeterminado de par�metros.
 */


#include <stdio.h>
#include <stdarg.h>

/*
 * Fun��o que recebe como par�metro e imprime um n�mero indeterminado de strigns.
 *
 * argsCount - O n�mero de par�metros
 * args      - Um ponteiro para o primeiro par�mtro
 */
void printArguments(int argsCount, char *args, ...) {
    va_list ap;
    int i;

    va_start(ap, args); // inicializa a lista de vairaveis
    for (i = 0; i < argsCount; i++) {
        puts(args);
        args = va_arg(ap, char *); // pega o proximo elemento
    }

    va_end(ap); // finaliza a lista
}

int main() {
    printArguments(4, "Allan ", "Diego ", "Silva ", "Lima");
    // voc� pode passar um parametro de qualquer tipo:
    // printArguments(6, "Allan ", "Diego ", "Silva ", "Lima ", 45 );
    // mas assim ir� gerar um erro de execu��o porque a fun��o assume que
    // todos os par�metros s�o stirngs
    printArguments(2, "C", "C++");
    return 0;
}
