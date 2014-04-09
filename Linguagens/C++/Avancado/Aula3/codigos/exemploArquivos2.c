/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploArquivos1.c - Mostra como utilizar as fun��o ferror
 */


#include <stdio.h>

int main() {
    // cria o arquivo se ele n�o existir
    FILE *fp = fopen("ExemploArquivos2.txt", "w");
    char r[30], *s = "CIn\nCentro de Informatica";


    // se n�o houve erro
    if (fp != NULL) {
        fputs(s, fp);

        // verifica a ocorr�ncia de erros
        if (ferror(fp)) {
            printf("Erro ao imprimir s.\n");
            exit(1);  // sai do programa
        }
    } else {
        printf("Imposs�vel abrir o arquivo.\n");
    }

    // fecha o arquivo
    fclose(fp);

    // abre o arquivo para leitura
    fp = fopen("ExemploArquivos2.txt", "r");

    // se n�o houve erro
    if (fp != NULL) {

        while (!feof(fp)) {
            fgets(r, 29, fp);

            // verifica a ocorr�ncia de erros
            if (ferror(fp)) {
                printf("Erro ao ler do arquivo.\n");
                exit(1); // sai do programa
            }

            printf("%s", r);
        }

        putchar('\n');

    } else {
        printf("Imposs�vel abrir o arquivo.\n");
    }

    getchar();

    return 0;
}
