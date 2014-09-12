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
const int MOD = 1000000007;


// helper function
int getPos(char c){
	return (int) c - (int) 'A';
}



/*
INVERSO MODULAR (usando algoritmo de euclides):
ax + by = 1
ax = 1 mod b
*/

lls mdc(lls a, lls b, lls *x, lls *y) {
	lls xx, yy, d;
	if(b == 0){
		*x = 1; 
		*y = 0;
		return a;
	}

	d = mdc(b, a%b, &xx, &yy);
	*x = yy;
	*y = xx - a/b*yy;
	return d;
}


lls inv(lls a){
	lls x, y;
	mdc(a, MOD, &x, &y);

	if(x < 0)
		x = x+MOD;

	return x;
}



llu fastexp(llu a, llu b){

  llu x;

  if(b==0) 
  	return 1;
  
  if(b==1) 
  	return a;

  if(b%2==0){
    x = fastexp(a, b/2) % MOD;
    return (x*x) % MOD;
  }

   return (a * fastexp(a, b-1)) % MOD;

}


llu inv2(llu a){
  return fastexp(a, MOD-2);
}



int main(){


	int quantidades[26];
	char palavra[1001]; 
	vector<llu> factMod(1001, 1);

	// pre calcula todos fatoriais
	for(int i=2; i<1001; i++)
		factMod[i] = (factMod[i-1]*i) % MOD;


	while(scanf("%s", palavra) != EOF){

		memset(quantidades, 0, sizeof(quantidades));
		int len = strlen(palavra);

		// seta as quantidades de cada caracter
		for(int i = 0; i<len; i++) 
			quantidades[getPos(palavra[i])]++;


		// denominador eh o produtorio do fatorial das quantidades
		llu den = 1;
		for(int i=0; i<26; i++)
			if(quantidades[i] > 1)
				den = (den*factMod[quantidades[i]]) % MOD;


		// faz a conta das permutacoes
		llu invden = inv(den);
		llu res = factMod[len];
		llu final = (res*invden) % MOD;
		

		printf("%llu\n", final);

	}


	return 0;
}
