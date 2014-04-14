/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.cpp - Resposta ao primeiro exerc�cio da oitava aula.
 */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 2) {
        ifstream entrada(argv[1]);

        if (!entrada.is_open()) {
           cerr << "Arquivo inexistente: " << argv[1] << endl;
        }

        ofstream saida(argv[2]);

        string linha;
        int total = 0;

        cout << "Copiando";
        while (getline(entrada, linha)) {
              saida << linha << endl;
              cout << '.';
              total++;
        }

        entrada.close();
        saida.close();

        cout << endl
             << "Arquivo copiado com sucesso."
             << endl
             << "Total de Linhas copiadas: "
             << total
             << endl;

    } else {
        cout << "Numero de parametros inv�lido!" << endl;
    }


    return 0;
}
