#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// structs and typedefs
typedef struct triple{
	int first, second, third;

	triple(){}
	triple(int f, int s, int t){
		first = f;
		second = s;
		third = t;
	}
}triple;

typedef long long unsigned int llu;
typedef long unsigned int lu;
typedef long double Lf;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii; //C++11
typedef vector<int> vi;


// functions
template <class T>
void printVector(const vector<T> &vet){
	for(int i=0; i<(int) vet.size(); i++)
		cout << vet[i] << " ";
	cout << endl;
}

template <class T>
void printMatrix(const vector< vector<T> > &mat){
	for(int i=0; i<(int) mat.size(); i++)
		printVector(mat[i]);
	cout << endl;
}





