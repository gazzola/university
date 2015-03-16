#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;



int contaPrefix(string &x, string &y){

	int i=0, t=0;
	while(x[i] == y[i] and i < (int) x.size()){
		i++;
		t++;
	}

	return t;
}



int main(){


	int n;
	string x, y;

	while(scanf("%d\n", &n) != EOF){

		vector<string> lista;

		while(n--){
			cin >> x;
			lista.push_back(x);
		}
		
		sort(lista.begin(), lista.end());

		int qtd = 0;
		for(int i=1; i<(int) lista.size(); i++)
			qtd += contaPrefix(lista[i-1], lista[i]);
		printf("%d\n", qtd);

	}



	return 0;
}