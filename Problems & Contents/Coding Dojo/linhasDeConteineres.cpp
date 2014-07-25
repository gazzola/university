/*
* Resolucao exercicio do Coding Dojo 2014 - SACTA
* Complexidade do algoritmo: O(L*C)
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


typedef pair<int, int> ii;
int matrix[301][301];


//se o ultimo for igual ao atual, esta ok

// 1 2 3
// 5 4 6
// ^

// 1 mod 3 = 1 
// 5 mod 3 = 2 -> como 1 != 2, entao esses elementos nao podem estar na mesma coluna
bool verColuna(int ultimo, int atual){
	return (ultimo == atual);
}



//se o (maior - menor) elemento da linha for igual ao (numero de colunas - 1), esta ok 

// 1 5 3 <
// 4 2 6

// maior = 5
// menor = 1
// c = 3 [num de  colunas]
// 5-1 != 3-1, entao esses elementos nao podem estar na mesma linha
bool verLinha(int maior, int menor, int c){
	return (maior-menor == c-1);
}



// verifica se a linha l esta com os elementos corretos, ou seja, se eles estao ordenados, 
// pois a verificacao de impossibilidade ja foi feita pelas funcoes acima

// se nao existe mais trocas possiveis, retorna (-1, -1)
// c.c eh retornado as colunas que devem ser trocadas (col1, col2)

ii linhaCorreta(int l, int numColunas){
	int ultimo = 0;
	ii primeiraTroca = ii(-1, -1);

	for(int i=1; i<numColunas; i++){
		if(matrix[l][ultimo] > matrix[l][i]){ 

			//1  4  3  2
			//   ^     ^
			//  ult  atual

			//(2-1)%numColunas == ultimo
			// e
			//(4-1)%numColunas == pos(2)

			int ult = matrix[l][ultimo];
			int atual = matrix[l][i];

			if(primeiraTroca.first == -1)
				if(((atual-1)%numColunas == ultimo) || ((ult-1)%numColunas == i))
					primeiraTroca = ii(ultimo, i); //primeira troca possivel

			if(((atual-1)%numColunas == ultimo) && ((ult-1)%numColunas == i))
				return ii(ultimo, i); //melhor troca possivel, substitui 2 elementos pra suas posicoes corretas
			
		}
		else
			ultimo = i;
	}


	return primeiraTroca;
}


// verifica se a coluna c esta com os elementos corretos, ou seja, se eles estao ordenados, 
// pois a verificacao de impossibilidade ja foi feita pelas funcoes acima

// se nao existe mais trocas possiveis, retorna (-1, -1)
// c.c eh retornado as linhas que devem ser trocadas (lin1, lin2)


ii colunaCorreta(int c, int numLinhas, int numColunas){

	int ultimo = 0;
	ii primeiraTroca = ii(-1, -1);

	for(int i=1; i<numLinhas; i++){
		if(matrix[ultimo][c] > matrix[i][c]){


			/*
			1 
			7 < ult
			4 < atual
			*/

			// ultimo*c + 1 == matrix[i][c] 
			// e
			// i*c + 1 == matrix[ultimo][c]

			int ult = matrix[ultimo][c];
			int atual = matrix[i][c];


			if(primeiraTroca.first == -1)
				if(((ultimo*numColunas + 1) == atual) || ((i*numColunas + 1) == ult))
					primeiraTroca = ii(ultimo, i); //primeira troca possivel

			if(((ultimo*numColunas + 1) == atual) && ((i*numColunas + 1) == ult))
				return ii(ultimo, i); //melhor troca possivel, substitui 2 elementos pra suas posicoes corretas
			
		}
		else
			ultimo = i;
	}

	return primeiraTroca;
}




// se analisar o fato de so mexer na linha 0 e coluna 0
// poderiamos optar por so inverter os elementos especificados
// nesses indicies, ou seja, gastariamos O(1) para isso
// porem, como a impressao da matriz foi importante para a compreensao,
// foi optado por deixar a inversao completa

