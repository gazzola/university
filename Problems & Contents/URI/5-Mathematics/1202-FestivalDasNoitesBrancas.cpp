#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;


typedef long long unsigned int llu;
typedef pair<llu, llu> ii;

ii fast_doubling(llu n, int mod){
	
	if(n <= 0)
		return ii(0, 1);

	ii ab = fast_doubling(n/2, mod);
	llu a = ab.first;
	llu b = ab.second;

	llu c = (a*(2*b + mod - a))%mod;
	llu d = (b*b + a*a)%mod;

	if((n&1) == 1)
		return ii(d, (c+d)%mod);

	return ii(c, d);
}


llu fib_fd(llu n, int mod){
	if(n <= 0)
		return 0;
	return fast_doubling(n-1, mod).second;
}


int pisano(int m){

	if(m <= 1)
		return 1;
	
	int a, b, temp, i, last;
	a = b = 1;
	i = last = 0;

	while(true){
		temp = a;	
		a = b;
		b = (temp+b)%m;

		if(b==last && last==1)
			break;

		last = b;
		i++;
	}

	return i+1;
}

 
int main(){
	 
	
	int t, k;
	char s[10001];
	llu fib[1501];

	int MOD = pisano(1000);
	fib[1] = fib[2] = 1;
	for(int i=3; i<=MOD; i++)
		fib[i] = (fib[i-1]+fib[i-2])%1000;


	scanf("%d\n", &t);
	while(t--){
 
		scanf("%s%n\n", s, &k);

		llu n = 0, e = 1;
		for(int i=k-1; i>=0; i--){
			if(s[i] == '1')
				n = (n+e)%MOD;
			e = (e*2)%MOD; 
		}

		printf("%.3llu\n", fib[n]);
	}

	return 0;
}