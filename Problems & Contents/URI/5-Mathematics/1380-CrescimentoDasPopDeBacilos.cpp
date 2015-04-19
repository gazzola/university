#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


typedef long long unsigned int llu;
typedef pair<llu, llu> ii;



int ctoi(char c){
	return (int) c - '0';
}



int main(){
	
	const int MOD = 1500; // pisano(1000);
	char s[1000001];
	int t, n, e, x;

	llu fib[1501];	// MOD+1
	fib[1] = fib[2] = 1;
	for(int i=3; i<=MOD; i++)
		fib[i] = (fib[i-1]+fib[i-2])%1000;


	scanf("%d\n", &t);
	while(t--){
		
		scanf("%s%n\n", s, &n);
		
		e = 1;
		x = 0;
		for(int i=n-1; i>=0; i--){
			x = (x+(ctoi(s[i])*e) % MOD) % MOD;
			e = (e*10)%MOD;
		}

		printf("%.3llu\n", fib[x]);

	}


	return 0;
}