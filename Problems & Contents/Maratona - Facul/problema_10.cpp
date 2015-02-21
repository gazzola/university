#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


typedef pair<int, int> ii;
int matrix[301][301];

bool verColuna(int ultimo, int atual){
	return (ultimo == atual);
}


bool verLinha(int maior, int menor, int c){
	return (maior-menor == c-1);
}


ii linhaCorreta(int l, int numColunas){
	int ultimo = 0;
	ii primeiraTroca = ii(-1, -1);

	for(int i=1; i<numColunas; i++){
		if(matrix[l][ultimo] > matrix[l][i]){ 

			int ult = matrix[l][ultimo];
			int atual = matrix[l][i];

			if(primeiraTroca.first == -1)
				if(((atual-1)%numColunas == ultimo) || ((ult-1)%numColunas == i))
					primeiraTroca = ii(ultimo, i); 

			if(((atual-1)%numColunas == ultimo) && ((ult-1)%numColunas == i))
				return ii(ultimo, i); 
			
		}
		else
			ultimo = i;
	}


	return primeiraTroca;
}


ii colunaCorreta(int c, int numLinhas, int numColunas){

	int ultimo = 0;
	ii primeiraTroca = ii(-1, -1);

	for(int i=1; i<numLinhas; i++){
		if(matrix[ultimo][c] > matrix[i][c]){

			int ult = matrix[ultimo][c];
			int atual = matrix[i][c];


			if(primeiraTroca.first == -1)
				if(((ultimo*numColunas + 1) == atual) || ((i*numColunas + 1) == ult))
					primeiraTroca = ii(ultimo, i); 

			if(((ultimo*numColunas + 1) == atual) && ((i*numColunas + 1) == ult))
				return ii(ultimo, i); 
			
		}
		else
			ultimo = i;
	}

	return primeiraTroca;
}



void inverteLinhas(int l1, int l2, int numColunas){
	int temp;
	for(int i=0; i<numColunas; i++){
		temp = matrix[l1][i];
		matrix[l1][i] = matrix[l2][i];
		matrix[l2][i] = temp;
	}
}



void inverteColunas(int c1, int c2, int numLinhas){
	int temp;
	for(int i=0; i<numLinhas; i++){
		temp = matrix[i][c1];
		matrix[i][c1] = matrix[i][c2];
		matrix[i][c2] = temp;
	}
}



void printMatriz(int l, int c){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	printf("\n------------------------\n\n");
}



int main(){

	int ultimos[301]; 
	int l,c; 


	while(scanf("%d %d", &l, &c) != EOF){

		bool ok = true;
		int menor, maior;
		int linhaDoUm=0, colunaDoUm=0;

		
		for(int i=0; i<c; i++)
			ultimos[i] = -1;

		
		for(int i=0; i<l; i++){

			menor = 99999; 
			maior = -1;
			
			for(int j=0; j<c; j++){
				scanf("%d", &matrix[i][j]);

				if(matrix[i][j] == 1){
					linhaDoUm = i;
					colunaDoUm = j;
				}
				
				int atual = matrix[i][j] % c;
				if(ultimos[j] == -1)
					ultimos[j] = atual;
				else{

					
					if(!verColuna(ultimos[j], atual))
						ok = false;
				}
				
				
				if(matrix[i][j] < menor)
					menor = matrix[i][j];
				
				
				if(matrix[i][j] > maior)
					maior = matrix[i][j];
			}

			
			if(!verLinha(maior, menor, c))
				ok = false;
		}


		
		int trocas = 0;

		if(!ok){
			printf("*\n");
		}
		else{
			
			if(linhaDoUm > 0){
				inverteLinhas(0, linhaDoUm, c);
				trocas++;
			}

			if(colunaDoUm > 0){
				inverteColunas(0, colunaDoUm, l);
				trocas++;
			}


			int posicaoInicial = 0;

			while(true){

				
				ii linc = linhaCorreta(posicaoInicial, c);
				if(linc.first >= 0){
					inverteColunas(linc.first, linc.second, l);
					trocas++;
				}
				else{ 
					ii colc = colunaCorreta(posicaoInicial, l, c);
					if(colc.first >= 0){
						inverteLinhas(colc.first, colc.second, c);
						trocas++;
					}
					else 		
						break;	
				}
			}



			printf("%d\n", trocas);
			

		}

	}

	return 0;
}