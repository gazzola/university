#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


typedef long long unsigned int llu;

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
	
	int n, x;
	char c;

	scanf("%d", &n);
	
	int vals[n];
	FenwickTree<int> *st = new FenwickTree<int>(n);

	for(int i=1; i<=n; i++){
		scanf("%d", &x);
		st->update(i, x);
		vals[i] = x;
	}

	while(scanf("\n%c %d", &c, &x) != EOF){
		if(c == 'a')
			st->update(x, - vals[x]);
		else
			printf("%d\n", st->range(1, x-1));
	}

}
