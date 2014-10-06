#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long unsigned int llu;

typedef pair<int, int> ii;
const int INF = 999999;
const int MAX = 1001;


struct lessAdj{
	bool operator()(const ii &lhs, const ii &rhs) const{
		return (lhs.second > rhs.second);
	}
};


void printVector(const vector<ii> &v){
	for(int i=0; i<(int) v.size(); i++)
		printf("(%d,%d)  ", v[i].first, v[i].second);
 	printf("\n");
}



int main(){
 
	int n;
	

	while(scanf("%d", &n) != EOF){
		
		int t, c;
	
		deque<int> tempos[MAX];
		priority_queue<ii, vector<ii>, lessAdj > aguardando;

		ii menor = ii(INF, INF);
		int pos = 0;

		for(int i=0; i<n; i++){
			scanf("%d %d", &t, &c);

			tempos[t].push_back(c);

			if(t < menor.first)
				menor = ii(t, c);
			else if(t == menor.first and c < menor.second){
				pos++;
				menor = ii(t, c);
			}
		}

		if(n == 1){

			if(tempos[0].size() > 0)
				printf("1\n");
			else
				printf("0\n");

			continue;
		}


		//tempos[menor.first].erase(tempos[menor.first].begin()+pos);
		for(int i=0; i<(int) tempos[menor.first].size(); i++){
            if(tempos[menor.first][i] == menor.second){
                tempos[menor.first].erase(tempos[menor.first].begin()+i);
                break;
            }
        }


		int executando = menor.second;

		llu soma = 0;
		int count = 1;
		int saiu = 0;

		int i = menor.first;
		llu last = menor.second+menor.first;

		while(count < n){

			if(saiu < n and i < MAX){
				if(tempos[i].size() > 0){
					while(!tempos[i].empty()){
						aguardando.push(ii(i, tempos[i].front()));
						tempos[i].pop_front();
						saiu++;
					}
				}

				if(executando <= 0){
					if(aguardando.size() > 0){
						ii novo = aguardando.top();
						aguardando.pop();
						//printf("%d %d\n", novo.first, novo.second);
						soma += (i-novo.first);
						last = i+novo.second;

						executando = novo.second;
						count++;
					}
				}
			}
			else{

				llu j = last;

				while(aguardando.size() > 0){
					ii novo = aguardando.top();
					aguardando.pop();

					//printf("x:%llu - %llu | %d %d\n", soma, j, novo.first, novo.second);
					soma += (j-novo.first);

					j += novo.second;
					

					executando = novo.second;
					count++;
				}
			}		
	
			i++;
			executando--;
		}
		

		printf("%llu\n", soma);	
	
	}
 
	return 0;
}