#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <stack>

using namespace std;


const int MAX_BYTES = 30000;
const int TAM = 100001;


char entrada[50], desc[TAM];
int mem[MAX_BYTES];
int pc, e;



void doit(char op){
	switch(op){
		case '>':
			pc = (pc+1 == MAX_BYTES) ? 0 : pc+1;
			break;
		case '<':
			pc = (pc == 0) ? MAX_BYTES-1 : pc-1;
			break;
		case '+':
			mem[pc]++;
			 break;
		case '-':
			mem[pc]--;
			break;
		case ',':
			mem[pc] = (entrada[e] != '\0') ? entrada[e++] : 0;
			break;
		case '.':
			printf("%c", mem[pc]);
			break;
		case '#':
			for(int i=0; i<10; i++)
				printf("%c", mem[i]);
			break;
	}

}



int iter(int a, bool b){

	for(int i=a; desc[i] != '\0'; i++){
		if(desc[i] == ']')
			return (mem[pc] == 0) ? i : iter(a, b);
		else if(desc[i] == '[')
			i = iter(i+1, (mem[pc] != 0));
		else if(b)
			doit(desc[i]);
	}

	return 99999;
}




int main(){

	int n, t;
	scanf("%d\n", &n);

	for(int c=1; c<=n; c++){

		scanf("\n%s\n", entrada);
		scanf("%s%n\n", desc, &t);

		
		memset(mem, 0, sizeof(mem));
		pc = e = 0;
		
		printf("Instancia %d\n", c);
		iter(0, true);
		printf("\n\n");

	}


	

	return 0;
}