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
	
	int total = 1;
	for(llu i=2; i*i<=x; ++i){
		if(x % i == 0)
			total++;
	}

	if(x > 1)
		total++;
	
	return total;
}


int divisorCount(llu n) {
    // a counter for the number of divisors
    // intially 1 (the multiplication identity)
    int count = 1;
 
    // save the square root to avoid re-computation
    int mysqrt = (int) sqrt(n);
 
    // loop through 2 and the odd numbers up to sqrt(n)
    for (int i = 2; i <= mysqrt; i = (i == 2 ? 3 : i + 2)) {
 
        // a counter for the power of the
        // current number in the prime factorization
        int mypow = 0;
 
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
            mysqrt = (int)sqrt(n);
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

int main(){
	

	int n;
	llu x;
	

	int divisores[1000001];
	memset(divisores, 0, sizeof(divisores));
	unordered_map<llu, int> numDivisores;

	while(scanf("%d", &n) and n > 0){
		llu soma = 0;
		while(n--){
			scanf("%llu", &x);
			if(x > 1000000){
				if(numDivisores.count(x) == 0){
					int k = divisorCount(x);
					numDivisores[x] = k;
					soma += k;
				}
				else
					soma += divisorCount(x);
				//printf("%d\n", num_divisors(x));
			}
			else if(divisores[x] == 0){
				divisores[x] = num_divisors(x);
				soma += divisores[x];
			}
			else{
				soma += divisores[x];
			}

			//printf("%d\n", divisores[x]);
		}

		if(soma % 2 == 0)
			printf("Garen\n");
		else
			printf("Annie\n");
	}


	return 0;
}
