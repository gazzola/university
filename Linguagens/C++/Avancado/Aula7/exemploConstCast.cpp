/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
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
    // casts simult�neos n�o compilam
    //long *l = const_cast<long*>(&v);
    return 0;
}


