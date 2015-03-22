#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long unsigned int llu;

typedef pair<int, llu> il;


struct lessAdj{
	bool operator()(const il &lhs, const il &rhs) const{
		return (lhs.second < rhs.second);
	}
};


int main(){
		
		
	int t, n, k, s;
	llu vet[1000001];

	scanf("%d", &t);
	while(t--){


		priority_queue<il, vector<il>, lessAdj > fila;

		scanf("%d %d %d", &n, &k, &s);
		
		vet[0] = s;
		for(int i=1; i<n; ++i)
			vet[i] = (1LL*vet[i-1]*1103515245 + 12345) % (2147483648LL);



		for(int i=0; i<k; i++)
			fila.push(il(i, vet[i]));
		
		
		llu soma = fila.top().second;
		for(int i=1; i<=n-k; i++){
			fila.push(il(i+k-1, vet[i+k-1]));
			while(fila.top().first < i)
				fila.pop();
			soma += fila.top().second;
		}

		cout << soma << endl;
	}

	return 0;
}