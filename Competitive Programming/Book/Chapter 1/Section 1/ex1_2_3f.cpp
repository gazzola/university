#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int buscaBinaria(vector<int> &v, int x){

	int ini=0, meio, fim=v.size()-1;
	while(ini <= fim){

		meio = (ini+fim)/2;

		if(v[meio] == x)
			return meio;
		else if(v[meio] > x)
			fim = meio-1;
		else
			ini = meio+1;
	}

	return -1;
}


int main(){

	vector<int> v;
	int x;
	while(scanf("%d", &x) != EOF){
		v.push_back(x);
	}
	
	x = 42;
	int i = buscaBinaria(v, x);
	if(i >= 0)
		printf("%d esta na posicao: %d\n", x, i);
	else
		printf("%d nao esta no vetor\n", x);
}