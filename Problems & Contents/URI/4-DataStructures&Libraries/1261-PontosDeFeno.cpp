#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main(){

	int m, n;
	while(scanf("%d %d\n", &m, &n) != EOF){

		map<string, int> cargos;

		string s;
		int x;

		while(m--){
			cin >> s >> x;
			cargos[s] = x;
		}

		while(n--){
			int total = 0;
			while(cin >> s and s != ".")
				total += cargos[s];
			printf("%d\n", total);
		}


	}



	return 0;
}