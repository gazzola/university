#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;

const char charbase = 'a';
const int INF = 9999999;
int matAdj[201][201];




int charToInt(char c){
	return (int) c - charbase;
}

char intToChar(int i){
	return (char) i + charbase;
}


void printCharBits(int x){
	int i = 0;
	while(x > 0){
		if((x&1) == 1)
			printf("%c", charbase+i);

		i++;
		x >>= 1;
	}
}


void floydWarshall(int n){
	int i, j, k;
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(matAdj[i][k] > 0 and matAdj[k][j] > 0)
					matAdj[i][j] |= (matAdj[i][k] & matAdj[k][j]);
}


void printGraph(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(matAdj[i][j] != 0){
				printf("[%d][%d]: ", i+1, j+1);
				printCharBits(matAdj[i][j]);
				printf("\n");
			}
		}
	}
	printf("\n");
}



int main(){
	
	int n, a, b;
	char companhia[50];

	while(scanf("%d", &n) and n > 0){

		memset(matAdj, 0, 201*n*sizeof(matAdj[0][0]));

		while(true){
			scanf("%d %d", &a, &b);
			if(a == 0 and b == 0)
				break;	

			int n2;
			scanf(" %s%n", companhia, &n2);
			n2--;

			int c = 0;
			for(int i=0; i<n2; i++)
				c += (1 << charToInt(companhia[i]));

			matAdj[a-1][b-1] = c;
		}

		floydWarshall(n);
		//printGraph(n);

		while(true){
			scanf("%d %d", &a, &b);
			if(a == 0 and b == 0)
				break;

			if(matAdj[a-1][b-1] == 0)
				printf("-");
			else
				printCharBits(matAdj[a-1][b-1]);
			printf("\n");
		}


		printf("\n");

	}




	return 0;
}