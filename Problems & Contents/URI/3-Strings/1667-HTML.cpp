#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;




int main(){

	
	char palavra[100];
	char br[] = "<br>";
	char hr[] = "<hr>";
	int ate = 0;
	int n;

	bool novalinha = false;
	scanf("%s%n ", palavra, &n);
	printf("%s", palavra);

	ate += n;

	while(scanf(" %s%n ", palavra, &n) != EOF){
		// printf("%d:%s\n", n, palavra);
		if(strcmp(palavra, br) == 0){
			printf("\n");
			ate = 0;
			novalinha = true;
		}
		else if(strcmp(palavra, hr) == 0){
			if(!novalinha)
				printf("\n");
			for(int i=0; i<80; i++)
				printf("-");
			printf("\n");
			ate = 0;
			novalinha = true;
		}
		else{

			if(ate + n+1 > 80){
				printf("\n");
				novalinha = true;
				ate = n;
			}
			else
				ate += n+1;

			if(!novalinha)
				printf(" ");
			printf("%s", palavra);
			novalinha = false;
		}

	}

	printf("\n");


	return 0;
}