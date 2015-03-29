#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	
	// sum from i to n of i^2
	// quadrados formados com 1x1, 2x2, 3x3...

	int n;
	while(scanf("%d", &n) and n > 0){
		printf("%d\n", (n*(n+1)*(2*n+1))/6);
	}

	return 0;
}