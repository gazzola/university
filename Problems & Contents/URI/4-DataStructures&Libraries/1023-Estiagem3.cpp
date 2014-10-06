#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


const int INF = 9999;
const int MAX = 201; 



int main(){
	
	int n, a, b, count=1;
	int valores[MAX];
	int somam, somac;
	int menor, maior;
	
	
	while(scanf("%d", &n) and n != 0){

		memset(valores, 0, sizeof(valores));

		somam = somac = 0;
		menor = INF;
		maior = 0;
		
		for(int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			
			int x = b/a;
			valores[x] += a;
			
			if(x > maior)
				maior = x;
			
			if(x < menor)
				menor = x;

			somac += b;
			somam += a;
		}

		

		if(count > 1)
			printf("\n");

		printf("Cidade# %d:\n", count);


		printf("%d-%d", valores[menor], menor);
		valores[menor] = 0;

		for(int i=menor; i<=maior; i++){
			if(valores[i] > 0){
				printf(" %d-%d", valores[i], i);
				valores[i] = 0;
			}
		}

		double media = floor(100.0*somac/somam)/100.0;
		printf("\nConsumo medio: %.2lf m3.\n", media);

		count++;
	}

	return 0;
}