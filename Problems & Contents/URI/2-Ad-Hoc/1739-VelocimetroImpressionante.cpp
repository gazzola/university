#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long unsigned int llu;
#define MOD 4294967296	// 2^32


int myatoi(char c){
	return (int) c - '0';
}



int main(){
	
	llu pot[100001];
	llu ex[100001];

	pot[0] = 0;
	pot[1] = 1;
	pot[2] = 1;
	ex[0] = 1;
	ex[1] = 10;
	ex[2] = 100;

	for(int i=3; i<100001; i +=2){
		ex[i] = (ex[i-1]*10) % MOD;
		ex[i+1] = (ex[i]*10) % MOD;
		pot[i] = pot[i+1] = ex[(i-1)/2];
	}

	char numero[100001];
	int tam, d, e;

	while(scanf("%s%n\n", numero, &tam) != EOF){
		
		llu t = 0;
		for(int i=1; i<tam; i++)
			t += (9*pot[i]) % MOD;

		
		d = myatoi(numero[0])-1; 
		e = (int) (tam-1)/2.0;
		t += (d*ex[e]) % MOD;

		for(int i=1; i<=e; i++){
			d = myatoi(numero[i]);
			t += (d*ex[e-i]) % MOD;
		}

		printf("%llu\n", (t+1) % MOD);
	}

	
	return 0;
}