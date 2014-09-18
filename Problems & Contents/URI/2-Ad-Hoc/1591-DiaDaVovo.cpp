#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;


void printMatrix(char matrix[50][51], int n){
	for(int i=0; i<n; i++)
		printf("%s\n", matrix[i]);
	printf("\n");
}


int countOccurrences(char *from, char *sub){
	
	int total = 0;
	char *tmp = from;

	while((tmp = strstr(tmp, sub)) != NULL){
		total++;
		tmp++;
	}

	return total;
}


int contar(char *from, char *sub){

	int tamf = strlen(from);
	int tams = strlen(sub);

	if(tams > tamf)
		return 0;

	if(tams == tamf){
		if(strcmp(from, sub) == 0)
			return 1;
		return 0;
	}

	int count = 0;
	bool ok;
	for(int i=0; i<=tamf-tams; i++){

		ok = true;
		for(int j=0; j<tams; j++){
			if(from[i+j] != sub[j]){
				ok = false;
				break;
			}
		}
		if(ok)
			count++;
	}

	return count;
}


int main(){
	
	
	int t, l, c, p;
	char linhas[50][51];	// linhas normais
	char colunas[50][51];	// colunas invertidas 
	char palavra[51];


	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &l, &c);

		for(int i=0; i<l; i++){

			scanf("%s", linhas[i]);
			linhas[i][c] = '\0';

			for(int j=0; j<c; j++){
				colunas[j][i] = linhas[i][j];
				colunas[j][l] = '\0';
			}
		}


		scanf("%d", &p);
		while(p--){
					
			scanf("%s", palavra);

			int total = 0;
			int tam = strlen(palavra);
			if(tam <= l)
				for(int i=0; i<l; i++)
					total += countOccurrences(linhas[i], palavra);

			if(tam > 1 and tam <= c)
				for(int i=0; i<c; i++)
					total += countOccurrences(colunas[i], palavra);


			printf("%d\n", total);
		}		

	}


	return 0;
}