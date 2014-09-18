```cpp
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

/*

c = pisano(m);
res1 = fib_fd(n, c);	 // fib(n) % m
res2 = fib_fd(res1, m); // fib(fib(n)) % m

*/


// INVERSO MODULAR:

typedef long long unsigned int llu;
typedef long long signed int lls;
const int MOD = 1000000007;

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


for(int i=2; i<1001; i++)
	factMod[i] = (factMod[i-1]*i) % MOD;

llu den = 1;
for(int i=0; i<26; i++)
	if(quantidades[i] > 1)
		den = (den*factMod[quantidades[i]]) % MOD;

// (n!/den) % m
// (n!%m * inv(den%m))%m

llu invden = inv(den);
llu res = factMod[len];
llu final = (res*invden) % MOD;


double raiz_quadrada(double n){
    double ini = 0, meio, fim = n;
    
    for(int i=0; i<100; i++) { // faremos no maximo 100 tentativas
         meio = (ini+fim)/2.0;
         
         if(meio*meio == n) 
         	return meio;
         else if(meio*meio > n) 
         	fim = meio;
         else 
         	ini = meio;
    }
    
    return meio;
}
```