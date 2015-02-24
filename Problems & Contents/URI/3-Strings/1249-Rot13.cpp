#include <cstdio>
#include <string>
#include <cstring>

using namespace std;


int getPos(char c){
	if(c <= 'Z')
		return c-'A';
	return c-'A'-('a'-'Z')+1;
}


int main(){


	char letras[70];
	int t = 'Z' - 'A' + 1;

	for(int i=0; i<t; i++){
		letras[i] = 'A' + (i + 13) % t;
		// printf("%c:%c\n", 'A'+i, letras[i]);
	}


	t = 'z'-'a' + 1;
	for(int i=0; i<t; i++){
		letras['Z' - 'A'+i+1] = 'a' + (i + 13) % t;
		// printf("%c:%c\n", 'a'+i, letras['Z' - 'A'+i]);
	}

	

	char c;
	while(scanf("%c", &c) != EOF){

		if((c >= 'A' and c<='Z') or (c >= 'a' and c<='z'))
			printf("%c", letras[getPos(c)]);
		else
			printf("%c", c);
	}



	return 0;
}