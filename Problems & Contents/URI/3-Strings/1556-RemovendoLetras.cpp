#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <cmath>
#include <deque>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>



using namespace std;


typedef pair<int, string> is;


char matAdj[1001][1001];


int ctoi(char c){
	return (int) c - 'a';
}

char itoc(int i){
	return (char) i + 'a';
}



struct lessAdj{
	bool operator()(const is &lhs, const is &rhs) const{
		return (lhs.second > rhs.second);
	}
};





void bfs(char *seq, int n){

	set<char> letras;
	set<char>::iterator it;
	priority_queue<is, vector<is>, lessAdj > fila;
	unordered_map<string, int> vis;
	
	int posicoes[30];


	for(int i=0; i<30; i++)
		posicoes[i] = 99999;


	for(int i=0; i<n; i++){
		letras.insert(seq[i]);
		int k = ctoi(seq[i]);
		posicoes[k] = min(posicoes[k], i); 
	}


	
	string f;
	
	for(it=letras.begin(); it!=letras.end(); ++it){

		char c = *it;
		int k = posicoes[ctoi(c)];

		string s;
		s.push_back(seq[k]);

		fila.push(is(k, s));
		vis[s] = 1;

		while(!fila.empty()){

			is aux = fila.top();
			fila.pop();

			int u = aux.first;
			cout << aux.second << endl;

			for(int v=u+1; v<n; v++){
				f = aux.second+seq[v];
				if(matAdj[u][v] != '0' and vis.find(f) == vis.end()){
					fila.push(is(v, f));
					vis[f] = 1;
				}
			}
		}

	}

}



int main(){

	char seq[1005];
	int n;

	int x, y;
	for(x=0; x<1001; x++)
		for(y=x+1; y<1001; y++)
			matAdj[x][y] = '1';

	while(scanf("%s%n\n", seq, &n) != EOF){
		bfs(seq, n);
		cout << endl;
	}


	return 0;
}