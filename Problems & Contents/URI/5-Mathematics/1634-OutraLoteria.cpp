#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;



int mdc(int a, int b){
	int t;
	while(a != 0){
		t = a;
		a = b%a;
		b = t;
	}

	return t;
}



int main(){
	

	int n, m;
	int jogadores[10001];
	int s, d;
	
	while(scanf("%d %d", &n, &m) and n+m > 0){

		s = 0;
		for(int i=0; i<n; i++){

			// so o ultimo importa
			// pois 2^m > 2^m-1 + 2^m-2 + ... 2^1
			for(int j=0; j<m; j++)
				scanf("%d", &jogadores[i]);

			s += jogadores[i];
		}

		for(int i=0; i<n; i++){
			d = mdc(s, jogadores[i]);
			printf("%d / %d\n", jogadores[i]/d, s/d);
		}


	}




	return 0;
}