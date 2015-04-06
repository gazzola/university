#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long unsigned int llu;

// 10^6 nth prime in wolfram alpha
const llu LIM = 15485864;
bool isprime[LIM];
llu prime[LIM];

llu prime_cont = 1;

void crivo(){
	prime[0] = 2;
	memset(isprime, true, sizeof(isprime));

	for(llu i=3; i<=LIM; i+=2){
		if(isprime[i]){
			prime[prime_cont++] = i;
			for(llu j=i*i; j<=LIM; j+=i) 
				isprime[j] = false;
		}
	}
}





int main(){


	crivo();
	

	int t, n, x;

	
	scanf("%d", &t);
	while(t--){

		bool achouUm = false;

		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &x);

			if(x <= LIM){
				isprime[x] = false;
				if(x == 1)
					achouUm = true;
			}
		}


		if(!achouUm){
			printf("0\n");
			continue;
		}
		

		llu res = LIM;
		for(int i=0; i<n; i++){
			if(isprime[prime[i]]){
				res = prime[i];
				break;
			}
			else
				isprime[prime[i]] = true;
		}


		printf("%llu\n", res-1);

	}



	return 0;
}