/*
*
* File: Problema F - Teletransporte
* Author: Marcos V. Treviso
*
* Complexity: O(n^3 log n)
*
* Description: 
*	- 
*
* Compile: g++ -o teste F-Teletransporte.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdint>

using namespace std;


typedef long int llu;


const int SIZE = 10000;
const int MOD = 10000;


void multiplica(llu *a, llu *b, int n, llu *c){

	register int i, j, k;
	llu mul[10000], temp;
	memset(mul, 0, sizeof(mul));

	for(i=0; i<n; ++i){
		for(k=0; k<n; ++k){
			temp = a[i*n + k];
			for(j=0; j<n; ++j){
				mul[i*n + j] += (temp * b[k*n + j])%10000;
			}
		}
	}
	
	for(i=0; i<n*n; i++)
		c[i] = mul[i];
}



llu exp(llu *a, int n, int l, int s, int t){
	
	llu res[10000];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			res[i*n + j] = (i==j) ? 1 : 0;

	while(l > 0){
		if(l % 2 == 1)
			multiplica(res, a, n, res);
	
		multiplica(a, a, n, a);
		l /= 2;
	}

	return res[n*(s-1) + t-1]%10000;
}

int main(){

	
	
	int n, l, s, t, x;
	llu naves[SIZE];

	while(scanf("%d %d %d %d", &n, &l, &s, &t) != EOF){

		memset(naves, 0, sizeof(naves));

		for(int i=0; i<n; i++){
			for(int j=0; j<4; j++){
				scanf("%d", &x);
				naves[i*n + x-1] += 1;
			}
		}
		
		printf("%lu\n", exp(naves, n, l, s, t));

	}

	return 0;
}