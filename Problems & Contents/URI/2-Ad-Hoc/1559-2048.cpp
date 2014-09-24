#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;
#define TAM 4

bool verificaDown(int mat[TAM][TAM]){
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM-1; j++){
			if(mat[j][i]>0 and mat[j+1][i]==0)
				return true;
			else if(mat[j][i] == mat[j+1][i] and mat[j][i] > 0)
				return true;
		}
	}

	return false;
}


bool verificaLeft(int mat[TAM][TAM]){
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM-1; j++){
			if(mat[i][j]==0 and mat[i][j+1]>0)
				return true;
			else if(mat[i][j] == mat[i][j+1] and mat[i][j] > 0)
				return true;
		}
	}

	return false;
}


bool verificaRight(int mat[TAM][TAM]){

	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM-1; j++){
			if(mat[i][j]>0 and mat[i][j+1]==0)
				return true;
			else if(mat[i][j] == mat[i][j+1] and mat[i][j] > 0)
				return true;
		}
	}

	return false;
}

bool verificaUp(int mat[TAM][TAM]){
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM-1; j++){
			if(mat[j][i]==0 and mat[j+1][i]>0)
				return true;
			else if(mat[j][i] == mat[j+1][i] and mat[j][i] > 0)
				return true;
		}
	}

	return false;
}

void verifica(int mat[TAM][TAM], bool &down, bool &left, bool &right, bool &up){
	down = verificaDown(mat);
	left = verificaLeft(mat);
	right = verificaRight(mat);
	up = verificaUp(mat);
}

void printVals(bool &down, bool &left, bool &right, bool &up){
	if(down)
		printf("DOWN");

	if(left){
		if(down)
			printf(" ");
		printf("LEFT");
	}

	if(right){
		if(down or left)
			printf(" ");
		printf("RIGHT");
	}

	if(up){
		if(down or left or right)
			printf(" ");
		printf("UP");
	}

	if(!down and !left and !right and !up)
		printf("NONE");

	printf("\n");
}

int main(){
	

	int n;
	int mat[TAM][TAM];
	bool down, left, right, up, win;

	scanf("%d", &n);
	while(n--){

		down = left = right = up = win = false;
		for(int i=0; i<TAM; i++){
			for(int j=0; j<TAM; j++){
				scanf("%d", &mat[i][j]);
				if(mat[i][j] == 2048)
					win = true;
			}
		}

		if(win){
			printf("NONE\n");
		}
		else{
			verifica(mat, down, left, right, up);
			printVals(down, left, right, up);
		}
	}

	return 0;
}