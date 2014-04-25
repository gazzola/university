#include <cstdio>
#include <cstring>


unsigned long int quadral(unsigned long int n){

	unsigned long int resto, i=1, quadral=0;

	while(n!=0){
		resto = n%4;
		n /= 4;
		quadral += resto*i;
		i *= 10;
	}

	return quadral;
}


char* alien(char quadral[50]){
	
	for(int i=0, tam=strlen(quadral); i<tam; i++){
		if(quadral[i] == '0')
			quadral[i] = 'A';
		else if(quadral[i] == '1')
			quadral[i] = 'B';
		else if(quadral[i] == '2')
			quadral[i] = 'C';
		else if(quadral[i] == '3')
			quadral[i] = 'D';
	}

	return quadral;
}



int main(){

	unsigned long int n;

	while(scanf("%lu ", &n) && n){
		char buffer[50];
		sprintf(buffer, "%lu", quadral(n*n));
		printf("%s\n", alien(buffer));
	}

	return 0;
}
