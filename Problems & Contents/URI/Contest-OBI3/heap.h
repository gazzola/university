/*
* Complexidade:
* Inserir: 		O(lgn)
* Retirar: 		O(lgn)
* Atualizar: 	O(1) // nao original
* Vazio:		O(1)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;


// heap-max
template <class T>
class Heap{

	private:

		vector<T> heap;
		bool builded;
		int tam;
		const int INF = 9999999;


		int getParent(int i);
		int getLeftSon(int i);
		int getRightSon(int i);
		void increaseKey(int i, T x);

	public:

		Heap(int n);
		virtual ~Heap(){};
		void heapify(int i);
		void build(vector<T> &vet);
		void insert(T x);
		void sort();
		T extractMax();
		T top();
		int size();
		bool empty();
		vector<T> getVector();
		void updateTopKey(T x);
};


template <class T>
Heap<T>::Heap(int n){
	this->heap.resize(n);
	this->tam = 0;
	this->builded = false;
}



template <class T>
int Heap<T>::getParent(int i){
	return (i-1)/2;
}

template <class T>
int Heap<T>::getLeftSon(int i){
	return (i*2)+1;
}

template <class T>
int Heap<T>::getRightSon(int i){
	return (i*2)+2;
}


template <class T>
T Heap<T>::top(){
	return this->heap[0];
}

template <class T>
void Heap<T>::updateTopKey(T x){
	if(x < this->heap[0])
		throw "Error: new key is lower than the current key";
	this->heap[0] = x;
}


template <class T>
int Heap<T>::size(){
	return this->tam;
}

template <class T>
bool Heap<T>::empty(){
	return this->tam > 0;
}


template <class T>
vector<T> Heap<T>::getVector(){
	return this->heap;
}


template <class T>
void Heap<T>::increaseKey(int i, T x){
	if(x < this->heap[i])
		throw "Error: new key is lower than the current key";

	this->heap[i] = x;

	while(i > 0 and this->heap[this->getParent(i)] < this->heap[i]){
		swap(this->heap[i], this->heap[this->getParent(i)]);
		i = this->getParent(i);
	}
}

template <class T>
void Heap<T>::insert(T x){
	
	if(this->size() == this->heap.size())
		throw "Maximum elements alread reached";

	this->tam++;
	this->heap[this->size()-1] = -INF;
	this->increaseKey(this->size()-1, x);
}

template <class T>
T Heap<T>::extractMax(){
	if(this->size() < 1)
		throw "Error: empty heap!";

	int maior = this->top();
	this->heap[0] = this->heap[this->size()-1];
	this->tam--;
	this->heapify(0);

	return maior;
}

template <class T>
void Heap<T>::heapify(int i){
	int l = this->getLeftSon(i);
	int r = this->getRightSon(i);
	int maior = i;

	if(l < this->size() and this->heap[l] > this->heap[i])
		maior = l;

	if(r < this->size() and this->heap[r] > this->heap[maior])
		maior = r;

	if(maior != i){
		swap(this->heap[i], this->heap[maior]);
		heapify(maior);
	}
}

template <class T>
void Heap<T>::build(vector<T> &vet){
	this->heap = vet;
	this->tam = vet.size();
	this->builded = true;

	for(int i=(this->size()-1)/2; i>=0; i--)
		this->heapify(i);
}

template <class T>
void Heap<T>::sort(){
	for(int i=this->size()-1; i>=1; i--){
		swap(this->heap[0], this->heap[i]);
		this->tam--;
		this->heapify(0);
	}
	this->tam = this->heap.size();
}
