/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploArquivos1.c - Mostra como utilizar as função ferror
 */


#include <stdio.h>

int main() {
    // cria o arquivo se ele não existir
    FILE *fp = fopen("ExemploArquivos2.txt", "w");
    char r[30], *s = "CIn\nCentro de Informatica";


    // se não houve erro
    if (fp != NULL) {
        fputs(s, fp);

        // verifica a ocorrência de erros
        if (ferror(fp)) {
            printf("Erro ao imprimir s.\n");
            exit(1);  // sai do programa
        }
    } else {
        printf("Impossível abrir o arquivo.\n");
    }

    // fecha o arquivo
    fclose(fp);

    // abre o arquivo para leitura
    fp = fopen("ExemploArquivos2.txt", "r");

    // se não houve erro
    if (fp != NULL) {

        while (!feof(fp)) {
            fgets(r, 29, fp);

            // verifica a ocorrência de erros
            if (ferror(fp)) {
                printf("Erro ao ler do arquivo.\n");
                exit(1); // sai do programa
            }

            printf("%s", r);
        }

        putchar('\n');

    } else {
        printf("Impossível abrir o arquivo.\n");
    }

    getchar();

    return 0;
}
