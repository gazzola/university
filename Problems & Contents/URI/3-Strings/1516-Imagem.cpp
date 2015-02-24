#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int ctoi(char c){
	return (int) c - 'A';
}


int main(){

	int n, m, a, b;
	char mat[100][100];

	while(scanf("%d %d\n", &n, &m) and n > 0){


		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				scanf("%c", &mat[i][j]);
			scanf("\n");
		}

		scanf("%d %d", &a, &b);
		n = a/n;
		m = b/m;

		for(int i=0; i<a; i++){
			for(int j=0; j<b; j++)
				printf("%c", mat[i/n][j/m]);
			printf("\n");
		}

		printf("\n");

	}


	return 0;
}