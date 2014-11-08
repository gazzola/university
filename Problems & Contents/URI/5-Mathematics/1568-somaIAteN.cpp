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



llu primeFactors(llu n){

	if(n <= 2)
		return 1;

	while(n%2 == 0)
		n /= 2;
	
	llu max = n;
	llu total = 1;

	for(llu i=1; i<prime_cont; i++){
		
		llu k = prime[i];
		if(k*k > max)
			break;

		int j = 0;
		while(n % k == 0){
			j++;	
			n /= k;
		}
		
		total *= (j+1);
		if(n == 1)
			break;
	}

	
	if(n > 2)
		total *= 2;

	return total;
}


int main(){

	crivo();

	llu n, res;
	while(scanf("%llu", &n) != EOF){
		res = primeFactors(n);
		printf("%llu\n", res);
	}


	return 0;
}