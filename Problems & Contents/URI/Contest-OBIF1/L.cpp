#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;
typedef long long signed int lls;


const llu LIM = 10000000;
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
	
	prime[0] = 2;
}



// formula simples para calcular combinacoes
llu combinacoes(llu n, llu k) {
	
	llu r = 1;
	for (llu d=1; d<=k; ++d) {
		r = r*n;
		n--;
		r = r/d;
	}
	
	// printf("%llu\n", r);
	return r;
}



int numPrimosBrute(int a, int b){

	int x, y;
	x = min(a, b);
	y = max(a, b);

	int n = (x == 2) ? 1 : 0;
	x += (x%2 == 0) ? 1 : 0;

	for(int i=x; i<=y; i+=2)
		if(isprime[i])
			n++;

	return n;
}



int main(){

	crivo();

	int a, b;
	scanf("%d %d", &a, &b);

	if(a == b)
		printf("?\n");
	else{

		int k = abs(a-b);
		int n = numPrimosBrute(a, b);
		// printf("%d\n", n);
		n = n+k-1;


		// http://math.stackexchange.com/questions/11002/cn-p-even-or-odd
		// llu x = combinacoes(n+k-1, k);
		if((k & (n-k)))
			printf("Bob\n");
		else
			printf("Alice\n");

	}

	return 0;
}
