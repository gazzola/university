#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;

const llu LIM = 1000005;
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


llu acharMultiplo(int n){

	int j = 0;
	llu k, i, max = n;
	llu menor = 1;

	while(n%2 == 0){
		j++;
		n /= 2;
	}

	if(j%2 != 0)
		menor = 2;

	if(n == 1)
		return menor;

	for(i=1; i<prime_cont; i++){
		
		k = prime[i];
		if(k*k > max)
			break;

		j = 0;
		while(n % k == 0){
			j++;	
			n /= k;
		}
		
		if(j%2 != 0)
			menor *= k;

		if(n == 1)
			break;
	}


	if(n > 1)
		menor *= n;

	return menor;
}


bool ehQuadradoPerfeito(int n){
	int h = n & 0xF;  // h is the last hex "digit"
	if (h > 9)
		return false;
		// Use lazy evaluation to jump out of the if statement as soon as possible
		if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8){
		int t = (int) floor( sqrt((double) n) + 0.5 );
		return t*t == n;
	}
	return false;
}


int main(){
	
	crivo();
	int t, n, k=1;
	llu i;

	scanf("%d", &t);
	while(t--){

		scanf("%d", &n);
		printf("Caso #%d: ", k++);

		if(ehQuadradoPerfeito(n)){
			printf("%d\n", n);
			continue;
		}

		i = acharMultiplo(n);
		if(i == 1)
			printf("%llu\n", (llu)n*n);
		else
			printf("%llu\n", i*n);

		
	}

	return 0;
}