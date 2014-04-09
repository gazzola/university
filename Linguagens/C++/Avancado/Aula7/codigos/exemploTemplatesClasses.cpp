/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploTemplatesClasse.cpp - Mostra implementar templates de classes.
 */

#include <iostream>

using namespace std;

template <class T>
class Stack {
private:
	T *elements;
	int nextIndex; // o topo da pilha + 1
	int size;

public:
	Stack(int size);

	void push(T &element);

	T pop();

	~Stack();
};

template <class T>
Stack<T>::Stack(int size) {
	this->size = size;
	this->elements = new T[size];
	this->nextIndex = size - 1;
}

template <class T>
void Stack<T>::push(T &element) {
	if (this->nextIndex != -1) {
		this->elements[this->nextIndex] = element;
		this->nextIndex--;
	}
}

template <class T>
T Stack<T>::pop() {
	T ret;
	if (this->nextIndex < (this->size - 1)) {
		ret = elements[this->nextIndex+1];
        this->nextIndex++;
	}

	return ret;
}

template <class T>
Stack<T>::~Stack() {
	delete [] this->elements;
}

int main() {
	Stack<int> sInt(10);

	for (int i = 0; i < 10; i++) {
		sInt.push(i);
	}

	for (int i = 0; i < 10; i++) {
		cout << sInt.pop() << endl;
	}

	Stack<double> sDouble(10);
	double base = 5.50;

	for (int i = 0; i < 10; i++) {
		sDouble.push(base);
		base = base + 10.0;
	}

	for (int i = 0; i < 10; i++) {
		cout << sDouble.pop() << endl;
	}

    getchar();

	return 0;
}
