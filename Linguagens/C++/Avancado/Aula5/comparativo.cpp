/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * comparativo.cpp - Exemplo das difen�as entre C e C++
 */

#include <iostream>
#include <string> // diferente de string.h de C

using namespace std;

/*
 * Demosntra como utilizar refer�ncias como par�metros de uma fun��o.
 * Os par�metros a e b podem ser utilizados como se fossem inteiros.
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
 * Demonstra a possibilidade de se criar uma fun��o com o mesmo nome de uma
 * outra definida anteriormente, por�m com prot�tipos distintos.
 */
void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

/*
 * Demonstra como seter o valor de faulta de um argumento da fun��o.
 */
int mult(int a = 2, int b = 1) {
    return a * b;
}

int main() {
    int a = 10;
    float f = float(a); // novo tipo de cast

    cout << "f = " << f << endl;

    int b = 20; // vari�vel declarada meio do bloco

    cout << "Antes:  a =  " << a << ", b = " << b << endl;
    swap(a, b);  // o compilador trata de chamar a fun��o correta
    cout << "Depois: a =  " << a << ", b = " << b << endl;

    float d = 45.5; // vari�vel declarada meio do bloco

    cout << "Antes:  f =  " << f << ",   d = " << d << endl;
    swap(f, d); // o compilador trata de chamar a fun��o correta
    cout << "Depois: f =  " << f << ", d = " << d << endl;

    cout << "mult(a, b) = " << mult(a, b) << endl;
    cout << "mult(a) = " << mult(a) << endl;
    cout << "mult() = " << mult() << endl;

    // Aloca��o de mem�ria com o new
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

    cin >> nome; // cin permite a leitura de dados da entrada padr�o

    cout << "Ola " << nome << endl;

    return 0;
}
    
