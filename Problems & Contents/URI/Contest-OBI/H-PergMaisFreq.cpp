#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	
	int n, k, x, perguntas[10001];
	while(true){

		scanf("%d %d", &n, &k);
		if(n==0 && k==0)
			break;

		memset(perguntas, 0, sizeof(perguntas));
		int total = 0;

		while(n--){
			scanf("%d", &x);
			perguntas[x]++;
			if(perguntas[x] == k)
				total++;
		}

		printf("%d\n", total);

	}


	return 0;
}
