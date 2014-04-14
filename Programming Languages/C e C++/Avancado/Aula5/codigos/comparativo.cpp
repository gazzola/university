/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * comparativo.cpp - Exemplo das difenças entre C e C++
 */

#include <iostream>
#include <string> // diferente de string.h de C

using namespace std;

/*
 * Demosntra como utilizar referências como parâmetros de uma função.
 * Os parâmetros a e b podem ser utilizados como se fossem inteiros.
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
 * Demonstra a possibilidade de se criar uma função com o mesmo nome de uma
 * outra definida anteriormente, porém com protótipos distintos.
 */
void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

/*
 * Demonstra como seter o valor de faulta de um argumento da função.
 */
int mult(int a = 2, int b = 1) {
    return a * b;
}

int main() {
    int a = 10;
    float f = float(a); // novo tipo de cast

    cout << "f = " << f << endl;

    int b = 20; // variável declarada meio do bloco

    cout << "Antes:  a =  " << a << ", b = " << b << endl;
    swap(a, b);  // o compilador trata de chamar a função correta
    cout << "Depois: a =  " << a << ", b = " << b << endl;

    float d = 45.5; // variável declarada meio do bloco

    cout << "Antes:  f =  " << f << ",   d = " << d << endl;
    swap(f, d); // o compilador trata de chamar a função correta
    cout << "Depois: f =  " << f << ", d = " << d << endl;

    cout << "mult(a, b) = " << mult(a, b) << endl;
    cout << "mult(a) = " << mult(a) << endl;
    cout << "mult() = " << mult() << endl;

    // Alocação de memória com o new
    int *array = new int[10];

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    cout << "Array: ";
    for (int j = 0; j < 10; j++) {
        cout << array[j] << " ";
    }

    delete[] array;

    cout << endl;

    // ES
    cout << "Qual o seu nome? ";

    string nome; // em C++ existe um tipo chamado string

    cin >> nome; // cin permite a leitura de dados da entrada padrão

    cout << "Ola " << nome << endl;

    return 0;
}
    
