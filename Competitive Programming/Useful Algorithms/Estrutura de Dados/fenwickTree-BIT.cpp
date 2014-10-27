/*
* Referencias:
* http://www.algorithmist.com/index.php/Fenwick_tree
* http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
*
* Complexidade:
* Inserir: 		O(logn)
* Buscar: 		O(logn)
* Atualizar: 	O(logn)
* Vazio:		O(1)
*
* Memoria usada: 
* O(n) para arvore
* O(1) para auxiliar
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;
const int MAX = 8;



template <class T>
class FenwickTree{

	public:

		T *tree;
		int size;

		FenwickTree(int size);
		virtual ~FenwickTree();

		void reset(T val);

		void update(int id, T val);
		T read(int id);
		T range(int id1, int id2);
};


template <class T>
FenwickTree<T>::FenwickTree(int size){
	size++;	//indexada em 1
	this->tree = (T*) malloc (size * sizeof(T));
	this->size = size;
}

template <class T>
FenwickTree<T>::~FenwickTree(){
	delete this->tree;
}




template <class T>
void FenwickTree<T>::reset(T val){
	memset(this->tree, val, sizeof(T)*this->size);
}


template <class T>
void FenwickTree<T>::update(int id, T val){
	while(id <= this->size){
		this->tree[id] += val;
		id += (id & -id);
	}
}


template <class T>
T FenwickTree<T>::read(int id){
	int sum = 0;
	while(id > 0){
		sum += this->tree[id];
		id -= (id & -id);
	}
	return sum;
}

template <class T>
T FenwickTree<T>::range(int id1, int id2){
	return this->read(id2) - this->read(id1-1);
}





int main(){

	FenwickTree<int> *st = new FenwickTree<int>(6);
	st->update(1, 1);
	st->update(2, 3);
	st->update(3, 5);
	st->update(4, 7);
	st->update(5, 9);
	st->update(6, 11);
		
	for(int i=1; i<=6; i++)
		cout << st->tree[i] << " ";

	cout << endl;
	cout << st->range(1, 4) << endl;

	delete st;

	return 0;
}