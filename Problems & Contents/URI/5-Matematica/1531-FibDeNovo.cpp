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

 
int main(){
	 
	long long int n, m; 
	//1000000000 100 -> 50

	while(scanf("%llu %llu", &n, &m) != EOF){
		printf("%llu\n", fib_fd(fib_fd(n)) % m);
	}

	return 0;
}