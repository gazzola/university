#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int main(){
	
	
	int n;
	bool visitados[10000];

	while(scanf("%d", &n) and n > 0){

		memset(visitados, false, sizeof(visitados));

		int i = 1;
		visitados[n] = true;
		n = (n*n/100)%10000;

		while(true){
			
			if(visitados[n])
				break;

			++i;
			visitados[n] = true;
			n = (n*n/100)%10000;
		}

		printf("%d\n", i);

	}


	
	return 0;
}