#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

int getPos(char c){
	return (int) c - (int) 'a' + 1;
}


int main(){
	
	
	int n;
	int de = (int) 'a';
	int ate = (int) 'z';
	int tam = ate-de+1;

	char palavra1[10002];
	char palavra2[10002];

	scanf("%d", &n);
	while(n--){

		scanf("%s %s", palavra1, palavra2);

		int total = 0;
		for(int i=0; palavra1[i]!='\0'; i++){

			int x1 = getPos(palavra1[i]);
			int x2 = getPos(palavra2[i]);
			total += (x1 > x2) ? (tam+x2-x1) : x2-x1;

		}

		printf("%d\n", total);

	}



	return 0;
}