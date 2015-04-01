#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	
	int n, m, c;

	while(scanf("%d %d %d", &n, &m, &c) and n+m+c > 0){

		if(c == 0)
			printf("%d\n", (n-7)*(m-7)/2);
		else
			printf("%d\n", (int) ceil((n-7)*(m-7)/2.0));

	}


	return 0;
}