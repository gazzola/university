#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;


bool ehTautograma(char *frase, char c){
	
	for(int i=1; frase[i]!='\0'; i++){
		if(frase[i-1] == ' ')
			if(toupper(frase[i]) != toupper(c))
				return false;
	}

	return true;
}

int main(){
	

	char frase[1002], c;
	while(true){

		scanf("%[^\n]", frase);
		scanf("%c", &c);

		c = frase[0];
		if(c == '*')
			break;

		if(ehTautograma(frase, c))
			printf("Y\n");
		else
			printf("N\n");

	}
	

	return 0;
}