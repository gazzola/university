#include <cstdio>
#include <string>
#include <cstring>

using namespace std;


char vogais[10001], consoa[10001];
char tempv[10001], tempc[10001];
int qtdv, qtdc;


bool estaNoAlfabeto(char c){
	return ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z'));
}

bool ehVogal(char c){
	if(estaNoAlfabeto(c)){

		if(c == 'A' or c == 'a')
			return true;
		if(c == 'E' or c == 'e')
			return true;
		if(c == 'I' or c == 'i')
			return true;
		if(c == 'O' or c == 'o')
			return true;
		if(c == 'U' or c == 'u')
			return true;

	}

	return false;
}


bool ehConsoante(char c){
	return (estaNoAlfabeto(c) and !ehVogal(c));
}


void printarPalavra(char *s, int n, int c, int v){
	
	int p;
	for(int i=0; i<qtdv; i++){
		p = (i+v) % qtdv;
		tempv[p] = vogais[i];
	}


	for(int i=0; i<qtdc; i++){
		p = (i+c) % qtdc;
		tempc[p] = consoa[i];
	}

	int j=0, k=0;
	for(int i=0; i<n; i++){
		if(ehVogal(s[i]))
			printf("%c", tempv[j++]);
		else if(ehConsoante(s[i]))
			printf("%c", tempc[k++]);
	}

	printf("\n");
}



int main(){
	
	int t, q, x, y, n;
	int c, v;
	char s[10001];
	
	
	scanf("%d", &t);
	for(int k=1; k<=t; k++){

		scanf("%s%n", s, &n);
		scanf("%d", &q);

		c = qtdc = v = qtdv = 0;
		for(int i=0; i<n; i++){
			if(ehVogal(s[i]))
				vogais[qtdv++] = s[i];
			else if(ehConsoante(s[i]))
				consoa[qtdc++] = s[i];
		}


		printf("Caso #%d:\n", k);
		
		while(q--){

			scanf("%d", &x);
			switch(x){
				case 0:
					scanf("%d", &y);
					if(qtdv > 0)
						v  = (v+y)%qtdv;
					break;
				case 1:
					scanf("%d", &y);
					if(qtdc > 0)
						c  = (c+y)%qtdc;
					break;
				case 2:
					printarPalavra(s, n, c, v);
					break;
			}
		}
	}


	return 0;
}