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
* Politica: FIFO
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
class Queue{
	
	private:
		T *stack;
		int ini, fim;
		int maxSize;

	public:

		Queue(int n);
		virtual ~Queue(){};
		void push(T x);
		T front();
		void pop();
		T extract();
		void update(T x, int i);
		bool empty();
		int size();
};

template <class T>
Queue<T>::Queue(int n){
	this->stack = (T*) calloc(n, sizeof(T));
	this->ini = this->fim = 0;
	this->maxSize = n;
}


template <class T>
void Queue<T>::push(T x){
	if(this->size() == this->maxSize)
		throw "Overflow!";
	this->stack[this->fim++] = x;
}

template <class T>
T Queue<T>::front(){
	return this->stack[this->ini];
}

template <class T>
void Queue<T>::pop(){
	if(this->size() == 0)
		throw "Underflow!";
	this->ini++;
}

template <class T>
T Queue<T>::extract(){
	int temp = this->front();
	this->pop();
	return temp;
}

template <class T>
void Queue<T>::update(T x, int i){
	if(i < this->ini or i >= this->fim)
		throw "Index error!";
	this->stack[i] = x;
}

template <class T>
bool Queue<T>::empty(){
	return (this->size() == 0);
}

template <class T>
int Queue<T>::size(){
	return (this->fim - this->ini);
}


int main(){

	srand(time(NULL));
	Queue<int> s(MAX);


	for(int i=0; i<MAX; i++){
		int x = rand()%MAX;
		s.push(x);
	}

	while(!s.empty())
		cout << s.extract() << endl;

	return 0;
}