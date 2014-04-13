#include <iostream>
#include <iomanip>

using namespace std;

int mat[9][9];

bool verificaMatriz(){

	int i, j, pos;

	//linhas
	for(i=0; i<9; i++){
		int vetLinhas[10] = {0,0,0,0,0,0,0,0,0,0};
		for(j=0; j<9; j++){
			pos = mat[i][j];
			if(vetLinhas[pos] == 1)
				return false;
			else
				vetLinhas[pos] = 1;
		}
	}


	//colunas
	for(i=0; i<9; i++){
		int vetColunas[10] = {0,0,0,0,0,0,0,0,0,0};
		for(j=0; j<9; j++){
			pos = mat[j][i];
			if(vetColunas[pos] == 1)
				return false;
			else
				vetColunas[pos] = 1;
		}
	}


	int aux = 0;
	int vetConjuntos[10];
	for(i=0; i<9; i++){
		
		if((i%3) == 0)
			for(int k=0; k<10; k++)
				vetConjuntos[k] = 0;

		int init = aux*3;
		int final = init+3;

		for(j=init; j<final; j++){
			pos = mat[i][j];
			if(vetConjuntos[pos] == 1)
				return false;
			else
				vetConjuntos[pos] = 1;
		}

		if((i+1) % 3 == 0){
			if(aux == 2){
				aux = 0;
			}
			else{
				aux++;
				i-=3;
			}
		}
	}


	return true;
}


int main(){
	
	int n;
	cin >> n;

	for(int i=1; i<=n; i++){

		for(int j=0; j<9; j++)
			for(int k=0; k<9; k++)
				cin >> mat[j][k];


		cout << "Instancia " << i << endl;
		if(verificaMatriz())
			cout << "SIM" << endl;
		else
			cout << "NAO" << endl;

		cout << endl;
	}

	return 0;
}