/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStdarg.c - Mostra como criar funções que recebem um número
 *                   indeterminado de parâmetros.
 */


#include <stdio.h>
#include <stdarg.h>

/*
 * Função que recebe como parâmetro e imprime um número indeterminado de strigns.
 *
 * argsCount - O número de parâmetros
 * args      - Um ponteiro para o primeiro parâmtro
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
    // você pode passar um parametro de qualquer tipo:
    // printArguments(6, "Allan ", "Diego ", "Silva ", "Lima ", 45 );
    // mas assim irá gerar um erro de execução porque a função assume que
    // todos os parâmetros são stirngs
    printArguments(2, "C", "C++");
    return 0;
}
