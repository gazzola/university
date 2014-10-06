#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> ii;


// faz uma busca em largura
bool verificar(int n, int m){

	queue<ii> lista;
	lista.push(ii(0, 1));

	while(!lista.empty()){

		ii atual = lista.front();
		lista.pop();

		// se chegou na posicao m, fechou o pastel
		if(atual.first == m)
			return true;


		// pra frente
		int pos = atual.first + 2*atual.second - 1;
		if(pos <= n)
			lista.push(ii(pos, atual.second+1));
		

		// pra tras
		pos = atual.first - (2*atual.second - 1);
		if(pos > 0)
			lista.push(ii(pos, atual.second+1));

	}

	return false;
}


int main(){
 
	int n, m;

	while(scanf("%d %d", &n, &m) and n > 0){

		if(n >= 49)
			printf("Let me try!\n");
		else{
			if(verificar(n, m))
				printf("Let me try!\n");
			else
				printf("Don't make fun of me!\n");
		}

	}
 
	return 0;
}