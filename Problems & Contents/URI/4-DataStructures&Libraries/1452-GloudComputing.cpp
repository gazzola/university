#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> ii;

void printSet(set<ii> &myset){
	set<ii>::iterator it;
	for (it=myset.begin(); it!=myset.end(); ++it)
		cout << ' ' << (*it).first << ":" << (*it).second << endl;
}

void printVector(vector<ii> &v){
	for(int i=0; i<(int) v.size(); i++)
		printf("(%d,%d) ", v[i].first, v[i].second);
 	printf("\n");
}

int main(){
 
	
	int n, m, q;
	char nome[25];
	bool visitados[201][201];
	string s;
	

	while(scanf("%d %d", &n, &m) and n > 0){

		map<string, vector<int> > servers;
		
		//for(int i=0; i<201; i++)
		//	for(int j=0; j<201; j++)
		//		visitados[i][j] = false;

		memset(visitados, 0, sizeof(bool) * 40401);


		for(int i=0; i<n; i++){
			scanf("%d", &q);
			while(q--){
				scanf("%s", nome);
				s = nome;
				servers[s].push_back(i);
			}

		}


		//vector<ii> conect;
		int count = 0;
		for(int j=0; j<m; j++){
			
			scanf("%d", &q);

			while(q--){
				scanf("%s", nome);
				s = nome;

				vector<int> temp = servers[s];

				for(int i=0; i<(int) temp.size(); i++){
					//printf("%d %d\n", j, temp[i]);
					if(!visitados[j][temp[i]]){
						visitados[j][temp[i]] = true;
						count++;
						//conect.push_back(ii(j, temp[i]));
					}
				}

			}

		}

		//printVector(conect);
		//printSet(conexoes);
		//printf("\n");
		//printf("%d\n", (int) conexoes.size());
		printf("%d\n", count);


	}

 
	return 0;
}