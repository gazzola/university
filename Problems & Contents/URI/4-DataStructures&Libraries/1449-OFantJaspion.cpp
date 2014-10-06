#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



int main(){
 
	int t;
	int m, n;

	char palavra[85], c;
	map<string, string>::iterator it;
	string a, b;

	scanf("%d", &t);
	while(t--){

		scanf("\n%d %d", &m, &n);
		map<string, string> dicionario;
		
		while(m--){

			
			scanf("%s\n", palavra);
			//printf("%s\n", palavra);
			a = palavra;
			
			scanf("%[^\n]\n", palavra);
			//printf("%s\n", palavra);
			b = palavra;

			dicionario[a] = b;
		}


		for(int i=0; i<n; i++){
			while(scanf(" %s%c", palavra, &c) != EOF){

				a = palavra;

				it = dicionario.find(a);
				if(it == dicionario.end())
					printf("%s", palavra);
				else
					printf("%s", it->second.c_str());

				if(c == '\n')
					break;
				
				printf(" ");
			}

			printf("\n");

		}

		printf("\n");


	}
 
	return 0;
}