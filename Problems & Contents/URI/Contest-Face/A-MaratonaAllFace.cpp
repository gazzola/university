#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
 
using namespace std;



typedef long long unsigned int llu;

const llu MOD = 1000000007;



llu somaDivisores(llu n){
	
	llu total = 1;
	for(llu i=2; i*i<=n; ++i){
		if(n % i == 0){

			total = (total+i)%MOD;
			if(i*i != n)
				total = (total+n/i)%MOD;
		}
	}

	return total%MOD;
}



int main(){
	

	int n;

	llu fat[100001];
	fat[2] = 2;
	for(int i=3; i<=100000; i++){
		fat[i] = fat[i-1]*i;
		if(fat[i] > MOD)
			fat[i] = fat[i]%MOD;
	}

	while(scanf("%d", &n) != EOF){
		llu s = somaDivisores(fat[n]);
		printf("%llu %llu\n", s, fat[n]);
	}
 
	return 0;
}
