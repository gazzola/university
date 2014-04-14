/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploError.c - Mostra como utilizar a diretiva de compilação #error
 */

int main() {

    // _WIN32 é uma diretiva que os compiladores usam para indicar que são
    // do  windows
    #ifndef __linux__
        #error Este programa so compila no Linux :D
    #endif

}
