#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
typedef long long unsigned int llu;
const llu MOD = 1000000009;
 
int main(){
 
	llu fat[100001];
	fat[0] = 1;
	fat[1] = 1;
	fat[2] = 2;
	fat[3] = 1;
	for(int i=4; i<100001; i++)
		fat[i] = (fat[i-1]*i) % MOD;
 
	int n;
	while(scanf("%d", &n), n)
		printf("%llu\n", fat[n]%MOD);
 
	return 0;
}