#include <cstdio>
#include <vector>

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

	int n, m, c; 
	llu res1, res2;

	while(scanf("%d %d", &n, &m) != EOF){
		
		c = pisano(m);
		res1 = fib_fd(n, c);
		res2 = fib_fd(res1, m);

		printf("%llu\n", res2);
	}

	return 0;
}