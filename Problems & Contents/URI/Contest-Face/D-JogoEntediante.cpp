#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long unsigned int llu;


int contaDivisores(llu x){
	
	if(x == 1)
		return 1;


	int total = 2;
	for(llu i=3; i*i<=x; ++i){
		if(x % i == 0)
			total++;
	}
	
	return total;
}


llu divisorCount(llu n) {
    // a counter for the number of divisors
    // intially 1 (the multiplication identity)
    llu count = 1;
 
    // save the square root to avoid re-computation
    llu mysqrt = (llu) sqrt(n);
 
    // loop through 2 and the odd numbers up to sqrt(n)
    for (llu i = 2; i <= mysqrt; i = (i == 2 ? 3 : i + 2)) {
 
        // a counter for the power of the
        // current number in the prime factorization
        llu mypow = 0;
 
        // while i is in n's prime factorization
        while (n % i == 0) {
            mypow++;  // increment the power count
            n /= i; // remove one i from the prime factorization of n
        }
 
        // if there were any i's in n's prime factorization
        if (mypow != 0) {
            // change the divisor count according to our formula
            count *= mypow + 1;
 
            // recompute the square root, since we've changed n
            // (a little optimization)
            mysqrt = (llu)sqrt(n);
        }
    }
 
    // if we've still not removed all factors from n,
    // then there is one prime factor left
    if (n != 1)
        // change the divisor count according to our formula
        // (the power of the last prime is 1)
        count *= 1 + 1;
 
    // return the number of divisors
    return count;
}

// metodo para teste, obviamente deve-se usar o crivo
bool ehPrimo(int x){

	if(x <= 2)
		return true;

	for(int i=2; i<=(x/2)+1; i++){
		if(x % i == 0){
			return false;
		}
	}

	return true;
}

int num_divisors(llu n){
	
    if(n % 2 == 0)
    	n = n/2;

  	unsigned long divisors = 1;
    unsigned int count = 0;

    while(n % 2 == 0){
		count += 1;
		n = n/2;
    }

    divisors = divisors * (count + 1);
    unsigned int p = 3;
    while(n != 1){
        count = 0;
        while(n % p == 0){
            count += 1;
            n = n/p;
        }
        divisors = divisors * (count + 1);
        p += 2;
    }

    return divisors;
}


// essa funcao tem erros por causa da precisao do epsilon
bool ehQuadradoPerfeito(llu x){
	llu y = round(sqrt(x));
	if(y*y == x)
		return true;
	return false;
}


bool ehQuadradoPerfeito_Bissecao(llu x){

	if(x == 1)
		return true;

	llu ini=0, fim=x, erro=fim-ini;
	llu meio, res;

	while(ini < fim and erro > 1){

		meio = (ini+fim)/2;

		res = meio*meio;
		if(res == x)
			return true;
		else if(res < x)
			ini = meio;
		else
			fim = meio;

		erro = fim-ini;
	}

	return false;
}



int main(){
	
	int n;
	llu x;

	bool ehQP[10000];
	memset(ehQP, false, sizeof(ehQP));

	while(scanf("%d", &n) and n > 0){
		int soma = 0;
		while(n--){
			scanf("%llu", &x);
			if(x < 10000 and ehQP[x])
				soma++;
			else{
				if(ehQuadradoPerfeito(x)){
					if(x < 10000)
					ehQP[x] = true;
					soma++;
				}
			}
		}

		if(soma % 2 == 0)
			printf("Garen\n");
		else
			printf("Annie\n");
	}


	return 0;
}
