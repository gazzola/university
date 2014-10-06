/*
* C++ 11:
* g++ -std=c++11 -o teste 1424-ProbFacRujiaLiu.cpp -Wall -Wextra
*
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_map> //c++11

using namespace std;



int main(){
 
	
	int n, m, x, k, v;
	bool visitados[1000005];

	while(scanf("%d %d", &n, &m) != EOF){

		unordered_map< int, vector<int> > mvet;
		memset(visitados, false, sizeof(visitados));

		for(int i=1; i<=n; i++){
			scanf("%d", &x);
			mvet[x].push_back(i);
			visitados[x] = true;
		}

		while(m--){

			scanf("%d %d", &k, &v);
			
			if(!visitados[v])
				printf("0\n");
			else if((int) mvet[v].size() < k)
				printf("0\n");
			else
				printf("%d\n", mvet[v][k-1]);

		}

	}


	

	return 0;
}