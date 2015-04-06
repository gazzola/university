#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;


int main(){

	int t;
	llu n;

	scanf("%d", &t);
	while(t--){

		scanf("%llu", &n);
		printf("%llu\n", (llu) (sqrt(8*n + 1) - 1)/2);

	}


	return 0;
}