#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, int> ii;
const ii NONE = ii(-1, -1);

char toNaipe(int naipe){
	if(naipe == 0)
		return 'C';

	if(naipe == 1)
		return 'D';

	if(naipe == 2)
		return 'H';

	return 'S';
}


int getPos(ii carta){
	return carta.second*13 + carta.first;
}

int getNaipe(int naipe){
	if(naipe == (int)'C')
		return 0;

	if(naipe == (int)'D')
		return 1;

	if(naipe == (int)'H')
		return 2;

	return 3;
}


int getMaior(int valor){
	return valor+39;
}

//
// 0 | 1 2 3 4 5 6 7 8 9 10 11 12 13 | 14 15 16 17 18 19 20 21 22 23 24 25 26 | 27 28 29 30 31 32 33 34 35 36 37 38 39 | 40 41 42 23 44 45 46 47 48 49 50 51 52

int getPosNaipe(int naipe){
	int pos = 1;
	switch(naipe){
		case 1:
			pos = 14;
			break;
		case 2:
			pos = 27;
			break;
		case 3:
			pos = 40;
			break;
		default:
			pos = 1;
	}

	return pos;
}


ii descartar(int *cartas, ii descartada){
	int maior = getMaior(descartada.first);

	// max 4 iteracoes
	ii seila = NONE;
	for(int i=maior; i>=1; i-=13){
		if(cartas[i] == 1){
			cartas[i] = 0;
			//printf("%d %d\n", descartada.first, (int) i/13);
			seila = ii(descartada.first, (int) i/13);
			break;
		}
	}

	

	// max 13 iteracoes
	int init = getPosNaipe(descartada.second);
	for(int i=init+12; i>=init; i--){

		int x = ((i-1)%13)+1;
		if(cartas[i] == 1 and x > seila.first){
			cartas[i] = 0;
			
			//printf("%d %d\n", x, descartada.second);
			seila = ii(x, descartada.second);
			break;
		}
	}

	if(seila != NONE)
		cartas[0]--;

	return seila;
}


