#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;



int main(){
	

	int n, a, b, x;
	int candidatos[50002];

	scanf("%d", &n);
	while(n--){

		scanf("%d %d", &a, &b);
		
		for(int i=0; i<=a; i++)
			candidatos[i] = 0;

		double m = (double) b/2.0;
		int ganhador = -1;
		for(int i=0; i<b; i++){
			scanf("%d", &x);
			candidatos[x]++;
			if((double) candidatos[x] > m)
				ganhador = x;
		}

		printf("%d\n", ganhador);
	}

	return 0;
}