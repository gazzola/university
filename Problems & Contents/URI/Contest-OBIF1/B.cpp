#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;



int dfs(vector<int> *listaAdj, vector<string> &letras){

	


}



int main(){

	int n, a, b;
	vector<int>[20000] listaAdj;
	vector<string> letras;
	char s[1001];

	scanf("%d %d\n", &n, &l);

	while(n--){
		scanf("%s", s);
		letras.push_back(string(s));
	}

	n = letras.seize()*2 - 1;
	while(n--){
		scanf("%d %d", &a, &b);
		listaAdj[a].push_back(b);
	}

	return 0;
}
