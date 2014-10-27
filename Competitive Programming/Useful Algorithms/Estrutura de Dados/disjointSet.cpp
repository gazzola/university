/*
* Referencias:
* http://en.wikipedia.org/wiki/Disjoint-set_data_structure
* http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=disjointDataStructure
*
* Complexidade:
* Criar: 		O(1)
* Buscar: 		O(n)
* Atualizar: 	O(logn)
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
class DisjointSet{

	private:

		vector<int> parent;
		vector<int> rank;	// para balancear
		vector<T> score;

		void link(int id1, int id2);

	public:

		DisjointSet(int size);
		virtual ~DisjointSet();

		void make(int x, T value);
		int find(int x);
		void join(int id1, int id2);
};


template <class T>
DisjointSet<T>::DisjointSet(int size){
	this->parent.resize(size);
	this->rank.resize(size);
	this->score.resize(size);
}

template <class T>
DisjointSet<T>::~DisjointSet(){	
	this->parent.clear();
	this->rank.clear();
	this->score.clear();
}

template <class T>
void DisjointSet<T>::make(int x, T value){
	this->parent[x] = x;
	this->rank[x] = 0;
	this->score[x] = value;
}

template <class T>
int DisjointSet<T>::find(int x){
	if(x != this->parent[x])
		this->parent[x] = this->find(this->parent[x]);
	return this->parent[x];
}

template <class T>
void DisjointSet<T>::link(int x, int y){
	if(this->rank[x] > this->rank[y])
		this->parent[y] = x;
	else{
		this->parent[x] = y;
		if(this->rank[x] == this->rank[y])
			this->rank[x]++;
	}

	int s = this->score[x]+this->score[y];
	this->score[x] = s;
	this->score[y] = s;
}

template <class T>
void DisjointSet<T>::join(int x, int y){
	this->link(x, y);
}



int main(){

	DisjointSet<int> *st = new DisjointSet<int>(MAX);
	
	for(int i=1; i<=MAX; i++)
		st->make(i, 1);

	st->join(1, 2);
	st->join(1, 5);
	st->join(1, 6);
	st->join(1, 8);

	st->join(3, 4);


	cout << st->find(2) << endl;
	cout << st->find(5) << endl;
	cout << st->find(3) << endl;
	cout << st->find(7) << endl;


	delete st;

	return 0;
}