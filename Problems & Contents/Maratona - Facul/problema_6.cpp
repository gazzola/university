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



void primeFactors(llu n){


	bool ok = false;
	while(n%2 == 0){
		if(ok)
			printf("x");
		printf("2");
		ok = true;
		n /= 2;
	}
	

	llu max = n;
	for(llu i=1; i<prime_cont; i++){
		
		llu k = prime[i];
		if(k > max)
			break;

		while(n % k == 0){
			if(ok)
				printf("x");
			printf("%llu", k);
			n /= k;
			ok = true;
		}
		
		if(n <= 1)
			break;
	}


}


int main(){

	crivo();

	llu n, res;
	while(scanf("%llu", &n) != EOF){
		primeFactors(n);
		printf("\n");
	}


	return 0;
}