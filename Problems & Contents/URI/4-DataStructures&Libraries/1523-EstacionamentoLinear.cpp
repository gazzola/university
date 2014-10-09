#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;


typedef pair<int, int> ii;


int main(){
 
	int n, k;
	int c, s;


	while(scanf("%d %d", &n, &k) and n > 0){
		
		int chegada[100001];
		int saida[100001];

		memset(chegada, 0, sizeof(chegada));
		memset(saida, 0, sizeof(saida));

		int maior = 0;
		for(int i=1; i<=n; i++){
			scanf("%d %d", &c, &s);
			chegada[c] = i;
			saida[s] = i;

			if(s > maior)
				maior = s;
		}



		stack<int> estac;
		bool ok = true;

		for(int i=1; i<=maior; i++){

			if(saida[i] > 0){
				if(!estac.empty() and estac.top() == saida[i])
					estac.pop();
				else{
					ok = false;
					break;
				}
			}

			if(chegada[i] > 0){
				if((int) estac.size() < k)
					estac.push(chegada[i]);
				else{
					ok = false;
					break;
				}
			}
		}

		if(ok)
			printf("Sim\n");
		else
			printf("Nao\n");

	}


 
	return 0;
}