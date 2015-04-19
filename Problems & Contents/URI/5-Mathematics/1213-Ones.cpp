#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	

	int n, x, qtd;
	while(scanf("%d", &n) != EOF){
	
		x = qtd = 1;
		while(x%n > 0){
			x = (x*10)%n + 1;
			qtd++;
		}

		printf("%d\n", qtd);
	}


	return 0;
}