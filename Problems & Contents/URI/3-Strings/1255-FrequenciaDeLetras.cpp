#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int ctod(char c){
	return (int) c - 'a';
}


char dtoc(int d){
	return (char) d + 'a';
}


int main(){

	int n;
	char s[220];
	int letras[27];

	scanf("%d\n", &n);
	while(n--){

		int tam;
		int m = 0;

		memset(letras, 0, sizeof(letras));

		scanf("%[^\n]%n\n", s, &tam);
		for(int i=0; i<tam; i++){

			char c = tolower(s[i]);
			if(c >= 'a' and c <= 'z'){
				int j = ctod(c);
				letras[j]++;
				m = max(m, letras[j]);
			}
		}

		for(int i=0; i<27; i++)
			if(letras[i] == m)
				printf("%c", dtoc(i));

		printf("\n");

	}


	return 0;
}