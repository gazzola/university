#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
 
 
 
using namespace std;
 
 
typedef long long unsigned int llu;
typedef pair<char*, int> ci;

 
int somatorioNome(char nome[12]){
	llu soma = 0;
	for(int i=0; nome[i]!='\0'; i++)
		soma += (int) nome[i];
	return soma;
}
 
llu somatorioPessoas(ci *pessoas, int x, int y){
	llu soma = 0;
	int count = y-x+1;
	for(int i=x; i<=y; i++){
		soma += pessoas[i].second*count;
		count--;
	}
	return soma;
}
 
 
llu somatorioPessoasInv(ci *pessoas, int x, int y){
	llu soma = 0;
	int count = 1;
	for(int i=x; i<y; i++){
		soma += pessoas[i].second*count;
		count++;
	}
	return soma;
}
 
 
 
int main(){
 
	int n;
 
	while(true){
 
		scanf("%d", &n);
		if(n == 0)
			break;
 
		ci pessoas[100001];
 
		for(int i=0; i<n; i++){
			char *nome = (char*) malloc (12); 
			scanf("%s", nome);
			pessoas[i] = ci(nome, somatorioNome(nome));
		}
 

		bool empate = false;
		int m=0, e=0, d=n-1;
 		
		while(e <= d){
 
			m = (e+d)/2;
 
			llu forca1 = somatorioPessoas(pessoas, 0, m);		// somatorio de [0, m] com cada elem multiplicado por sua posicao
			llu forca2 = somatorioPessoasInv(pessoas, m+1, n);	// somatorio de (m, n] com cada elem multiplicado por sua posicao
 
			if(forca1 < forca2)			// se a forca1 for menor que a forca2, vai para a direita
				e = m+1;
			else if(forca1 > forca2)	// se a forca1 for maior que a forca2, vai para a esquerda
				d = m-1;
			else{						// c.c, houve empate de forcas
				empate = true;
				break;
			}
		}
 
		if(empate)
			printf("%s\n", pessoas[m].first);
 		else
 			printf("Impossibilidade de empate.\n");
 			
	}
 
	return 0;
}