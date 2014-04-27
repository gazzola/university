#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

#define LC 10 //c cavalo = 12

char mat[LC][LC];


void printMatriz(char mat[LC][LC]){
	for(int i=1; i<LC-1; i++){
		printf("%d: ", LC-i-1);
		for(int j=1; j<LC-1; j++)
			printf("%c ", mat[i][j]);
		printf("\n");
	}

	printf("   - - - - - - - -\n   ");
	for(int i=1; i<LC-1; i++)
		printf("%c ", i+96);

	printf("\n\n");
}



bool xMate(int x, int y){

	int i, j;

	if(x<1 || y<1 || x>8 || y>8)
		return true;

	//peoes
	if(mat[x-1][y-1] == 'P' || mat[x-1][y+1] == 'P')
		return true;

	//rei
	if(mat[x-1][y-1] == 'W' || mat[x-1][y] == 'W' || mat[x-1][y+1] == 'W' ||
	   mat[x][y-1] == 'W' || mat[x][y+1] == 'W' ||
	   mat[x+1][y-1] == 'W' || mat[x+1][y] == 'W' || mat[x+1][y+1] == 'W')
	   return true;	


	//torre e rainha:
	//--------------------

	//esquerda
	for(i=y-1; i>=1; i--){
		if(mat[x][i] != '0'){
			if(mat[x][i] == 'T' || mat[x][i] == 'R')
				return true;
			else
				break;
		}

	}

	//direita
	for(i=y+1; i<=8; i++){
		if(mat[x][i] != '0'){
			if(mat[x][i] == 'T' || mat[x][i] == 'R')
				return true;
			else
				break;
		}
	}


	//cima
	for(i=x-1; i>=1; i--){
		if(mat[i][y] != '0'){
			if(mat[i][y] == 'T' || mat[i][y] == 'R')
				return true;
			else
				break;
		}
	}

	//baixo
	for(i=x+1; i<=8; i++){
		if(mat[i][y] != '0'){
			if(mat[i][y] == 'T' || mat[i][y] == 'R')
				return true;
			else
				break;
		}
	}

	
	//bispo e rainha
	//---------------
	//superior_esquerda
	for(i=x-1, j=y-1; i>=1 && j>=1; i--, j--){
		if(mat[i][j] != '0'){
			if(mat[i][j] == 'B' || mat[i][j] == 'R'){
				return true;
			}
			else 
				break;
		}
	}

	//superior direita
	for(i=x-1, j=y+1; i>=1 && j<=8; i--, j++){
		if(mat[i][j] != '0'){
			if(mat[i][j] == 'B' || mat[i][j] == 'R')
				return true;
			else 
				break;
		}
	}

	//inferior esquerda
	for(i=x+1, j=y-1; i<=8 && j>=1; i++, j--){
		if(mat[i][j] != '0'){
			if(mat[i][j] == 'B' || mat[i][j] == 'R')
				return true;
			else
				break;
		}
	}

	//inferior direita
	for(i=x+1, j=y+1; i<=8 && j<=8; i++, j++){
		if(mat[i][j] != '0'){
			if(mat[i][j] == 'B' || mat[i][j] == 'R')
				return true;
			else 
				break;
		}
	}

	return false;
}



int main(){
	
	int n;
	while(scanf("%d ", &n) != EOF){

		char peca, c, l;
		int x, y, xrei, yrei;

		memset(mat, '0', sizeof(mat));

		for(int i=0; i<n; i++){
			scanf("%c%c%c ", &peca, &c, &l);
			x = 7-abs(49-l)+1;
			y = abs(97-c)+1;
			mat[x][y] = peca;
		}

		scanf("%c%c%c ", &peca, &c, &l);
		xrei = 7-abs(49-l)+1;
		yrei = abs(97-c)+1;


		if(xMate(xrei-1, yrei-1) && xMate(xrei-1, yrei) && xMate(xrei-1, yrei+1) &&
		   xMate(xrei, yrei-1) && xMate(xrei, yrei) && xMate(xrei, yrei+1) &&
		   xMate(xrei+1, yrei-1) && xMate(xrei+1, yrei) && xMate(xrei+1, yrei+1))
			printf("SIM\n");
		else
			printf("NAO\n");

	}
	

	return 0;
}