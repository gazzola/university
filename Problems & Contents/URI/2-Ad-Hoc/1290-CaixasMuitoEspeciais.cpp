#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

const int INF = 9999999;
typedef tuple<int, int, int> triple; //C++11


bool encaixa(triple &item, triple &t){
	int x = get<0>(item);
	int y = get<1>(item);
	int z = get<2>(item);

	int tx = get<0>(t);
	int ty = get<1>(t);
	int tz = get<2>(t);


	if(tx >= x and ty >= y and tz >= z)
		return true;
	return false;
}



// int qtd[201][201][201];

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortThreeValues(int *x, int *y, int *z){
	if(*x > *y)
		swap(&(*x), &(*y));

	if(*y > *z)
		swap(&(*y), &(*z));

	if(*x > *y)
		swap(&(*x), &(*y));
}

int main(){
	

	
	int m, n, x, y, z, a, b, c, tx, ty, tz;
	vector<int> item(3);
	vector<int> vet(3);

	while(scanf("%d %d", &n, &m) and n > 0){

		scanf("%d %d %d", &x, &y, &z);
		
		sortThreeValues(&x, &y, &z);
		triple item = triple(x, y, z);
		int v = x*y*z;


		map<triple, int> qtd;
		vector<triple> caixas;

		for(int i=0; i<m; i++){
			
			scanf("%d %d %d", &a, &b, &c);
			sortThreeValues(&a, &b, &c);
			
			triple t = triple(a, b, c);
			qtd[t] += 1;
			caixas.push_back(t);
		}



		int menor = INF;
		for(int i=0; i<(int) caixas.size(); i++){
			
			triple t = caixas[i];
			tx = get<0>(t);
			ty = get<1>(t);
			tz = get<2>(t);

			int k = tx*ty*tz - v;
			if(k < menor and k >= 0 and qtd[t] >= n and encaixa(item, t))
				menor = k;
		}

		if(menor != INF)
			printf("%d\n", menor);
		else
			printf("impossible\n");

	}
	

	
	return 0;
}