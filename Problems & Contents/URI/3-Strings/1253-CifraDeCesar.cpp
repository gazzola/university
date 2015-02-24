#include <cstdio>
#include <string>
#include <cstring>

using namespace std;


int getPos(char c){
	return c-'A';
}

int mymod(int a, int b){
	if (a < 0)
        a += b;
	return a%b;
}


int main(){


	char letras[26][30];

	int t = 'Z' - 'A' + 1;
	for(int k=0; k<26; k++)
		for(int i=0; i<t; i++)
			letras[k][i] = 'A' + mymod((i-k), t);


	int n, x, tam;
	char s[55];

	scanf("%d", &n);
	while(n--){

		scanf("%s%n", s, &tam);
		scanf("%d", &x);
		
		for(int i=0; i<tam-1; i++)
			printf("%c", letras[x][getPos(s[i])]);

		printf("\n");
	}



	return 0;
}