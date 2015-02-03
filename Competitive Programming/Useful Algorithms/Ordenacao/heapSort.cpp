/*
* Complexidade:
* Pior Caso: 	O(nlgn)
* Caso medio: 	O(nlgn)
* Melhor Caso:	O(nlgn)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*
* Estavel: Nao
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <tuple> // C++11
#include "../utils.h"

using namespace std;
const int MAX = 8;
const int INF = 999999;

// heap-max
template <class T>
class Heap{

	private:

		vector<T> heap;
		bool builded;
		int tam;

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
		vector<T> getVector();
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
int Heap<T>::size(){
	return this->tam;
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

int main(){

	srand(time(NULL));
	Heap<int> *h = new Heap<int>(10);
	for(int i=0; i<MAX; i++)
		h->insert((rand()%MAX));

	printVector(h->getVector());

	h->sort();
	printVector(h->getVector());

	return 0;
}