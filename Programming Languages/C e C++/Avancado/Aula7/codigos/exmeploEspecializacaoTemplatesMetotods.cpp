/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploEspecializacaoTemplatesMetodos.cpp - Mostra como especializar 
 *                                             métodos de classes templates
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Stack {
private:
	T *elements;
	int nextIndex;
	int size;

public:
	Stack(int size);
	
	void push(T &element);

	T pop();

	bool isEmpty(){ return this->nextIndex == 0; };

	~Stack();
};

template <class T>
Stack<T>::Stack(int size) {
	this->size = size;
	this->elements = new T[size];
	this->nextIndex = 0;
}

template <class T>
void Stack<T>::push(T &element) {
	if (this->nextIndex != this->size) {
		this->elements[this->nextIndex] = element;
		this->nextIndex++;
	}
}

// não precisamos mais do template <class T>
void Stack<char*>::push(char* &element) {
	if (this->nextIndex != this->size) {
		this->elements[this->nextIndex] = new char[strlen(element) + 1];
		strcpy(this->elements[this->nextIndex], element);
		this->nextIndex++;
    }
}


template <class T>
T Stack<T>::pop() {
	T ret;
	if (this->nextIndex > 0) {
		this->nextIndex--;
		ret = elements[this->nextIndex];
	}

	return ret;
}

template <class T>
Stack<T>::~Stack() {
	delete [] this->elements;
}

Stack<char *>::~Stack() {
    for (int i = 0; i < this->size; i++) {
        delete [] elements[i];
    }

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

	Stack<char *> sChar(10);
	char *string = new char[50];
	strcpy(string, "CIn");
	sChar.push(string);
	strcpy(string, "UFPE");
	sChar.push(string);
	strcpy(string, "C++");
	sChar.push(string);

	while (!sChar.isEmpty()) {
		char *element = sChar.pop();
		cout << element << endl;
		delete [] element;
	}


	return 0;
}	
