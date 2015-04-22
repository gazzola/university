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
#include <vector>

using namespace std;

template <class T>
class BitMask{

	private:
		T bitmask;
		char base;
		T getX(int x);

	public:

		BitMask();
		virtual ~BitMask();

		void clear();
		void setBase(char c);
		void add(int x);
		bool exist(int x);
		bool empty();
		void remove(int x);
		void toggle(int x);
		void reverse();
		void print();
		
};


template <class T>
BitMask<T>::BitMask(){
	this->clear();
}

template <class T>
BitMask<T>::~BitMask(){
	this->clear();
}

template <class T>
void BitMask<T>::clear(){
	this->bitmask = 0;
}

template <class T>
void BitMask<T>::setBase(char c){
	this->base = c;
}

template <class T>
T BitMask<T>::getX(int x){
	T um = 1;
	return (um << (x - this->base));
}

template <class T>
void BitMask<T>::add(int x){
	this->bitmask |= this->getX(x);
}

template <class T>
bool BitMask<T>::exist(int x){
	long long unsigned int y = this->getX(x);
	return ((this->bitmask & y) == y);
}

template <class T>
void BitMask<T>::remove(int x){
	this->bitmask &= ~(this->getX(x));
}

template <class T>
void BitMask<T>::toggle(int x){
	this->bitmask ^= this->getX(x);
}

template <class T>
void BitMask<T>::print(){
	long long unsigned int aux = this->bitmask;
	int i = 0;
	while(aux > 0){
		if((aux & 1) == 1)
			cout << (char) (this->base+i);
		aux >>= 1;
		i++;
	}
	cout << endl;
}


typedef long long unsigned int llu;

int main(){


	BitMask<llu> *bm = new BitMask<llu>();
	
	bm->setBase('a');
	
	bm->add('m');
	bm->add('a');
	bm->add('r');
	bm->add('c');
	bm->add('o');
	bm->add('s');
	bm->add('k');
	bm->print();

	bm->remove('k');
	bm->print();

	bm->toggle('m');
	bm->print();

	cout << bm->exist('m') << endl;



	delete bm;


	return 0;
}
