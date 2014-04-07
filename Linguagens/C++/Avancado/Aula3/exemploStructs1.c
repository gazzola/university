/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploStructs1.c - Demonstra com utilizar estruturas em C
 */
 
#include<stdio.h>
#include<string.h>

struct Endereco {
    char rua[50];
    int numero;
    char bairro[20];
    char *cidade;
    char siglaEstado[3];
    long int cep;
};

struct Pessoa {
    char nome[100];
    char telefone[14];
    struct Endereco *endereco;
};

int main() {
   
    return 0;
}
