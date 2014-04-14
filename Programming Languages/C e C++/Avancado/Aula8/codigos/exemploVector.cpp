/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploVector.cpp - Mostra como utilizar a classe std::vector.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void imprimirVetor(const vector<T> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " "; // acesso através do operador []

	}

	cout << endl;
}

int main() {
	vector <int> v;

	cout << "O tamanho inicial de v e: " << v.size() << endl // imprime 0
		 << "A capacidade inicial de v e: " << v.capacity() << endl; // imprime 0

	// insere no final do vetor
	v.push_back(10);
	v.push_back(15);
	v.push_back(4);
	v.push_back(76);
	v.push_back(-1);

	cout << "O tamanho atual de v e: " << v.size() << endl // imprime 5
		 << "A capacidade atual de v e: " << v.capacity() << endl; // imprime 6

	cout << "Ordem atual: ";
	imprimirVetor(v);

	// ordena o vetor
	sort(v.begin(), v.end());
	cout << "Ordem atual: ";
	imprimirVetor(v);

	// reverte o vetor
	reverse(v.begin(), v.end());
	cout << "Ordem atual: ";
	imprimirVetor(v);

	// compila, roda e não levanta exceção:
	// v[100] = 40;

// este trecho só compila no visual studio
//	try {
//		v.at(2) = 5;
//		v.at(100) = 45; // forma segura
//		v.at(4) = 5;
//	} catch (out_of_range &e) {
//		cout << "Erro : " << e.what() << endl;
//	}

	cout << "Ordem atual: ";
	imprimirVetor(v);

	cout << "O vetor esta vazio? " << (v.empty() ? "Sim" : "Nao") << endl;
	// limpa o vetor
	v.clear();
	cout << "O vetor esta vazio? " << (v.empty() ? "Sim" : "Nao") << endl;


		
	return 0;
}
