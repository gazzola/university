#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>		// vector and pair
#include <algorithm>	// sort

using namespace std;

typedef pair<int, int> ii;
const int INF = 9999;
const int MAX = 201; 

// que tiverem menor id e menor consumo
bool orderBy(const ii &i, const ii &j){
	return i.second < j.second;
}

void printVector(const vector<ii> &v){
	for(int i=0; i<(int) v.size(); i++)
		printf("(%d,%d)  ", v[i].first, v[i].second);
 	printf("\n");
}


int main(){
	
	int n, a, b, count=1;
	vector<ii> cidades(MAX);
	
	while(scanf("%d", &n) and n != 0){

		for(int i=0; i<MAX; i++){
			cidades[i].first = 0;
			cidades[i].second = INF;
		}

		int somam=0, somac=0;
		for(int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			cidades[b/a] = ii(cidades[b/a].first+a, b/a);
			somac += b;
			somam += a;
		}

		double media = floor(100.0*somac/somam)/100.0;

		if(count > 1)
			printf("\n");

		printf("Cidade# %d:\n", count);


		sort(cidades.begin(), cidades.end(), orderBy);
		//printVector(cidades);
		
		
		printf("%d-%d", cidades[0].first, cidades[0].second);
		for(int i=1; i<(int)cidades.size(); i++){
			
			if(cidades[i].first == 0)
				break;

			printf(" %d-%d", cidades[i].first, cidades[i].second);
		}

		printf("\nConsumo medio: %.2lf m3.\n", media);

		count++;
	}

	return 0;
}