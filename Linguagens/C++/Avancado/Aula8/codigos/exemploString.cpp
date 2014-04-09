/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploString.cpp - Mostra utilizar a classe string de C++.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	// também é uma string
	basic_string<char> bs;

	// lê uma linha
	getline(cin, bs);
	cout << "bs = \"" << bs << "\"" << endl;

	// lê uma string
	cin >> s;
	cout << "s = \"" << s << "\"" << endl;

	// troca os conteúdos
	s.swap(bs);
	cout << "Apos a inversao: " << endl
		 << "bs = \"" << bs << "\"" << endl
		 << "s = \"" << s << "\"" << endl;

	int a = s.find('a');

	cout << "Primeiro indice da letra 'a' em s: " << a << endl;
	s[a] = 'A';
	cout << "Apos a modificacao s = \"" << s << "\"" << endl;

	// converte s para uma strig de c
	const char *p = s.data();
	cout << "p = \"" << p << "\""<< endl;


	cout << "Tamanho de bs: " << bs.length() << endl;
	// limpa bs
	bs = "";
	cout << "bs foi limpa? " << (bs.empty() ? "Sim" : "Nao") << endl;

	return 0;
}
