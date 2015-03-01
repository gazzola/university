#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;



int ctoi(char c){
	return (int) c - 'a';
}


int main(){

	
	int n, l, c, tam;
	char t;
	char s[80];

	while(scanf("%d %d %d\n", &n, &l, &c) != EOF){

		int pags, linhas, caracs;

		pags = 1;
		linhas = 1;
		caracs = 0;

		while(n--){
			
			scanf("%s%n%c", s, &tam, &t);

			if(caracs+tam > c){
				
				if(linhas + 1 > l){
					pags++;
					linhas = 0;
				}

				linhas++;
				caracs = 0;
			}

			if(t == ' ')
				tam++;
			
			caracs += tam;
		}
		
		printf("%d\n", pags);

	}


	return 0;
}