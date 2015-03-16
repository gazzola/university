#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <stack>

using namespace std;


const int MAX_BYTES = 30000;
const int TAM = 100001;



int main(){

	int inicio[TAM], fim[TAM], mem[MAX_BYTES];
	char entrada[50], descricao[TAM];
	int n, t, pc, e;

	scanf("%d\n", &n);
	for(int c=1; c<=n; c++){

		scanf("\n%s\n", entrada);
		scanf("%s%n\n", descricao, &t);

		
		memset(mem, 0, sizeof(mem));
		pc = e = 0;


		stack<int> lp;
		for(int i=0; i<t; i++){
			inicio[i] = fim[i] = -1;

			if(descricao[i] == '['){
				lp.push(i);
			}
			else if(descricao[i] == ']'){
				inicio[lp.top()] = i;
				fim[i] = lp.top();
				lp.pop();
			}
		}

		
		printf("Instancia %d\n", c);
		for(int i=0; i<t; i++){
			switch(descricao[i]){
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
				case '.':
					printf("%c", mem[pc]);
					break;
				case ',':
					mem[pc] = (entrada[e] != '\0') ? entrada[e++] : 0;
					break;
				case '[':
					i = (mem[pc] == 0) ? inicio[i] : i;
					break;
				case ']':
					i = (mem[pc] != 0) ? fim[i] : i;
					break;
				case '#':
					for(int i=0; i<10; i++)
						printf("%c", mem[i]);
					break;
			}
		}


		printf("\n\n");

	}


	

	return 0;
}