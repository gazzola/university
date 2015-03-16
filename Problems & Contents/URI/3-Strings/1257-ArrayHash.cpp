#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;


int ctop(char c){
	return (int) c - 'A';
}


int main(){

	
	int n, l;
	char s[51];

	scanf("%d", &n);
	while(n--){

		scanf("%d\n", &l);
		
		int res = 0, tam;
		for(int i=0; i<l; i++){
			scanf("%s%n\n", s, &tam);
			for(int j=0; j<tam; j++)
				res += ctop(s[j]) + j + i;
		}


		printf("%d\n", res);

	}



	return 0;
}