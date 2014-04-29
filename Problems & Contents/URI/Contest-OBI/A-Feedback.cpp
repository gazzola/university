#include <cstdio>

int main(){
	
	const char *nomes[4] = {"Rolien", "Naej", "Elehcim", "Odranoel"};
	int n, k, x;

	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &k);
		for(int j=0; j<k; ++j){
			scanf("%d", &x);
			printf("%s\n", nomes[--x]);
		}
	}


	return 0;
}