int novoJogador(int i, int p, bool sentido){
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

int jogAnterior(int i, int p, bool sentido){
	if(sentido){
		i--;
		i = (i == -1) ? p-1 : i;
	}
	else{
		i++;
		i = i % p;
	}

	return i;
}


ii popSaque(deque<ii> &saque){
	ii temp = saque.back();
	saque.pop_back();
	return temp;
}


void decidir(int jogadores[12][56], deque<ii> &saque, ii &descartada, int i){
	
	descartada = NONE;

	ii prox = descartar(jogadores[i], descartada);
	if(prox != NONE){
		jogadores[i][getPos(prox)] = 0;
		descartada = prox;
	}
	else{

		if(!saque.empty()){
			prox = popSaque(saque);
			jogadores[i][getPos(prox)] = 1;

			if(prox != NONE){
				jogadores[i][getPos(prox)] = 0;
				descartada = prox;
			}
		}
	}
}


int getProx(ii descartada){
	if(descartada.first == 12)
		return 12;
	else if(descartada.first == 7)
		return 7;
	else if(descartada.first == 1)
		return 1;
	else if(descartada.first == 11)
		return 11;

	return 0;
}





int verQuemGanhou(int jogadores[12][56], deque<ii> &saque, ii descartada, int p){
	
	bool sentido = true; //horario
	int i = 0; // primeiro jogador
	int prox = 0;

	prox = getProx(descartada);
	//printf("%d: %d %c (%d)\n", i, descartada.first, toNaipe(descartada.second), prox);

	if(prox != 0){

		if(prox == 12){
			sentido = !sentido;
			//printf("aquiiii\n");
			prox = 0;

			/*ii nova = descartar(jogadores[i], descartada);
			if(nova != NONE){
				descartada = nova;
				prox = getProx(descartada);
			}
			else{
				if(!saque.empty()){
					nova = popSaque(saque);
					jogadores[i][getPos(nova)] = 1;
					jogadores[i][0]++;

					if(nova != NONE){
						descartada = nova;
						prox = getProx(descartada);
					}
				}
			}*/
		}
		else if(prox == 7){
			prox = 0;
			if(!saque.empty()){
				ii nova = popSaque(saque);
				jogadores[i][getPos(nova)] = 1;
				jogadores[i][0]++;
			}

			if(!saque.empty()){
				ii nova = popSaque(saque);
				jogadores[i][getPos(nova)] = 1;
				jogadores[i][0]++;
			}
		}
		else if(prox == 1){
			prox = 0;
			if(!saque.empty()){
				ii nova = popSaque(saque);
				jogadores[i][getPos(nova)] = 1;
				jogadores[i][0]++;
			}
		}
		else if(prox == 11)
			prox = 0;
	}
	else{

		ii nova = descartar(jogadores[i], descartada);
		if(nova != NONE){
			descartada = nova;
			prox = getProx(descartada);
		}
		else{
			if(!saque.empty()){
				nova = popSaque(saque);
				jogadores[i][getPos(nova)] = 1;
				jogadores[i][0]++;

				if(nova != NONE){
					descartada = nova;
					prox = getProx(descartada);
				}
			}
		}
	}

	if(prox == 12)
		sentido = !sentido;

	//int last = i;
	//printf(":%d: %d %c\n", i, descartada.first, toNaipe(descartada.second));
	i = novoJogador(i, p, sentido);
	//printf("%d: %d %c (%d)\n", i, descartada.first, toNaipe(descartada.second), prox);



	while(true){

		if(prox != 0){

			if(prox == 12){
				//sentido = !sentido;
				//printf("aquiiii\n");
				prox = 0;

				/*ii nova = descartar(jogadores[i], descartada);
				if(nova != NONE){
					descartada = nova;
					prox = getProx(descartada);
				}
				else{
					if(!saque.empty()){
						nova = popSaque(saque);
						jogadores[i][getPos(nova)] = 1;
						jogadores[i][0]++;

						if(nova != NONE){
							descartada = nova;
							prox = getProx(descartada);
						}
					}
				}*/

			}
			else if(prox == 7){
				prox = 0;
				if(!saque.empty()){
					ii nova = popSaque(saque);
					jogadores[i][getPos(nova)] = 1;
					jogadores[i][0]++;
				}

				if(!saque.empty()){
					ii nova = popSaque(saque);
					jogadores[i][getPos(nova)] = 1;
					jogadores[i][0]++;
				}
			}
			else if(prox == 1){
				prox = 0;
				if(!saque.empty()){
					ii nova = popSaque(saque);
					jogadores[i][getPos(nova)] = 1;
					jogadores[i][0]++;
				}
			}
			else if(prox == 11)
				prox = 0;
		}
		else{

			ii nova = descartar(jogadores[i], descartada);
			if(nova != NONE){
				descartada = nova;
				prox = getProx(descartada);
			}
			else{
				if(!saque.empty()){
					nova = popSaque(saque);
					jogadores[i][getPos(nova)] = 1;
					jogadores[i][0]++;

					if(nova != NONE){
						descartada = nova;
						prox = getProx(descartada);
					}
				}
			}

			
		}
		
		if(prox == 12)
			sentido = !sentido;

		//printf(":%d: %d %c\n", i, descartada.first, toNaipe(descartada.second));
		if(jogadores[i][0] == 0)
			return i;

		//last = i;
		i = novoJogador(i, p, sentido);
	}

	//printf(":%d: %d %c\n", i, descartada.first, toNaipe(descartada.second));



	return i;
}


int main(){
 	
	int p, m, n, valor;
	char c;

	while(scanf("%d %d %d", &p, &m, &n) and n > 0){


		int jogadores[12][56];
		memset(jogadores, 0, sizeof(jogadores[0][0])*12*52);
		
		deque<ii> saque;

		for(int i=0; i<p; i++){
			for(int j=0; j<m; j++){
				scanf("%d %c", &valor, &c);

				//printf("%d %c\n", valor, c);
				int pos = getPos(ii(valor, getNaipe((int) c)));
				jogadores[i][pos] = 1;
				jogadores[i][0]++;
			}
		}

		scanf("%d %c", &valor, &c);
		//printf("%d %c\n", valor, c);
		ii descartada = ii(valor, getNaipe((int) c));


		for(int i=p*m + 1; i<n; i++){
			scanf("%d %c", &valor, &c);
			//printf("%d %c\n", valor, c);
			saque.push_back(ii(valor, getNaipe((int) c)));
		}



		int ganhador = verQuemGanhou(jogadores, saque, descartada, p);
		printf("%d\n", ganhador+1);
		//break;
	}


	
	return 0;
}