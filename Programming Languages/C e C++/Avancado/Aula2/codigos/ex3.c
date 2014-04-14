#include <stdio.h>

int mystrlen(char *c){
	int count=0;

	while(c[count] != '\0')
		count++;

	return count;
}

int main(){
	
	int (*p)(const char *);
	p = mystrlen;
	int tam = p("LOL");
	printf("len(LOL): %d\n", tam);

	return 0;
}