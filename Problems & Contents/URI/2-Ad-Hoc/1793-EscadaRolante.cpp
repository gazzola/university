#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	
	int n, vet[101], fim, s, ant;

	while(scanf("%d", &n) and n > 0){

		for(int i=0; i<n; i++)
			scanf("%d", &vet[i]);


		fim = vet[0]+10;
		s = 10;

		for(int i=1; i<n; i++){
			if(fim >= vet[i]){
				ant = fim;
				fim = vet[i]+10;
				s += fim - ant;
			}
			else{
				fim = vet[i]+10;
				s += 10;
			}

		}

		printf("%d\n", s);

	}


	return 0;
}