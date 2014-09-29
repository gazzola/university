#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;


void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}


int contarConvidados(vector< deque<int> > &convites){

	int count = 1;

	bool visitados[1001];
	memset(visitados, false, sizeof(visitados));
	visitados[1] = true;

	deque<int> fila = convites[1];

	while(!fila.empty()){

		int prox = fila.front();
		fila.pop_front();
		
		if(!visitados[prox]){
			visitados[prox] = true;
			count++;
		}

		int tam = convites[prox].size();
		for(int i=0; i<tam; i++)
			if(!visitados[convites[prox][i]])
				fila.push_front(convites[prox][i]); //lifo
	}


	return count;

}


int main(){
	

	int n;
	while(scanf("%d\n", &n) and n > 0){

		vector< deque<int> > convites(1001);
		
		while(n--){

			int x, y;
			scanf("(%d,%d) ", &x, &y);

			convites[x].push_back(y);
			convites[y].push_back(x);
		}

		printf("%d\n", contarConvidados(convites));

	}	

	
	return 0;
}