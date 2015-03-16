#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


int pos(char c){
	return (int) c - 'E';
}



int main(){
 	

 	int obj = 1000000;
 	
	int notas[30];
	notas[pos('W')] = obj;
	notas[pos('H')] = obj/2;
	notas[pos('Q')] = obj/4;
	notas[pos('E')] = obj/8;
	notas[pos('S')] = obj/16;
	notas[pos('T')] = obj/32;
	notas[pos('X')] = obj/64;

	char s[201];
	int n;

	while(scanf("%s%n\n", s, &n) and s[0] != '*'){

		int soma = 0, qtd = 0;
		for(int i=0; i<n; i++){
			if(s[i] == '/'){
				if(soma == obj)
					qtd++;
				soma = 0;
			}
			else
				soma += notas[pos(s[i])];
		}


		printf("%d\n", qtd);
	}



 
	return 0;
}