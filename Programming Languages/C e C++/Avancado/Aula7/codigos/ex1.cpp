#include <iostream>
#include <algorithm>
#include "ex1.h"

using namespace std;
using namespace ex1;


bool descendOrder(int i, int j){
	return i > j; 
}

bool ascendOrder(int i, int j){
	return i < j; 
}


int main(int argc, char const *argv[]){
	
	Vetor<int> v(10);

	try{
		v.inserir(1);
		v.inserir(4);
		v.inserir(8);
		v.inserir(3);
		v.inserir(11);
		v.inserir(2);
		v.inserir(7);
		v.inserir(15);
		v.inserir(19);
		v.inserir(9);
	}
	catch(const char *s){
		cout << s << endl; 
	}

	v.mostrar();
	
	cout << "index do 11: " << v.getIndice(11) << endl;

	string s1 = (v.contem(11)) ? "11: yes" : "11: no";
	string s2 = (v.contem(66)) ? "66: yes" : "66: no";
	cout << s1 << endl;
	cout << s2 << endl;


	try{
		v.remover(5);
		v.remover(7);
		cout << v.contem(7) << endl;
		v.inserir(7);
	}
	catch(const char *s){
		cout << s << endl; 
	}

	
	v.remover(11);
	v.remover(15);
	v.remover(19);
	v.mostrar();


	v.ordenar(ascendOrder);
	v.mostrar();
	v.ordenar(descendOrder);
	v.mostrar();

	cout << endl;

	return 0;
}