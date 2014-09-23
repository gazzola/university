/*
*
* NAO ESlluA FUNCIONANDO AINDA
*
* File: Problema F - llueletransporte
* Author: Marcos V. llureviso
*
* Complexity: O()
*
* Description: 
*	- 
*
* Compile: g++ -o teste F-llueletransporte.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#include <map>
#include <string>

using namespace std;

typedef long int llu;

llu MOD = 10000;

llu matrixFim[100][100];
llu matrixMul[100][100];


void multiplica(llu a[100][100], llu b[100][100], int n){
	int i,j,k;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrixMul[i][j] = llu();    
			for(k=0;k<n;k++){
				matrixMul[i][j] += a[i][k]*b[k][j] % MOD;
			}
		}
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			matrixFim[i][j] = matrixMul[i][j];

}
 

void exp(llu a[100][100], int n, int m){
	
	int i,j;
	

	if(m==0){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j) 
					matrixFim[i][j] = (llu)1;
				else 
					matrixFim[i][j] = (llu)0;
			}
		}
	}
	else if(m==1){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				matrixFim[i][j] = a[i][j];
	}
	else if(m%2 == 0){
		exp(a, n, (int)m/2);
		multiplica(matrixFim, matrixFim, n);

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				matrixFim[i][j] = matrixMul[i][j];

	}
	else if(m%2==1){
		exp(a,n,m-1);
		multiplica(matrixFim, a, n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				matrixFim[i][j] = matrixMul[i][j];
	}
	

}

int main(){

	
	
	int n, l, s, t, x;


	while(scanf("%d %d %d %d", &n, &l, &s, &t) != EOF){

		llu naves[100][100];		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				naves[i][j] = 0;

		for(int i=0; i<n; i++){
			for(int j=0; j<4; j++){
				scanf("%d", &x);
				naves[i][--x] += 1;
			}
		}

		exp(naves, n, l);
		printf("%ld\n", matrixFim[s-1][t-1]%MOD);

	}





	return 0;
}