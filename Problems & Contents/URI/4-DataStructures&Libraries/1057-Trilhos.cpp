#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;





int main(){
 
	int n;
	int entrada[1005];

	while(scanf("%d", &n), n){

		while(true){

			stack<int> estacao;
			int x;

			bool ok = true;
			int k = n;
			for(int i=0; i<n; i++){
				scanf("%d", &x);
				if(x == 0){
					ok = false;
					break;
				}
				entrada[i] = x;
			}

			for(int i=n-1; i>=0; i--){
				estacao.push(entrada[i]);
				while(estacao.top() == k){
					estacao.pop();
					k--;
					if(estacao.empty())
						break;
				}
			}

			if(!ok){
				printf("\n");
				break;
			}


			if(k == 0)
				printf("Yes\n");
			else
				printf("No\n");
		}

	}

 
	return 0;
}