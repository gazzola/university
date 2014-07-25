#include <cstdio>
#include <vector>

using namespace std;

typedef long long unsigned int llu;
typedef pair<llu, llu> ii;
 

ii fast_doubling(long long int n){
	
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

llu fib_fd(long long int n){
	if(n <= 0)
		return 0;
	return fast_doubling(n-1).second;
}


int pisano(int m){
	
	int x=2;
	while(true){

		llu t1 = fib_fd(x)%m;
		llu t2 = fib_fd(x+1)%m;
		if(t1 == t2 && t2 == 1)
			break;

		x++;
	}

	return x-1;
}


int main(){
	 
	long long int n, m; 

	while(scanf("%llu %llu", &n, &m) != EOF){
		int c = pisano(m);
		llu result = fib_fd(fib_fd(n)%c) % m;
		printf("%llu\n", result);
	}

	return 0;
}