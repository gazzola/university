#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>


using namespace std;

const int INF = 999999;


int main(){

	int n, x, p;
	bool fila, pilha, prior;

	while(scanf("%d", &n) != EOF){

		deque<int> entradaFila;
		deque<int> entradaPilha;
		priority_queue<int> entradaPrior;

		fila = pilha = prior = true;

		while(n--){
			scanf("%d %d", &p, &x);
			if(p == 1){
				entradaFila.push_back(x);
				entradaPilha.push_back(x);
				entradaPrior.push(x);				
			}
			else{

				if(fila and entradaFila.size() > 0){
					if(entradaFila.front() == x)
						entradaFila.pop_front();
					else
						fila = false;
				}
	
				if(pilha and entradaPilha.size() > 0){
					if(entradaPilha.back() == x)
						entradaPilha.pop_back();
					else
						pilha = false;
				}
		
				if(prior and entradaPrior.size() > 0){
					if(entradaPrior.top() == x)
						entradaPrior.pop();
					else
						prior = false;
				}
				
			}
		}


		if(fila and !pilha and !prior)
			printf("queue\n");
		else if(!fila and pilha and !prior)
			printf("stack\n");
		else if(!fila and !pilha and prior)
			printf("priority queue\n");
		else if(!fila and !pilha and !prior)
			printf("impossible\n");
		else
			printf("not sure\n");

	}


	return 0;
}