/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploSet.cpp - Mostra como utilizar a classe set de C++.
 */

#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

int main() {
    // less � uma fun��o gen�rica
    set< string, less<string> > stringSet;
    // permite que a lista possa ser copida para cout
    ostream_iterator<string> output(cout, " ");

    stringSet.insert("EU");

    // n�o faz nada
    stringSet.insert("EU");

    stringSet.insert("TU");
    stringSet.insert("ELE");

    copy(stringSet.begin(), stringSet.end(), output);
  
    cout << endl;

    return 0;
}
