#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	
	int t, n, x, m;

	scanf("%d", &t);
	for(int i=1; i<=t; i++){

		scanf("%d", &n);
		m = 0;
		while(n--){
			scanf("%d", &x);
			m = max(m, x);
		}

		printf("Case %d: %d\n", i, m);
	}
	
}

