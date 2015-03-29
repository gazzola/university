#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long unsigned int llu;


int main(){

	int t, n, k;

	scanf("%d", &t);
	while(t--){

		scanf("%d", &n);
		scanf("%*s%n\n", &k);

		llu total = 1;
		for(int i=n;  i>0; i-=k)
			total *= i;

		printf("%llu\n", total);

	}


	return 0;
}