#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <vector>
#include <deque>
#include <queue>

using namespace std;


typedef pair<int, int> ii;
typedef struct triple{

	int first, second, third;

	triple(){}
	triple(int f, int s, int t){
		first = f;
		second = s;
		third = t;
	}

}triple;


const ii NONE = ii(-1,-1);

char toNaipe(int naipe){
	if(naipe == 0)
		return 'C';

	if(naipe == 1)
		return 'D';

	if(naipe == 2)
		return 'H';

	return 'S';
}

int getNaipe(char naipe){
	if(naipe == 'C')
		return 0;

	if(naipe == 'D')
		return 1;

	if(naipe == 'H')
		return 2;

	return 3;
}


int proxJogador(int i, int p, bool sentido){
	if(sentido){
		i++;
		i = i % p;
	}
	else{
		i--;
		i = (i == -1) ? p-1 : i;
	}

	return i;
}

ii popSaque(queue<ii> &saque){
	ii temp = saque.front();
	saque.pop();
	return temp;
}

bool ehMaior(ii i, ii j){
	if(i.first != j.first)
		return (i.first >= j.first);
	return (i.second >= j.second); 
}


int verQuemGanhou(vector<ii> *jogadores, queue<ii> &saque, ii descartada, int p){
	
	bool sentido = true; //horario
	int i = 0; // primeiro jogador
	//triple ant = triple(descartada.first, descartada.second, 0);
	
	if(descartada.first == 12){ 	// inverte sentido
		sentido = !sentido;
	}
	else if(descartada.first == 7){ // saca 2 cartas e pula a vez
		ii nova = popSaque(saque);
		jogadores[i].push_back(nova);
		
		nova = popSaque(saque);
		jogadores[i].push_back(nova);
		
		i = proxJogador(i, p, sentido);
	}
	else if(descartada.first == 1){ // saca 1 carta e pula a vez
		ii nova = popSaque(saque);
		jogadores[i].push_back(nova);
		
		i = proxJogador(i, p, sentido);
	}
	else if(descartada.first == 11){ // so pula a vez
		i = proxJogador(i, p, sentido);
	}


	//int x = 10;
	bool debug = false;

	if(debug)
		printf("%d: %d %c\n", i, descartada.first, toNaipe(descartada.second));


	while(true){

		int old = i;
		int maior = 0;
		bool first = true;
		bool ok = false;
		
		for(int j=0; j<(int) jogadores[i].size(); j++){
			if(jogadores[i][j].first == descartada.first or jogadores[i][j].second == descartada.second){

				if(ehMaior(jogadores[i][j], jogadores[i][maior])){
					maior = j;
				}

				if(first == true){
					maior = j;
					first = false;
				}
				
				ok = true;
			}
		}

		ii proxCarta = NONE;

		if(!ok){

			if(!saque.empty()){
				ii nova = popSaque(saque);
				jogadores[i].push_back(nova);

				int t = jogadores[i].size() - 1;
				if(jogadores[i][t].first == descartada.first or jogadores[i][t].second == descartada.second){
					ok = true;
					maior = t;
				}
			}

		}
		
		if(ok){
			proxCarta = jogadores[i][maior];
			jogadores[i].erase(jogadores[i].begin()+maior);

			int k = proxJogador(i, p, sentido);
			if(proxCarta.first == 12){
				sentido = !sentido;
				//i = proxJogador(i, p, sentido);
			}
			else if(proxCarta.first == 7){
				if(!saque.empty()){
					ii nova = popSaque(saque);
					jogadores[k].push_back(nova);
				}
				if(!saque.empty()){
					ii nova = popSaque(saque);
					jogadores[k].push_back(nova);
				}
				i = k;
			}
			else if(proxCarta.first == 1){
				if(!saque.empty()){
					ii nova = popSaque(saque);
					jogadores[k].push_back(nova);
				}
				i = k;
			}
			else if(proxCarta.first == 11){
				i = k;
			}
		}
	

		if(proxCarta != NONE)
			descartada = proxCarta;

		if(debug)
			printf("%d: %d %c\n", old, descartada.first, toNaipe(descartada.second));

		if(jogadores[old].size() == 0)
			return old;
		
		i = proxJogador(i, p, sentido);
		
	}


	return 0;
}


int main(){
 
	
	int p, m, n, valor;
	char c;


	while(scanf("%d %d %d", &p, &m, &n) and n > 0){


		vector<ii> jogadores[12];
		queue<ii> saque;

		for(int i=0; i<p; i++){
			for(int j=0; j<m; j++){
				scanf("%d %c", &valor, &c);
				jogadores[i].push_back(ii(valor, getNaipe(c)));

			}
		}

		scanf("%d %c", &valor, &c);
		ii descartada = ii(valor, getNaipe((int) c));
	

		for(int i=p*m + 1; i<n; i++){
			scanf("%d %c", &valor, &c);
			saque.push(ii(valor, getNaipe((int) c)));

		}



		int ganhador = verQuemGanhou(jogadores, saque, descartada, p);
		printf("%d\n", ganhador+1);
		//w++;
		//break;


	}

 
	return 0;
}