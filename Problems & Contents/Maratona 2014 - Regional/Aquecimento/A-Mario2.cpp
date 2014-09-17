/*
*
* File: Problema A - Mario 2
* Author: Marcos V. Treviso
*
* Complexity: O(n^2 log n)
* Algoritmo de forca bruta
*
* Description: 
*	- Numero minimo de trocar para ter N armarios
	  consecutivos disponiveis.
*
* Compile: g++ -o teste A-Mario2.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;


void printVector(vector<int> &livres){
	for(unsigned int i=0; i<livres.size(); i++)
		printf("%d | ", livres[i]);
	printf("\n");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void maiorSeq(vector<int> &armario, int *maior, int *start, int *end){

	int qtd = 0;
	int tam = armario.size();
	bool foi = false;

	for(int i=1; i<tam; i++){

		if(armario[i-1] == armario[i]-1){
			qtd++;
		}
		else{

			if(qtd >= *maior){
				*maior = qtd;
				*start = i-1-qtd;
				foi = true;
			}

			qtd = 0;
		}

	}

	if(qtd >= *maior){
		*maior = qtd;
		*start = tam-1-qtd;
		foi = true;
	}

	*end = *start + *maior;
	if(foi)
		*maior += 1;
}


int getDir(int *armario, int maior, int start, int ate){
	
	int i = start - 2;
	int j = start + maior + 2;

	if(i < 1)
		i = 1;

	if(j > ate)
		j = ate;

	int dir = i;

	if(armario[i] == 1)
		dir = i;
	else if(armario[j] == 1)
		dir = j;

	return dir;
}


int getMelhorColocacao(vector<int> &armario, int *start, int *end, int *pos){
	
	int i = *start - 2;
	int j = *end + 2;

	int tam = armario.size();

	if(i < 0)
		i = 0;

	if(j > tam-1)
		j = tam-1;

	int melhor = armario[i]+1;
	*pos = i;
	if(armario[i] == armario[*start]-2){
		*pos = i;
		melhor = armario[i]+1;
	}
	else if(armario[j] == armario[*end]+2){
		*pos = j;
		melhor = armario[j]-1;
	}

	return melhor;
}



// left ... start
// end  ... right
int getMaisLonge(vector<int> &armario, int *start, int *end, int melhor){

	int tam = armario.size();

	int left = armario[0];
	int right = armario[tam-1];

	
	if(abs(melhor-left) >= abs(melhor-right)){
		if(left <= armario[*start])
			return 0;
		else if(right > armario[*end])
			return tam-1;
	}
	else{
		if(right >= armario[*end])
			return tam-1;
		else if(left < armario[*start])
			return 0;
	}
	
	
	return 0;
}


int main(){

	int n, l, x;

	while(scanf("%d %d", &n, &l) != EOF){

		vector<int> armario;

		for(int i=0; i<l; i++){
			scanf("%d", &x);
			armario.push_back(x);
		}

		
		//printVector(armario);

		vector<int> livres;
		int maior=1, start=0, end=0;
		maiorSeq(armario, &maior, &start, &end);
		
		//printf("%d %d %d\n", maior, start, end);
		printVector(armario);

		int count = 0;
		int melhor;
		while(maior < n){
			
			int pos;
			melhor = getMelhorColocacao(armario, &start, &end, &pos);
			int index = getMaisLonge(armario, &start, &end, melhor);
			

			//printf("%d %d %d\n", maior, start, end);
			//printf("%d %d %d\n\n", melhor, pos, index);

			armario.erase(armario.begin()+index);
			armario.push_back(melhor);
			sort(armario.begin(), armario.end());

			printVector(armario);
			//printf("\n");


			if(melhor < start)
				start--;
			else if(melhor > end)
				end++;

			pos--;
			int x = pos-1;
			int y = pos+1;
			int tam = armario.size();
			if(x < 0 or y >= tam)
				maior++;
			else{
				if(armario[x] == armario[pos]-1 and armario[y] == armario[pos]+1)
					maior += 2;
				else
					maior++;
			}

			

			count++;
		}

		printf("%d\n\n", count);


	
	}



	return 0;
}