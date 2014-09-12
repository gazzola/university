#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;


void printMatrix(char matrix[110][110], int n){
	for(int i=0; i<n; i++)
		printf("%s\n", matrix[i]);
	printf("\n");
}


int countOccurrences(char *from, char *sub){
	
	int total = 0;
	char* tmp = from;

	while((tmp = strstr(tmp, sub)) != NULL){
		total++;
		tmp++;
	}

	return total;
}



int main(){
	
	
	int t, l, c, p;
	char linhas[110][110];	// linhas normais
	char colunas[110][110];	// colunas invertidas 
	char palavra[110];

	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &l, &c);

		for(int i=0; i<l; i++){
			scanf("%s", palavra);
			strcpy(linhas[i], palavra);

			for(int j=0; j<c; j++)
				colunas[j][i] = linhas[i][j];

			colunas[i][l] = '\0';
		}


		scanf("%d", &p);
		while(p--){
					
			scanf("%s", palavra);

			int total = 0;	
			for(int i=0; i<l; i++)
				total += countOccurrences(linhas[i], palavra);

			if(strlen(palavra) > 1)
				for(int i=0; i<c; i++)
					total += countOccurrences(colunas[i], palavra);


			printf("%d\n", total);
		}		

	}


	return 0;
}