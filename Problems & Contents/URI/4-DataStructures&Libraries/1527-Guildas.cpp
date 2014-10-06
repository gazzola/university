/*
* union-set or union-find structure
* mais infos: 
* http://www.fernandolobo.info/aed-II/teoricas/a23.print.pdf
* http://www.ic.unicamp.br/~zanoni/mo637/aulas/conjuntosDisjuntos.pdf
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int parent[100001];
int ranks[100001];
int score[100001];

void makeSet(int x, int p){
	parent[x] = x;	// primeiro elemento corr. ao proprio cjto
	ranks[x] = 0; // para deixar melhor balanceada
	score[x] = p;
}

// visualizar arvore para entender melhor
int findSet(int x){
	if(x != parent[x])
		parent[x] = findSet(parent[x]);
	return parent[x];
}

void linkSet(int x, int y){
	if(ranks[x] > ranks[y])
		parent[y] = x;		
	else{
		parent[x] = y;
		if(ranks[x] == ranks[y])
			ranks[x] += 1;
	}

	int s = score[x]+score[y];
	score[x] = score[y] = s;
}


void unionSet(int x, int y){
	linkSet(findSet(x), findSet(y));
}



int main(){
 
	int n, m, p, q, a, b;
	int r = 1;	// player's number

	while(scanf("%d %d", &n, &m) and n > 0){

		

		for(int i=1; i<=n; i++){
			scanf("%d", &p);
			makeSet(i, p);
		}


		int win = 0;
		for(int i=0; i<m; i++){

			scanf("%d %d %d", &q, &a, &b);
			if(q == 1){
				unionSet(a, b);
			}
			else{

				int setA = findSet(a);
				int setB = findSet(b);
				int setR = findSet(r);
				if(setA == setR and score[setA] > score[setB])
					win++;
				else if(setB == setR and score[setB] > score[setA])
					win++;

			}
		}

		printf("%d\n", win);

	}
	

 
	return 0;
}