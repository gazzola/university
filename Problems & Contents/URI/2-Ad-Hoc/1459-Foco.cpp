#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1000000001;


template <class T>
bool orderBy(const pair<T, T> &i, const pair<T, T> &j){
	return i.second < j.second;
}

template <class T>
void printVector(const vector<T> &v){
	for(int i=0; i<v.size(); i++)
		printf("(%d, %d)  ", v[i].first, v[i].second);
 	printf("\n");
}




/*
LEMBRETE:
funciona e eh rapido, porem falha por causa do valores de a e b gigantes
tentar mudar modo de armazenar o valor anterior
*/

/*
int minimoFotos(vector<ii> &focos, ii inicial, ii ultimo){

	vector<int> focosAnt(ultimo.first+1); //leeeeento

	int n = focos.size();
	focosAnt[inicial.first] = inicial.second;
	focosAnt[ultimo.first] = ultimo.second;

	for(int i=0; i<n; i++){
		if(focos[i].second > focosAnt[focos[i].first])
			focosAnt[focos[i].first] = focos[i].second;
	}


	int count = 1;
	int prox = inicial.second+1;
	while(focosAnt[prox] != 0){

		count++;
		prox = focosAnt[prox]+1;

		if(prox == ultimo.first){
			count++;
			break;
		}

	}

	return count;
}
*/


//(1, 2)  (1, 3)  (3, 4)  (1, 5)  (5, 6)  (5, 7)  (1, 8)  (5, 10)
// (2, 3) (4, 5) (6, 7) (8, 9)

// estrategia trivial, ordenar e pegar o maior valor de seconds possiveis
// tal que esse valor de second seja o maior dos firsts encontrados
// onde cada troca de maior valor, quer dizer que mais uma foto foi
// adicionada a ao foco.

int minimoFotos2(vector<ii> &focos){

	int count = 0, maior = 0;
	int n = focos.size();

	for(int i=0; i<n; i++){
		if(focos[i].first > maior){
			count++;
			maior = focos[i].second;
		}
	}

	return count;
}




int main(){
	
	int n, a, b;

	while(scanf("%d", &n) != EOF){

		vector<ii> focos;
		ii inicial = ii(INF, 0);
		ii ultimo = ii(0, 0);

		for(int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			focos.push_back(ii(a, b));

			if(focos[i].first > ultimo.first)
				ultimo = focos[i];
			else if(focos[i].first == ultimo.first)
				if(focos[i].second > ultimo.second)
					ultimo = focos[i];
		
			if(focos[i].first < inicial.first)
				inicial = focos[i];
			else if(focos[i].first == inicial.first)
				if(focos[i].second > inicial.second)
					inicial = focos[i];

		}

		//printf("%d %d\n", inicial.first, inicial.second);
		//printf("%d %d\n", ultimo.first, ultimo.second);

		sort(focos.begin(), focos.end(), orderBy<int>);
		//printVector(focos);

		//int mf = minimoFotos(focos, inicial, ultimo);
		int mf = minimoFotos2(focos);

		printf("%d\n", mf);	

	}

	
	return 0;
}