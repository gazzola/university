#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct dot{

	int x, y;

	dot(){}
	dot(int x, int y){
		this->x = x;
		this->y = y;
	};

	bool operator<(const dot &c) const{
		return this->y < c.y;
	};
	
}dot;


dot toVector(dot a, dot b){
	return dot(a.x-b.x, a.y-b.y);
}

int cross(dot a, dot b){
	return a.x*b.y - a.y*b.x;
}

int ccw(dot &a, dot &b){
	return cross(a, b);
}

bool colinear(dot &a, dot &b){
	return cross(a, b) == 0;
}

// functions
template <class T>
void printVector(const vector<T> &vet){
for(int i=0; i<(int) vet.size(); i++)
	cout << vet[i] << " ";
	cout << endl;
}




int buscaQtdParedes(dot eg, vector<dot> &paredes, dot epicentro, int p){

	int ini=0, med=0, fim=p-1;
	int k;
	dot epa, epb, pontoA, pontoB;
	
	// busca binaria para procurar o lower bound
	while(ini <= fim){

		med = (ini+fim)/2;
		epa = toVector(epicentro, dot(0, paredes[med].y));
		epb = toVector(epicentro, dot(0, paredes[med].x));

		if(ccw(epb, eg) > 0 and ccw(epa, eg) < 0)
			break;
		else if(ccw(epb, eg) < 0)
			fim = med-1;
		else
			ini = med+1;

	}


	// da pra fazer com 1 while/for so, mas 2 fica mais simples
	
	int qtd = 0;

	k = med-1;
	while(k > 0){
		epa = toVector(epicentro, dot(0, paredes[k].y));
		epb = toVector(epicentro, dot(0, paredes[k].x));
		if(ccw(epb, eg) > 0 and ccw(epa, eg) < 0){
			k--;
			qtd++;
		}
		else
			break;
	}


	k = med;
	while(k < p){
		epa = toVector(epicentro, dot(0, paredes[k].y));
		epb = toVector(epicentro, dot(0, paredes[k].x));
		if(ccw(epb, eg) > 0 and ccw(epa, eg) < 0){
			k++;
			qtd++;
		}
		else
			break;
	}

	return qtd;
}



int main(){
	
	int t, p, g, sol;
	dot epicentro, eg, epa, epb;

	vector<dot> paredes(10001);
	vector<dot> esconde(10001);

	scanf("%d", &t);
	while(t--){

		sol = 0;
		
		scanf("%d %d", &epicentro.x, &epicentro.y);
		
		scanf("%d", &p);
		for(int i=0; i<p; i++)
			scanf("%d %d", &paredes[i].x, &paredes[i].y);
		
		scanf("%d", &g);
		for(int i=0; i<g; i++)
			scanf("%d %d", &esconde[i].x, &esconde[i].y);

		sort(paredes.begin(), paredes.begin()+p);
		
		for(int i=0; i<g; i++){

			eg = toVector(epicentro, esconde[i]);
			sol += buscaQtdParedes(eg, paredes, epicentro, p);
			
			/*for(int j=0; j<p; j++){

				epa = toVector(epicentro, dot(0, paredes[j].y));
				epb = toVector(epicentro, dot(0, paredes[j].x));

				//printf("%d %d\n", ccw(epa, eg), ccw(epb, eg));
				if(ccw(epa, eg) < 0 and ccw(epb, eg) > 0)
					sol++;
			}*/

		}
		
		printf("%d\n", sol);
	}



	return 0;
}