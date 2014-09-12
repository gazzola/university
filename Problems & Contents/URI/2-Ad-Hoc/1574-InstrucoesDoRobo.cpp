#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){
	
	int n, m, x, total;
	int instrucoes[105];
	char ins[10];
	scanf("%d", &n);

	while(n--){

		total = 0;
		scanf("%d", &m);

		for(int i=1; i<=m; i++){
			scanf("%s", ins);

			if(strcmp(ins, "LEFT") == 0){
				total -= 1;
				instrucoes[i] = -1;
			}
			else if(strcmp(ins, "RIGHT") == 0){
				total += 1;
				instrucoes[i] = 1;
			}
			else{
				scanf("%s %d", ins, &x);
				instrucoes[i] = instrucoes[x]; 
				total += instrucoes[x]; 
			}
		}

		printf("%d\n", total);

	}


	return 0;
}