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
class FenwickTree2D{

	public:

		vector<vector<T>> tree;
		int max_x, max_y;

		FenwickTree2D(int max_x, int max_y);
		virtual ~FenwickTree2D();

		void reset(T val);

		void update(int x, int y, T val);
		T read(int x, int y);
		T range(int x1, int y1, int x2, int y2);
};


template <class T>
FenwickTree2D<T>::FenwickTree2D(int max_x, int max_y){
	
	max_x++;
	max_y++;

	this->tree.resize(max_x);
	for(int i=0; i<max_x; i++)
		this->tree[i].resize(max_y);
	
	this->max_x = max_x;
	this->max_y = max_y;
}

template <class T>
FenwickTree2D<T>::~FenwickTree2D(){	
	for(int i=0; i<this->max_x; i++)
		this->tree.clear();
}


template <class T>
void FenwickTree2D<T>::reset(T val){
	for(int i=1; i<this->max_x; i++)
		for(int j=2; j<this->max_y; j++)
			this->tree[i][j] = val;
}


template <class T>
void FenwickTree2D<T>::update(int x, int y, T val){
	while (x <= this->max_x){
		int y1 = y;
		while(y1 <= this->max_y){
			this->tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}


template <class T>
T FenwickTree2D<T>::read(int x, int y){
	int sum = 0;
	while (x > 0){
		int y1 = y;
		while(y1 > 0){
			sum += this->tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

template <class T>
T FenwickTree2D<T>::range(int x1, int y1, int x2, int y2){
	
	int x_min = min(x1, x2);
	int x_max = max(x1, x2);
	int y_min = min(y1, y2);
	int y_max = max(y1, y2);
	 
	int s = this->read(x_max, y_max);
	s -= this->read(x_max, y_min-1);
	s -= this->read(x_min-1, y_max);
	s += this->read(x_min-1, y_min-1);
 
	return s;
}





int main(){

	FenwickTree2D<int> *st = new FenwickTree2D<int>(2, 2);
	st->reset(0);

	st->update(2, 2, 5);
	st->update(2, 1, 9);
	st->update(1, 1, 2);
	st->update(1, 2, 5);

	for(int i=1; i<=2; i++){
		for(int j=1; j<=2; j++)
			cout << st->tree[i][j] << " ";
		cout << endl;
	}


	cout << endl;
	cout << st->range(2, 1, 2, 2) << endl;

	delete st;

	return 0;
}