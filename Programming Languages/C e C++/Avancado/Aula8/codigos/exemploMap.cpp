/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploMap.cpp - Mostra como utilizar a classe map de C++.
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
    map < string, float > mapaDeNotas;

    mapaDeNotas["EU"] = 10.0f;
    mapaDeNotas["TU"] = 5.5f;
    mapaDeNotas["ELE"] = 8.5f;


    map < string, float > :: const_iterator iter;

    // imrime na ordem ELE, EU, TU
    for (iter = mapaDeNotas.begin(); iter != mapaDeNotas.end(); iter++) {
        cout << iter->first << '\t'
             << iter->second << '\n';
    }

    cout << endl;
    mapaDeNotas["EU"] = 9.5f;

    cout << "EU\t" << mapaDeNotas["EU"] << endl;

    map < string, float,  greater <string> > copia;
    //map < string, float, greater <string> > :: conts_iterator iter;

    for (iter = mapaDeNotas.begin(); iter != mapaDeNotas.end(); iter++) {
        copia[iter->first] = iter->second;
    }

    cout << endl;
    // imrime na ordem TU, EU, ELE
    for (iter = copia.begin(); iter != copia.end(); iter++) {
        cout << iter->first << '\t'
             << iter->second << '\n';
    }

    return 0;
}
