#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;


int hashFunction(int x, int m){
	return x % m;
}




int main(){

	int t, m, c, x, p;
	bool first = true;

	scanf("%d", &t);

	while(t--){


		deque<int> tab[101];
		scanf("%d %d", &m, &c);

		while(c--){
			scanf("%d", &x);
			p = hashFunction(x, m);
			tab[p].push_back(x);
		}


		if(!first)
			printf("\n");

		for(int i=0; i<m; i++){
			printf("%d -> ", i);
			for(int j=0; j<(int) tab[i].size(); j++)
				printf("%d -> ", tab[i][j]);
			printf("\\\n");
		}

		first = false;
	}
	

		
	return 0;
}