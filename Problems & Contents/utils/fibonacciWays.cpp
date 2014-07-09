#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include <sys/time.h>

using namespace std;

typedef long long unsigned int llu;
typedef pair<llu, llu> ii;


// recursive way - O(x^n)
llu fib_re(int n){
	if(n <= 0)
		return 0;
	else if(n == 1)
		return 1;

	return fib_re(n-2) + fib_re(n-1);
}



// iterative way - O(n)
llu fib_ok(int n){
	if(n<=0)
		return 0;

	llu a = 1;
	llu b = 1;
	llu temp;
	int i = 0;
	while(i < n-2){
		temp = a;	
		a = b;
		b = temp+b;
		i++;
	}

	return b;
}



// dynamic programming way - O(n)
llu fib_dn(int n){
	llu *arr = (llu*)malloc(n*sizeof(llu));
	int i;

	arr[0] = 0;
	arr[1] = 1;

	for(i=2; i<=n; i++)
		arr[i] = arr[i-2]+arr[i-1];


	return arr[n];
}



// fast doubling way - O(lg n)
ii fast_doubling(int n){
	
	if(n <= 0)
		return ii(0, 1);

	ii ab = fast_doubling(n/2);
	llu a = ab.first;
	llu b = ab.second;

	llu c = a*(2*b-a);
	llu d = b*b + a*a;

	if((n&1) == 1)
		return ii(d, c+d);
	else
		return ii(c, d);

}

llu fib_fd(int n){
	if(n <= 0)
		return 0;
	return fast_doubling(n-1).second;
}



// rounding way - O(1)
// has to work with bigger numbers, see GMP library of GNU Project or Boost Library.
llu mround(double number){
    return floor(number + 0.5);
}

llu rounding(int n){
	double sqrt5 = sqrt(5);
	double phi = (sqrt5+1)/2;
	double alfa = pow(phi, n)/sqrt5;
	return mround(alfa);
}


llu fib_rd(int n){
	if(n <= 0)
		return 0;
	return rounding(n);
}





double crono(){
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1e6;
}



int main(int argc, char const *argv[]){

	srand(time(NULL));

	if(argc < 2){
		printf("Sem argumentos! <1> -> n | [2] -> y or n para modo recursivo tbm");
		return 1;
	}

	int n = atoi(argv[1]);
	string rec = (argc > 2) ? argv[2] : "n";



	double timer = crono();
	printf("fib_fd(%d) = %llu\n", n, fib_fd(n));
	timer = crono() - timer;
	printf("em %lfs\n\n", timer);


	timer = crono();
	printf("fib_rd(%d) = %llu\n", n, fib_rd(n));
	timer = crono() - timer;
	printf("em %lfs\n\n", timer);


	timer = crono();
	printf("fib_ok(%d) = %llu\n", n, fib_ok(n));
	timer = crono() - timer;
	printf("em %lfs\n\n", timer);


	timer = crono();
	printf("fib_dn(%d) = %llu\n", n, fib_dn(n));
	timer = crono() - timer;
	printf("em %lfs\n\n", timer);


	if(rec == "s"){
		timer = crono();
		printf("fib_re(%d) = %llu\n", n, fib_re(n));
		timer = crono() - timer;
		printf("em %lfs\n\n", timer);
	}

	return 0;
}