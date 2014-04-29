#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

int inverter(int n){
	int reverse = 0;
	while(n != 0){
		reverse = reverse*10 + n%10;
		n /= 10;
	}

	return reverse;
}


int main(){

	int t, a, b;
	
	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &a, &b);

		if(a == b){
			printf("0\n");
			continue;
		}
		else{
			
			bool visitados[11000];
			queue<ii> fila;
			memset(visitados, false, sizeof(visitados));
			fila.push(ii(a, 0));

			while(!fila.empty()) {
				ii u = fila.front();
				fila.pop();

				if(u.first < 11000 && !visitados[u.first]){ 
					visitados[u.first] = true;

					if(u.first == b) {
						printf("%d\n", u.second);
						break;
					}

					fila.push(ii(u.first+1, u.second+1));
					fila.push(ii(inverter(u.first), u.second+1));
				}
			}
		}


	}

	return 0;
}
