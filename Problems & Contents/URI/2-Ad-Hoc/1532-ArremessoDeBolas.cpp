#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



bool verificar(int n, int v){
	
	int i, vezes, total;
	for(int j=1; j<=v; j++){
		
		i = 1;
		vezes = total = j;

		while(i <= vezes and vezes >= 0){

			if(total == n)
				return true;

			total += vezes;

			if(i == vezes-1){
				i = -1;
				vezes--;
			}

			i++;
		}
	}

	return false;
}


int main(){
	
	int n, v;

	while(scanf("%d %d", &n, &v) and n > 0){

		if(n <= v)
			printf("possivel\n");
		else{

			if(verificar(n, v))
				printf("possivel\n");
			else
				printf("impossivel\n");
		}


	}

	
	return 0;
}