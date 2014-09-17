/*
*
* File: Problema I - RSA
* Author: Marcos V. Treviso
*
* Complexity: O(n.m)
*
* Description: 
*	- Decifrar mensagem RSA dado a mensagem cifrada e duas chaves publicas
*
* Compile: g++ -o teste I-RSA.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cmath>

typedef long long unsigned int llu;
typedef long long signed int lls;


// algoritmo de euclides para calcular o mdc de 2 nums
llu mdc(llu a, llu b){

	llu temp;
	while(a != 0){
		temp = a;
		a = b%a;
		b = temp;
	}

	return temp;

}


// algoritmo de euclides estendido
lls mdcest(lls a, lls b, lls *x, lls *y) {
	lls xx, yy, d;
	if(b == 0){
		*x = 1; 
		*y = 0;
		return a;
	}

	d = mdcest(b, a%b, &xx, &yy);
	*x = yy;
	*y = xx - a/b*yy;
	return d;
}


lls inv(lls a, lls MOD){
	lls x, y;
	mdcest(a, MOD, &x, &y);

	if(x < 0)
		x = x+MOD;

	return x;
}


// regra: mdc(n, e) == 1

// totiente = quantos numeros respeitam a regra

// Na maratona diz que se mdc(n,e) == 1, porem nos nao conhecemos 
// os numeros primos (p e q) que geraram esse n.

// Entao temos que testar para todos os numeros que sao co-primos de n,
// menores que n e que respeitem essa regra. 

// Uma boa observacao eh que nao precisamos calcular 
// se um numero i eh primo, pois se nao for
// ele nao vai respeitar a regra de ser co-primo de n
llu totiente(llu n){
	llu total = 1;
	llu i = 2;
	while(i < n){
		if(mdc(n, i) == 1)
			total++;
		i++;
	}

	return total;
}

// inverso multiplicativo de e mod totiente
llu getD(llu e, llu totiente){
	return inv(e, totiente);
}


// se usarmos o pow do math.h, vai dar overflow
// sendo assim, devemos modularizar a cada iteracao
// da multiplicacao da exponenciacao
llu powmod(llu c, llu d, llu n){

	llu i = 0;
	llu res = 1;
	while(i  < d){
		res = (res*c) % n;
		i++;
	}

	return res;

}

int main(){

	llu n, e, c;
	while(scanf("%llu %llu %llu", &n, &e, &c) != EOF){

		llu tot = totiente(n);
		llu d = getD(e, tot);

		//llu res = (llu) pow(c, d) % n; //overflow
		llu res = powmod(c, d, n);
		printf("%llu\n", res);
	}

	return 0;
}