/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploConstCast.cpp - Mostra como utilizar o const_cast.
 */

int main() {
    const int a = 10;
    int *b;
    
    b = (int *) &a; // estilo antigo
    b = const_cast<int*>(&a);
    
    volatile int v = 0;
    int *u = const_cast<int*>(&v);
    // casts simultâneos não compilam
    //long *l = const_cast<long*>(&v);
    return 0;
}


