#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long unsigned int llu;

// http://en.wikipedia.org/wiki/Summation

int main(){

	int n;

	while(scanf("%d", &n) != EOF){


		llu s1 = n*(n+1)/2;
		llu s2 = n*(n+1)*(2*n+1)/6;
		llu s3 = s1*s1;
		llu s4 = (n*(n+1)*(2*n+1)*(3*n*n+3*n-1))/30;
		llu s5 = s3*s3;

		llu r2 = s3 - s2;
		llu r3 = s3*s1 - s3;
		llu r4 = s5 - s4;

		printf("%llu %llu %llu %llu %llu %llu\n", s2, r2, s3, r3, s4, r4);

	}
	

	return 0;
}