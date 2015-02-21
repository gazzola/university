#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
 
using namespace std;
 
 
 
int main(){
 
	long long unsigned int t, n, p;
	long long unsigned int maior[51], maior7[51];
	long long unsigned int x;
	 
	scanf("%llu", &t);
	while(t--){
 
		scanf("%llu %llu", &p, &n);
 
		for(unsigned int i=0; i<n; i++){
 
			maior[i] = 0;
			maior7[i] = 0;
 
			long long unsigned int media = 0;
 
			for(unsigned int j=0; j<p; j++){
 
				long long unsigned int z;
				scanf("%llu.%llu", &x, &z);
				x = x*10 + z;
				// scanf("%Lf", &x);
 
				if(x < 70)
					maior7[i] = max(x, maior7[i]);
 
				maior[i] = max(maior[i], x);
				media += x;
			}
 
 
		 	
			if(media < 70*p){
 
				// REPROVADO
				if(media < 40*p){
					printf("%.2Lf\n", (long double) media/(p*10.0));
				}
				// FINAL
				else{  
					if(maior7[i]*p > media)
						printf("%.2Lf\n", (long double) maior7[i]/10.0);
					else
						printf("%.2Lf\n", (long double) media/(p*10.0));
				}
			}
			// APROVADO
			else
				printf("%.2Lf\n",  (long double) maior[i]/10.0);
		}
 
	}
 
 
	return 0;
}