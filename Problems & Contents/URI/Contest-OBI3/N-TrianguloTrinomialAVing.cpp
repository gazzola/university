#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


typedef pair<int, int> ii;
typedef long long unsigned int llu;
const llu MOD = 2147483647; // (1 << 31) - 1;

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


int main(){
	
	
	llu n;
	scanf("%llu", &n);
	printf("%llu\n", fastexp(3LL, n));


}
