#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;



int main(){

	int t, n;
	char nomes[101][255];
	char s[255];
	int presencas[101];

	scanf("%d\n", &t);
	while(t--){
		
		memset(presencas, 0, sizeof(presencas));

		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%s ", nomes[i]);

		bool first = true;
		for(int i=0; i<n; i++){

			int c = 0, tam;
			scanf("%s%n ", s, &tam);

			for(int j=0; j<tam; j++){
				if(s[j] == 'P')
					presencas[i]++;

				if(s[j] != 'M')
					c++;
			}

			if(100*presencas[i] < 75*c){
				if(!first)
					printf(" ");

				printf("%s", nomes[i]);
				first = false;
			}

		}

		printf("\n");

		
	}


	return 0;
}