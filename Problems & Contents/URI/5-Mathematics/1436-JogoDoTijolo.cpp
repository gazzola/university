#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	int t, n, x;

	scanf("%d", &t);
	for(int i=1; i<=t; i++){
			
		scanf("%d", &n);
		vector<int> vet;

		while(n--){
			scanf("%d", &x);
			vet.push_back(x);
		}

		sort(vet.begin(), vet.end());
		
		n = vet.size();
		x = (n%2 == 0) ? n/2 - 1 : n/2;
		printf("Case %d: %d\n", i, vet[x]);
	}


	return 0;
}