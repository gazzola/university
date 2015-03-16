#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;



int buscaI(bool *fila, int a, int k, int n){

	int c = 0, i = a;
	while(true){
		if(fila[i]){
			c++;
			if(c == k)
				break;
		}
		i = (i%n)+1;
	}

	return i;
}


int buscaJ(bool *fila, int a, int m, int n){

	int c = 0, j = a;
	while(true){
		if(fila[j]){
			c++;
			if(c == m)
				break;
		}
		j = (j == 1) ? n : j-1;
	}

	return j;
}



int main(){
	

	bool fila[25];

	int n, k, m, t;
	while(scanf("%d %d %d", &n, &k, &m) and n > 0){

		for(int i=1; i<=n; i++)
			fila[i] = true;	

		int i=1, j=n;
		t = 0;
		bool first = true;

		while(t < n){

			i = buscaI(fila, i, k, n);
			j = buscaJ(fila, j, m, n);
			fila[i] = fila[j] = false;

			if(i == j){
				if(!first)
					printf(",");
				printf("%3d", i);
				t += 1;
			}
			else{
				if(!first)
					printf(",");
				printf("%3d%3d", i, j);
				t += 2;
			}

			first = false;
		}

		printf("\n");
	}
	

	return 0;
}


// 0 1 2 3 4 5 6 7 8 9 	-> 3 7
// 0 1 2 4 5 6 8 9     	-> 3 7 8 4
// 0 1 2 5 6 9			-> 3 7 8 4 2 0
// 1 5 6 9				-> 3 7 8 4 2 0 1 5
// 6 9                  -> 3 7 8 4 2 0 1 5 6