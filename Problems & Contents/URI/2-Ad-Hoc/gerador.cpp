#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int k = 10;

	while(k--){


		int a,b,c;
		a = (rand()%100)+2;
		
		printf("%d\n", a);

		bool visitados[101][101];
		for(int i=0; i<101; i++)
			for(int j=0; j<101; j++)
				visitados[i][j] = false;

		for(int i=0; i<a; i++){
			
			int x = (rand()%10)+1;
			int y = (rand()%10)+1;

			if(!visitados[x][y]){
				printf("(%d,%d)", x, y);
				if(i < a-1)
					printf(" ");
			}
		}

		printf("\n");

	}

	printf("0\n");

	return 0;
}