// funcao para inverter duas linhas da matriz
void inverteLinhas(int l1, int l2, int numColunas){
	int temp;
	for(int i=0; i<numColunas; i++){
		temp = matrix[l1][i];
		matrix[l1][i] = matrix[l2][i];
		matrix[l2][i] = temp;
	}
}


// funcao para inverter duas colunas da matriz
void inverteColunas(int c1, int c2, int numLinhas){
	int temp;
	for(int i=0; i<numLinhas; i++){
		temp = matrix[i][c1];
		matrix[i][c1] = matrix[i][c2];
		matrix[i][c2] = temp;
	}
}


// simples lacos para exibicao da matriz
void printMatriz(int l, int c){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	printf("\n------------------------\n\n");
}



int main(){

	int ultimos[301]; //vetor para verificar integridade das colunas
	int l,c; //linhas, colunas
	int count=0;

	while(scanf("%d %d", &l, &c) != EOF){


		bool ok = true;
		int menor, maior;
		int linhaDoUm=0, colunaDoUm=0;


		// preenche o vetor com os ultimos elementos da coluna i
		for(int i=0; i<c; i++)
			ultimos[i] = -1;


		// le os elementos e verifica os casos de impossibilidade
		for(int i=0; i<l; i++){

			menor = 99999; //300*300
			maior = -1;
			
			for(int j=0; j<c; j++){
				scanf("%d", &matrix[i][j]);


				// pega os indicies do elemento 1, ja que eh ele que vamos mover primeiramente
				// alem do 1, poderia ser tambem o ultimo valor, que eh igual a l*c
				if(matrix[i][j] == 1){
					linhaDoUm = i;
					colunaDoUm = j;
				}


				// define o primeiro valor das colunas da primeira linha no vetor
				int atual = matrix[i][j] % c;
				if(ultimos[j] == -1)
					ultimos[j] = atual;
				else{

					// faz a verificacao da integridade da coluna j 
					if(!verColuna(ultimos[j], atual))
						ok = false;
				}
				
				// pega menor elemento
				if(matrix[i][j] < menor)
					menor = matrix[i][j];
				
				// pega maior elemento
				if(matrix[i][j] > maior)
					maior = matrix[i][j];
			}

			// verificado a integridade da linha i, atraves do maior e menor calculados no `for` acima
			if(!verLinha(maior, menor, c))
				ok = false;
		}

		//nao ta ok se:
		//por linhas = maior - menor tem q ser igual ao C-1
		//por colunas = se somatorio de (num % C) tem q ser igual a (j+1)*C 
		//por colunas = se ultimo (num%c) for diferente do atual


		printf("Teste %d: ", ++count);
		int trocas = 0;

		if(!ok){
			printf("*\n");
		}
		else{
			//ve qtas mudancas tem q fazer
			
			//minha ideia:
			//primeiro sempre troca a primeira linha pela linha q tem o 1
			//depois troca as colunas ate o 1 ser o primeiro elemento da matriz
			//assim tu garante q a primeira linha e a primeira coluna consequentemente ta ok
			//dae depois verifica todos elementos da primeira linha e da primeira coluna


			// faz a inversao da linha/coluna do elemento 1 para a posicao inical (0,0)
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

				// verifica se deve-se inverter as colunas e faz a devida inversao
				ii linc = linhaCorreta(posicaoInicial, c);
				if(linc.first >= 0){
					inverteColunas(linc.first, linc.second, l);
					trocas++;
				}
				else{ // se td tiver correto com a linha, comeca a ver a coluna
					ii colc = colunaCorreta(posicaoInicial, l, c);
					if(colc.first >= 0){
						inverteLinhas(colc.first, colc.second, c);
						trocas++;
					}
					else 		//se td certo oom as colunas tbm, a matriz final ta correta, pois tds trocas possiveis
						break;	//foram feitas e todos os casos impossiveis ja foram tirados no comeco
				}
			}



			printf("%d\n", trocas);
			//printMatriz(l, c);

		}

	}


	/*

	TESTAR ESSES 2 CASOS:   
	
	1 10
	10 1 4 9 2 8 7 5 3 6
	resp: 7

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
	resp: 9
	
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