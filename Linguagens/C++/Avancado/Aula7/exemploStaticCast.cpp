/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStaticCast.cpp - Mostra como utlizar o StaticCast.
 */

class A { };

class B : public A { };

int main() {
    int i = 45;
    float f;

    f = i;
    // outra maneira:
    f = static_cast<float>(i);

    // gera um warning
    i = f; // pode perder informação

    i = (int) f; // evita o warning
    i = static_cast<int>(f); // evita o warning

    A *a = new A();
    B *b = (B *) a;// compila!!!
    b = static_cast<B*>(a);// compila!!!

    int *p = (int *) a; // compila
    // mas assim não compila:
    //p = static_cast<int*> (a);

    return 0;
}
