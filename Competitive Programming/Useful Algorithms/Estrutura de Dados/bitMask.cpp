/*
* Complexidade:
* Inserir: 		O(k)
* Retirar: 		O(k)
* Existe:		O(k)
* k = qtd. de bits do bitmask (64b)
*
* Memoria usada: 
* O(1) para bitmask
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;
typedef long long unsigned int llu;


template <class T>
class BitMask{

	private:
		// T bitmask;
		char base;
		int size;

		int getIndex(int x);
		T getX(int x);
		vector<T> bitmasks;

	public:
		BitMask(int ammount);
		BitMask(int minElement, int maxElement);
		virtual ~BitMask();

		void set(vector<T> bitmasks);
		void set(int i, T bitmask);

		vector<T> get(); 
		T get(int i);
		
		void setBase(char c);
		
		bool exist(int x);
		bool empty();
		int length();
		
		void clear();
		void add(int x);
		void remove(int x);
		void toggle(int x);
		void reverse();
		
		void print();
		

};

// constructor and destructor

template <class T>
BitMask<T>::BitMask(int minElement, int maxElement){
	this->size = (maxElement - minElement)/(8 * sizeof(T)) + 1;
	this->bitmasks.resize(this->size);
	this->clear();
	this->base = 0;
}


template <class T>
BitMask<T>::BitMask(int ammount){
	this->size = ammount/(8 * sizeof(T)) + 1;
	this->bitmasks.resize(this->size);
	this->clear();
	this->base = 0;
}


template <class T>
BitMask<T>::~BitMask(){
	this->bitmasks.clear();
}




// maintaince

template <class T>
void BitMask<T>::setBase(char c){
	this->base = c;
}


template <class T>
int BitMask<T>::getIndex(int x){
	int k = 8 * sizeof(T);
	k = (x - this->base)/k;
	if(k >= this->size)
		throw "limit bound exception!";
	return k;
}

template <class T>
T BitMask<T>::getX(int x){
	T um = 1;
	return (um << (x - this->base));
}




// setters and getters

template <class T>
void BitMask<T>::set(vector<T> bitmasks){
	this->bitmasks = bitmasks;
}


template <class T>
void BitMask<T>::set(int i, T bitmask){
	this->bitmasks[i] = bitmask;
}


template <class T>
vector<T> BitMask<T>::get(){
	return this->bitmasks;
}


template <class T>
T BitMask<T>::get(int i){
	return this->bitmasks[i];
}





// helpers

template <class T>
void BitMask<T>::clear(){
	for(int i=0; i<this->size; i++)
		this->bitmasks[i] = 0LL;
}


template <class T>
bool BitMask<T>::empty(){
	for(int i=0; i<this->size; i++)
		if(this->bitmasks[i] > 0)
			return false;
	return true;
}

template <class T>
int BitMask<T>::length(){
	int n = 0;
	T aux;

	for(int i=0; i<this->size; i++){
		aux = this->bitmasks[i];
		while(aux){
			++n;
			aux = (aux - 1) & n;
		}
	}

	return n;
}




// basics

template <class T>
bool BitMask<T>::exist(int x){
	int i = this->getIndex(x);
	T y = this->getX(x);
	return ((this->bitmasks[i] & y) == y);
}

template <class T>
void BitMask<T>::add(int x){
	int i = this->getIndex(x);
	this->bitmasks[i] |= this->getX(x);
}


template <class T>
void BitMask<T>::remove(int x){
	int i = this->getIndex(x);
	this->bitmasks[i] &= ~(this->getX(x));
}

template <class T>
void BitMask<T>::toggle(int x){
	int i = this->getIndex(x);
	this->bitmasks[i] ^= this->getX(x);
}

template <class T>
void BitMask<T>::reverse(){
	for(int i=0; i<this->size; i++)
		this->bitmasks[i] = ~(this->bitmasks[i]);
}




// print

template <class T>
void BitMask<T>::print(){
	
	T aux;
	int i, k;
	int t = 8*sizeof(T);

	for(i=0; i<this->size; i++){
		aux = this->bitmasks[i];
		k = 0;
		while(aux > 0){
			if((aux & 1) == 1)
				cout << (char) (this->base + t*i + k);
			aux >>= 1;
			k++;
		}
	}

	cout << endl;
}



int main(){

	BitMask<llu> *bm = new BitMask<llu>('a', 'z');
	bm->setBase('a');

	bm->add('m');
	bm->add('a');
	bm->add('r');
	bm->add('c');
	bm->add('o');
	bm->add('s');
	bm->print();

	bm->remove('a');
	bm->print();

	bm->toggle('m');
	bm->print();

	bm->toggle('m');
	cout << "m:" << bm->exist('m') << endl;

	bm->reverse();
	bm->print();

	delete bm;

	return 0;
}
