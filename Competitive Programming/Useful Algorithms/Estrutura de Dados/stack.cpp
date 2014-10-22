/*
* Complexidade:
* Inserir: 		O(1)
* Retirar: 		O(1)
* Atualizar: 	O(1) // nao original
* Vazio:		O(1)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*
* Politica: LIFO
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;

template <class T>
class Stack{
	
	private:
		T *stack;
		int tam;
		int maxSize;

	public:

		Stack(int n);
		virtual ~Stack(){};
		void push(T x);
		T top();
		void pop();
		T extract();
		void update(T x, int i);
		bool empty();
		int size();
};

template <class T>
Stack<T>::Stack(int n){
	this->stack = (T*) calloc(n, sizeof(T));
	this->tam = 0;
	this->maxSize = n;
}


template <class T>
void Stack<T>::push(T x){
	if(this->tam == this->maxSize)
		throw "Overflow!";
	this->stack[this->tam++] = x;
}

template <class T>
T Stack<T>::top(){
	return this->stack[this->tam-1];
}

template <class T>
void Stack<T>::pop(){
	if(this->tam == 0)
		throw "Underflow!";
	this->tam--;
}

template <class T>
T Stack<T>::extract(){
	int temp = this->top();
	this->pop();
	return temp;
}

template <class T>
void Stack<T>::update(T x, int i){
	if(i < 0 or i >= this->tam)
		throw "Index error!";
	this->stack[i] = x;
}

template <class T>
bool Stack<T>::empty(){
	return (this->tam == 0);
}

template <class T>
int Stack<T>::size(){
	return this->tam;
}


int main(){

	srand(time(NULL));
	Stack<int> s(MAX);


	for(int i=0; i<MAX; i++){
		int x = rand()%MAX;
		s.push(x);
	}

	while(!s.empty())
		cout << s.extract() << endl;

	return 0;
}