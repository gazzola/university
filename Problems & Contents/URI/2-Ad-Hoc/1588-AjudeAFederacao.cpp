#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


typedef struct _times{
	int pontos;
	int vitorias;
	int aparicao;
	int gols;
	char nome[22];
}times;


static int count = 0;	// so para testar mesmo

bool ordenarPorPontos(const times &i, const times &j){
	
	::count++;

	if(i.pontos > j.pontos)
		return true;
	else if(i.pontos < j.pontos)
		return false;
	
	if(i.vitorias > j.vitorias)
		return true;
	else if(i.vitorias < j.vitorias)
		return false;

	if(i.gols > j.gols)
		return true;
	else if(i.gols < j.gols)
		return false;

	return (i.aparicao < j.aparicao);

}

struct char_cmp{ 
	bool operator ()(const char *a,const char *b) const{
		return strcmp(a,b)<0;
	} 
};


int main(){
	
	int t, n, m;
	int golsA, golsB;
	char timeA[22], timeB[22];


	scanf("%d", &t);
	while(t--){

		map<char*, int, char_cmp> posicaoPartidas;
		vector<times> partidas;

		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++){
			
			char *nome = (char*) malloc (22);
			scanf("%s", nome);
			posicaoPartidas[nome] = i;
			
			times *timeX = (times*) malloc(sizeof(times));
			timeX->pontos = 0;
			timeX->vitorias = 0;
			timeX->gols = 0; 
			timeX->aparicao = i;
			strcpy(timeX->nome, nome);

			partidas.push_back(*timeX);
		}

		while(m--){
			scanf("%d %s %d %s", &golsA, timeA, &golsB, timeB);
			
			int posA = posicaoPartidas[timeA];
			int posB = posicaoPartidas[timeB];

			if(golsA > golsB){
				partidas[posA].pontos += 3;
				partidas[posA].vitorias += 1;
			}
			else if(golsA < golsB){
				partidas[posB].pontos += 3;
				partidas[posB].vitorias += 1;
			}
			else{
				partidas[posA].pontos += 1;
				partidas[posB].pontos += 1;
			}

			partidas[posA].gols += golsA;
			partidas[posB].gols += golsB;
		}

		sort(partidas.begin(), partidas.end(), ordenarPorPontos);

		//printf("count:%d\n", ::count); apenas brincando com escopos

		for(int i=0; i<n; i++)
			printf("%s\n", partidas[i].nome);
	}


	return 0;
}