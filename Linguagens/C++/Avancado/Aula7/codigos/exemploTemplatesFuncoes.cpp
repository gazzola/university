/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploTemplatesFuncoes.cpp - Mostra como definir templates de funções.
 */

#include <iostream>
#include <string>

using namespace std;

// a e b precisam ser do mesmo tipo
template<class T>
T maximo(T a, T b) {
	return (a > b) ? a : b;
}


// a e b podem ser de tipos diferentes
// mas o retorno é do mesmo tipo de a
template<class T, class U>
T minimo (T a, U b) {
	return (a < b) ? a : b;
}

template<class T>
int getIndice(T *itens, int tamanho, T item) {
	for (int i = 0; i < tamanho; i++) {
		if (itens[i] == item) {
			return i;
		}
	}

	return -1;
}

int main() {

	cout << maximo(10, 45) << endl;
	cout << maximo(10.5, 5.06) << endl;
	// como a e b devem ter o mesmo tipo devemos usar o  <double>
	cout << maximo <double> (5, 5.06) << endl;

	cout << minimo(10, 45) << endl;
	cout << minimo(10.5, 5.06) << endl;
	// como a e b podem ser de tipos diferentes não precisamos usar o <>
	cout << minimo (4.06, 5) << endl;

	int array[] = { 45, 87, 40, 98, -59, 5, 9 };
	cout << "Indice do 98: " << getIndice(array, 7, 98) << endl;
	cout << "Indice do 4: " << getIndice(array, 7, 4) << endl;

	string strings[] = { "Eu", "TU", "ELE", "NOS", "VOS", "ELES" };
	cout << "Indice de \"ELE\": " 
		 // precisamos usar string("ELE") para garantir que "ELE" seja uma string
		 << getIndice(strings, 6, string("ELE")) 
		 << endl;
	
	cout << "Indice de \"ELA\": " 
		 << getIndice(strings, 6, string("ELA")) 
		 << endl;

    getchar();

	return 0;
}	
