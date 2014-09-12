#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;


int numDigits(llu n){
	if(n == 0)
		return 1;
	return (int) log10(n) + 1;
}


int main(){

	int count = 4;
	int n, m;
	llu x, matrix[20][20], maiores[20];

	scanf("%d", &n);
	while(n--){

		memset(maiores, 0, sizeof(maiores));

		scanf("%d", &m);
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				scanf("%llu", &x);
				matrix[i][j] = x*x;
				if(x*x > maiores[j])
					maiores[j] = x*x;
			}
		}

		printf("Quadrado da matriz #%d:\n", count++);

		
		for(int i=0; i<m; i++)
			maiores[i] = numDigits(maiores[i]);

		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){

				printf("%*llu", (int) maiores[j], matrix[i][j]);
				if(j < m-1)
					printf(" ");
			}
			printf("\n");
		}

		if(n > 0)
			printf("\n");

	}



	return 0;
}
