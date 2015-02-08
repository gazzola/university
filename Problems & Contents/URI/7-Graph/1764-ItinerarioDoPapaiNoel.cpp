#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



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






// structs and typedefs
typedef struct triple{
	int first, second, third;

	triple(){}
	triple(int f, int s, int t){
		first = f;
		second = s;
		third = t;
	}

	bool operator < (const triple &t) const{
		return this->third < t.third;
	}

}triple;




typedef pair<int, int> ii;


long int kruskal(int m, vector<triple> &arestas){

	DisjointSet<int> *ds = new DisjointSet<int>(m);
	// vector<ii> result;
	long int t = 0;

	for(int i=0; i<m; i++)
		ds->make(i, 0);

	sort(arestas.begin(), arestas.end());

	int e = 0, i = 0;
	while(e < m-1){

		int u = ds->find(arestas[i].first);
		int v = ds->find(arestas[i].second);

		if(ds->find(u) != ds->find(v)){
			t += arestas[i].third;
			// result.push_back(ii(u, v));
			ds->join(u, v);
			e++;
		}

		i++;
	}

	return t;
}




int main(){
	
	
	int m, n, x, y, z;
	while(scanf("%d %d", &m, &n) and m > 0){

		vector<triple> arestas;

		while(n--){
			scanf("%d %d %d", &x, &y, &z);
			arestas.push_back(triple(x, y, z));
		}

		printf("%ld\n", kruskal(m, arestas));
	}




	return 0;
}