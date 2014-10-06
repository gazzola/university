#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

bool verNinguemResolv(bool *vet, int n){
	for(int i=0; i<n; i++)
		if(vet[i] == false)
			return false;
	return true;
}

bool verTodosResolv(bool *vet, int n){
	for(int i=0; i<n; i++)
		if(vet[i] == false)
			return false;
	return true;
}

bool verNenhumProblem(bool *vet, int n){
	

	for(int i=0; i<n; i++)
		if(vet[i] == false)
			return false;
	return true;
}

bool verAlgumProblem(bool *vet, int n){
	for(int i=0; i<n; i++)
		if(vet[i] == false)
			return false;
	return true;
}

int contar(int mat[101][101], int n, int m){

	bool ninguemResolveu[101];
	bool todosResolvidos[101];
	bool nenhumProblem[101];
	bool algumProblem[101];

	memset(ninguemResolveu, false, sizeof(ninguemResolveu));
	memset(todosResolvidos, false, sizeof(todosResolvidos));

	memset(nenhumProblem, false, sizeof(nenhumProblem));
	memset(algumProblem, false, sizeof(algumProblem));

	int count = 0;

	for(int i=0; i<n; i++){

		for(int j=0; j<m; j++){

			if(mat[i][j] == 0){
				ninguemResolveu[i] = true;
				nenhumProblem[j] = true;
			}

			if(mat[i][j] == 1){
				todosResolvidos[j] = true;
				algumProblem[i] = true;
			}
		}

	}

	//printf("-------\n");
	if(verNinguemResolv(ninguemResolveu, n)){
		//printf("1\n");
		count++;
	}

	if(verTodosResolv(todosResolvidos, m)){
		//printf("2\n");
		count++;
	}

	if(verNenhumProblem(nenhumProblem, m)){
		//printf("3\n");
		count++;
	}

	if(verAlgumProblem(algumProblem, n)){
		//printf("4\n");
		count++;
	}

	//printf("-------\n");
	
	return count;
}


int main(){
	

	int n, m;
	int mat[101][101];

	while(scanf("%d %d", &n, &m) and n > 0){

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &mat[i][j]);
		

		printf("%d\n", contar(mat, n, m));


	}

	
	return 0;
}