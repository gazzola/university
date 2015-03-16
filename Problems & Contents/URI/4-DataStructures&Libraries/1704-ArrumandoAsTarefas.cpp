#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
 
 
using namespace std;
 
typedef pair<int, int> ii;
 
 
bool orderBy(const int &x, const int &y){
	return x > y;
}
 
 
int main(){
 
	int n, h, v, t;
 
	while(scanf("%d %d", &n, &h) != EOF){
 
 
		deque<int> tarefas[1001];
 
		int dinheiro = 0;
		 
		while(n--){
			scanf("%d %d", &v, &t);
			dinheiro += v; 
			tarefas[t].push_back(v);
		}
 
 
		for(int i=1; i<=h; i++)
			sort(tarefas[i].begin(), tarefas[i].end(), orderBy);
 
		 
		for(int i=h; i>0; i--){
 
			int maior = 0;
			int mpos = 0;
 
			for(int j=h; j>=i; j--){
				if(tarefas[j].size() > 0 and tarefas[j].front() > maior){
					maior = tarefas[j].front();
					mpos = j;
				}
			}
 
			if(mpos > 0){
				dinheiro -= maior;
				tarefas[mpos].pop_front();
			}
		}
		 
	 
		 
		printf("%d\n", dinheiro);
	}
 
 
 
	return 0;
}