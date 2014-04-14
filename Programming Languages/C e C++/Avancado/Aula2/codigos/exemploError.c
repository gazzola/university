/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploError.c - Mostra como utilizar a diretiva de compila��o #error
 */

int main() {

    // _WIN32 � uma diretiva que os compiladores usam para indicar que s�o
    // do  windows
    #ifndef __linux__
        #error Este programa so compila no Linux :D
    #endif

}
