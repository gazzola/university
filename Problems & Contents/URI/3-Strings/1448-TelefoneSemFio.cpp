#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int ctoi(char c){
	return (int) c - 'A';
}


int main(){

	int t;
	char asd;

	scanf("%d\n", &t);

	for(int c=1; c<=t; c++){

		char frase[110];
		char time1[110];
		char time2[110];

		// scanf("%[^\n]\n", frase);
		// scanf("%[^\n]\n", time1);
		// scanf("%[^\n]\n", time2);

		gets(frase);
		gets(time1);
		gets(time2);

		int a=0, b=0;
		int quem=0;

		for(int i=0; frase[i]!='\0'; i++){
			if(frase[i] == time1[i])
				a++;

			if(frase[i] == time2[i])
				b++;

			if(quem == 0){
				if(frase[i] == time1[i] and frase[i] != time2[i])
					quem = 1;
				else if(frase[i] != time1[i] and frase[i] == time2[i])
					quem = 2;
			}
		}


		printf("Instancia %d\n", c);

		if(a > b)
			printf("time 1\n");
		else if(a < b)
			printf("time 2\n");
		else{
			if(quem > 0)
				printf("time %d\n", quem);
			else
				printf("empate\n");
		}

		printf("\n");
	}
	


	return 0;
}