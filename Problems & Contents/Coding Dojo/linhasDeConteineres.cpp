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
	ii melhorTroca = ii(-1, -1);
	ii primeiraTroca = ii(-1, -1);

	for(int i=1; i<numColunas; i++){
		if(matrix[l][ultimo] > matrix[l][i]){ //1, 4, 3, 2

			if(primeiraTroca.first == -1)
				primeiraTroca == ii(ultimo, i);

			//(2-1)%numColunas == ultimo
			// e
			//(4-1)%numColunas == pos(2)

			int atual = matrix[l][i];
			int ult = matrix[l][ultimo];

			if(((atual-1)%numColunas == ultimo) && ((ult-1)%numColunas == i)){
				melhorTroca = ii(ultimo, i);
				return melhorTroca;
			}
			
		}
		else
			ultimo = i;
	}


	return primeiraTroca;
}

ii colunaCorreta(int c, int numLinhas, int numColunas){

	int ultimo = 0;
	ii melhorTroca = ii(-1, -1);
	ii primeiraTroca = ii(-1, -1);

	for(int i=1; i<numLinhas; i++){
		if(matrix[ultimo][c] > matrix[i][c]){



			/*
			
			1 3 2
			7 8 9
			4 5 6

			1
			13
			9
			5
			17

			*/


			if(primeiraTroca.first == -1)
				primeiraTroca == ii(ultimo, i);

			// ultimo*c + 1 == matrix[i][c] 
			// e
			// i*c + 1 == matrix[ultimo][c]

			int atual = matrix[i][c];
			int ult = matrix[ultimo][c];

			if(((ultimo*numColunas + 1) == atual) && ((i*numColunas + 1) == ult)){
				melhorTroca = ii(ultimo, i);
				return melhorTroca;
			}
			
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


void printMatriz(int c, int l){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	printf("\n---\n\n");
}


int main(){


	
	int ultimos[301];
	int l,c;
	int count=0;

	while(scanf("%d %d", &l, &c) != EOF){


		bool ok = true;
		int menor, maior;
		int linhaDoUm=0, colunaDoUm=0;

		for(int i=0; i<c; i++)
			ultimos[i] = -1;

		for(int i=0; i<l; i++){

			menor = 99999; //300*300
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

		//nao ta ok se:
		//por linhas = maior - menor tem q ser igual ao C-1
		//por colunas = se somatorio de (num % C) tem q ser igual a (j+1)*C 
		//por colunas = se ultimo (num%c) for diferente do atual


		printf("%d: ", ++count);
		int iters = 0;

		if(!ok){
			printf("*\n");
		}
		else{
			//ve qtas mudancas tem q fazer
			
			//minha ideia:
			//primeiro sempre troca a primeira linha pela linha q tem o 1
			//depois troca as colunas ate o 1 ser o primeiro elemento da matriz
			//assim tu garante q a primeira linha e a primeira coluna consequentemente ta ok
			//dae depois verifica a proxima linha e coluna disponivel
			//ou seja, vai pegando sempre elementos da diagonal principal

			if(linhaDoUm > 0){
				inverteLinhas(0, linhaDoUm, c);
				iters++;
			}

			if(colunaDoUm > 0){
				inverteColunas(0, colunaDoUm, l);
				iters++;
			}


			int k = 0;

			while(true){ //vai so ate o penultimo elemento da dp

				ii linc = linhaCorreta(k, c);
				if(linc.first >= 0){
					inverteColunas(linc.first, linc.second, l);
					iters++;
				}
				else{ // se td tiver correto com a linha, comeca a ver a coluna
					ii colc = colunaCorreta(k, l, c);
					if(colc.first >= 0){
						inverteLinhas(colc.first, colc.second, c);
						iters++;
					}
					else //se td certo oom as colunas tbm, a matriz final ta correta, pois os casos impossiveis ja foram tirados no comeco
						break;
				}
			}



			printf("%d\n", iters);
			//printMatriz(l, c);

			//if(count == 9)
			//	break;
		}

	}


	/*
	

	TESTAR ESSES 2 CASOS:

	1 10
	10 1 4 9 2 8 7 5 3 6
	

	10 1
	4
	10
	7
	6
	9
	3
	8
	5
	2
	1
	
	--------------------

	13 15 14 16
	05 07 06 08
	09 11 10 12
	01 03 02 04
	17 19 18 20
	
	primeira troca: linha q tem o 1

	01 03 02 04
	05 07 06 08
	09 11 10 12
	13 15 14 16
	17 19 18 20

	segunda troca: linha nao precisa trocar, coluna sim
	
	01 02 03 04
	05 06 07 08
	09 10 11 12
	13 14 15 16
	17 18 19 20

	*/


	return 0;
}