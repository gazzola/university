#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){

	int n, m;
	bool ok;
	char idioma[50];
	char ultimo[50];
	
	scanf("%d", &n);

	while(n--){
		
		scanf("%d", &m);
		strcpy(ultimo, "");
		ok = true;
		
		while(m--){
			scanf("%s", idioma);
			if(strcmp(ultimo, idioma) != 0)
				if(strcmp(ultimo, "") != 0)
					ok = false;
			
			strcpy(ultimo, idioma);
		}

		if(!ok)
			printf("ingles\n");
		else
			printf("%s\n", ultimo);
	}

	return 0;
}