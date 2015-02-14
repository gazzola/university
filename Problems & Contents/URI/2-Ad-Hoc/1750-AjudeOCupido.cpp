#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;




int main(){
	
	int n, x;
	while(scanf("%d", &n) != EOF){

		vector<int> fusos;
		while(n--){
			scanf("%d", &x);
			fusos.push_back(x);
		}

		sort(fusos.begin(), fusos.end());
		
		n = fusos.size();

		int menor = 0;
		for(int i=0; i<n; i+=2){
			int d = fusos[i+1]-fusos[i];
			int e = 24 - (fusos[i+1]-fusos[i]);
			menor += min(d, e);
		}

		// devido ao fato de 24-|i-j| pode ser menor para j=12 e i=-11
		// devemos testar de modo a junta-los primeiro
		int menor2 = min(abs(fusos[n-1]-fusos[0]), 24-(abs(fusos[n-1]-fusos[0])));
		for(int i=1; i<n-1; i+=2){
			int d = fusos[i+1]-fusos[i];
			int e = 24 - (fusos[i+1]-fusos[i]);
			menor2 += min(d, e);
		}

		menor = min(menor, menor2);

		printf("%d\n", menor);

	}

	
	return 0;
}