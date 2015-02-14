#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

void invertString(char *s, int n){
	
	char c;
	for(int i=0, j=n-1; i<(n/2); i++, j--){
		c = s[i]; 
		s[i] = s[j];
		s[j] = c;
	}
	s[n] = '\0';
}


int main(){
	
	char conta[100];
	int tam, a, b, c;

	while(scanf("%s%n\n", conta, &tam) != EOF){
		invertString(conta, tam);
		sscanf(conta, "%d=%d+%d", &c, &b, &a);
		if(a+b == c)
			printf("True\n");
		else
			printf("False\n");
	}

	
	return 0;
}